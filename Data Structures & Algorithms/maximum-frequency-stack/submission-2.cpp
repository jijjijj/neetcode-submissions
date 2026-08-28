class FreqStack {
public:
    FreqStack() {}
    
    void push(int val) {
        const int nval = ++freq[val];
        
        if (freq[val] > max) {
            max = freq[val];
            data.push_back({});
        }

        data[nval].emplace_back(val);
    }
    
    int pop() {
        const int val = data[max].back();
        data[max].pop_back();
        --freq[val];
        if (data[max].empty()) {
            --max;
        }
        // std::cout << max << std::endl;
        return val;
    }

private:
    std::unordered_map<int, int> freq;
    std::vector<std::vector<int>> data = {{}};
    int max = 0;
};