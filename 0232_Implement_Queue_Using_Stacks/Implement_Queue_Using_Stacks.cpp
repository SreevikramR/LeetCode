class MyQueue {
private:
    std::vector<int> q;
public:
    MyQueue() {

    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        int num = q.at(0);
        q.erase(find(q.begin(), q.end(), num));
        return num;
    }
    
    int peek() {
        return q.at(0);
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
