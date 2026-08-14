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

        std::priority_queue<std::tuple<int, int>> q1; // -time, user id
        for (int followee : follows[userId]) {
            if (tweets[followee].empty()) continue;
            
            q1.push({ -tweets[followee].begin()->first, followee });

            if (q1.size() > 10) q1.pop();
        }

        using val_t = std::tuple<int, it_t, int>; // -time, it, user id
        const auto comp = [](const val_t& a, const val_t& b) {
            const auto [t1, _1, _2] = a;
            const auto [t2, _3, _4] = b;

            return t1 < t2;
        };

        std::priority_queue<val_t,
            std::vector<val_t>, decltype(comp)> q2(comp);

        while (!q1.empty()) {
            const auto [time, user_id] = q1.top();
            q1.pop();
            q2.push({ -time, tweets[user_id].begin(), user_id });
        }

        std::vector<int> res;

        while (res.size() < 10 && !q2.empty()) {
            auto [time, it, user_id] = q2.top();
            q2.pop();

            res.emplace_back(it->second);
            ++it;
            if (it != tweets[user_id].end()) {
                q2.push({ it->first, it, user_id });
            }
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
