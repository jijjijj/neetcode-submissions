class MyCircularQueue {
public:
    MyCircularQueue(int k) : k{ k } {
        Node* last = &start;

        for (int i = 0; i < k; ++i) {
            last->next = new Node{};
            last->next->prev = last;
            last = last->next;
        }

        last->next = start.next;
        end.next = last;
        last_filled.next = &start;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        ++filled;
        last_filled.next->next->val = value;
        last_filled.next = last_filled.next->next;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        --filled;
        last_filled.next = last_filled.next->prev;

        return true;
    }
    
    int Front() {
        return start.next->val;
    }
    
    int Rear() {
        return last_filled.next->val;
    }
    
    bool isEmpty() {
        return !filled;
    }
    
    bool isFull() {
        return filled == k;
    }

private:
    struct Node {
        Node* next{};
        Node* prev{};
        int val{};
    };

    Node start{};
    Node end{};
    Node last_filled{};
    int filled = 0;
    int k = 0;
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