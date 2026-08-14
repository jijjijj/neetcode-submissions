class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front({ time++, tweetId });
        if (tweets[userId].size() > 10) {
            tweets[userId].pop_back();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        follows[userId].emplace(userId);

        using it_t = std::list<std::pair<int, int>>::iterator;
        std::vector<std::pair<it_t, it_t>> lists;

        for (int followee : follows[userId]) {
            lists.emplace_back(
                tweets[followee].begin(),
                tweets[followee].end());
        }

        std::vector<int> res;
        for (int i = 0; i < 10; ++i) {
            int best = -1;
            for (int j = 0; j < lists.size(); ++j) {
                auto [s, e] = lists[j];
                if (s != e && (best == -1 ||
                    s->first > lists[best].first->first)) {
                    best = j;
                }
            }
            if (best == -1) break;
            res.emplace_back(lists[best].first->second);
            lists[best].first++;
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
    int time = 0;
    std::unordered_map<int,
        std::list<std::pair<int, int>>> tweets;
    std::unordered_map<int,
        std::unordered_set<int>> follows;
};
