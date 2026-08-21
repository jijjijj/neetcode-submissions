class FreqStack {
public:
    FreqStack() {}
    
    void push(int val) {
        data[++freq[val]].emplace_back(val);
        if (freq[val] > max) {
            max = freq[val];
        }
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
    std::unordered_map<int, std::vector<int>> data;
    int max = 0;
};