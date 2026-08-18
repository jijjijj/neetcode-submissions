class MyCircularQueue {
public:
    MyCircularQueue(int k) : k{ k } {
        start.next = &end;
        start.prev = nullptr;

        end.prev = &start;
        end.next = nullptr;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        ++filled;
        
        // start <-/-> 0 <-/-> 1 <-/-> end

        Node* last = end.prev;
        end.prev = new Node{ .val = value };
        end.prev->next = &end;
        last->next = end.prev;
        end.prev->prev = last;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        --filled;
        
        Node* first = start.next;
        start.next = first->next;
        first->next->prev = &start;

        delete first;

        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : start.next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : end.prev->val;
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