class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        const int new_freq = ++freq[val];

        if (last_of_freq.contains(new_freq)) {
            last_of_freq[new_freq].first++;
            last_of_freq[new_freq].second =
                data.insert(++last_of_freq[new_freq].second, val);
        } else {
            last_of_freq[new_freq] = {1, data.insert(data.end(), val) };
        }
    }
    
    int pop() {
        const int val = data.back();
        data.pop_back();
        last_of_freq[freq[val]].second = std::prev(data.end());
        if (!--last_of_freq[freq[val]].first) {
            last_of_freq.erase(freq[val]);
        }
        freq[val]--;
        return val;
    }

private:
    // std::stack<int> s;
    // std::stack<int> mf;
    std::list<int> data;
    std::unordered_map<int, int> freq;
    std::unordered_map<int,
        std::pair<int, std::list<int>::iterator>> last_of_freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */