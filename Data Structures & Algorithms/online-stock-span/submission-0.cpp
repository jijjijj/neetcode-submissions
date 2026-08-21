class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = time;
        while (!s.empty() && s.top().first <= price) {
            i = s.top().second;
            s.pop();
        }

        s.push({ price, i });
        time++;
        return time - i;
    }

private:
    int time = 0;
    std::stack<std::pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */