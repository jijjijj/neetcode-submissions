class MyCircularQueue {
public:
    MyCircularQueue(int k) : data(k) {
        front = 0;
        back = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        ++filled;
        
        back = (back + 1) % data.size();
        data[back] = value;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        --filled;
        
        front = (front + 1) % data.size();

        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : data[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : data[back];
    }
    
    bool isEmpty() {
        return !filled;
    }
    
    bool isFull() {
        return filled == data.size();
    }

private:
    std::vector<int> data;
    int front{};
    int back{};
    int filled{};
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */