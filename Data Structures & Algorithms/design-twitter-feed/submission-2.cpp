class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front(tweetId);
        if (tweets[userId].size() > 10) {
            tweets[userId].pop_back();
        }
        follows[userId].emplace(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        using it_t = std::list<int>::iterator;
        std::vector<std::pair<it_t, it_t>> lists;

        for (int followee : follows[userId]) {
            lists.emplace_back(
                tweets[followee].begin(),
                tweets[followee].end());
        }

        std::vector<int> res;
        for (int i = 0; i < 10; ++i) {
            const size_t size = res.size();
            for (auto [s, e] : lists) {
                if (s != e) res.emplace_back(*(s++));
            }
            if (res.size() != size) break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }

private:
    std::unordered_map<int,
        std::list<int>> tweets;
    std::unordered_map<int,
        std::unordered_set<int>> follows;
};
