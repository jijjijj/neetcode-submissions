class MyCircularQueue {
public:
    struct Node {
        Node* next{};
        int val{};
    };

    MyCircularQueue(int k) : cap(k) {
        back = front;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        ++filled;

        front->next = new Node{.val = value};
        front = front->next;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        --filled;
        
        Node* tmp = back->next;
        back->next = back->next->next;
        delete tmp;
        if (!back->next) front = back;

        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : back->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : front->val;
    }
    
    bool isEmpty() {
        return !back->next;
    }
    
    bool isFull() {
        return filled == cap;
    }

private:
    Node root{};
    Node* front = &root;
    Node* back{};
    int filled{};
    int cap{};
};
