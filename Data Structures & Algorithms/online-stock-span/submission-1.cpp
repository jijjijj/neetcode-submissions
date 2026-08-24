class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = 1;
        while (!s.empty() && s.top().first <= price) {
            i += s.top().second;
            s.pop();
        }

        s.push({ price, i });
        return i;
    }

private:
    std::stack<std::pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */