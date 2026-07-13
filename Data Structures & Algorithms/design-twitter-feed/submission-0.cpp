class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        _tweets[userId].emplace_back(
            std::pair{ ++_counter, tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        _follows[userId].emplace(userId);
        
        std::priority_queue<std::tuple<int, int, int>> q; // time, user, index
        std::vector<int> result;

        for (const int followee : _follows[userId]) {
            if (const auto& vec = _tweets[followee]; !vec.empty()) {
                q.push(std::tuple{ vec.back().first, followee,
                    static_cast<int>(vec.size() - 1) });
            }
        }

        while (result.size() < 10 && !q.empty()) {
            auto [_, followee, index] = q.top();
            q.pop();

            const auto& vec = _tweets[followee];

            result.emplace_back(vec[index].second);

            if (index) {
                q.push(std::tuple{ vec[index - 1].first, followee,
                    index - 1 });
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        _follows[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        _follows[followerId].erase(followeeId);
    }

private:
    std::unordered_map<int,
        std::unordered_set<int>> _follows;
    std::unordered_map<int,
        std::vector<std::pair<int, int>>> _tweets; // counter, tweet_id
    int _counter = 0;
};
