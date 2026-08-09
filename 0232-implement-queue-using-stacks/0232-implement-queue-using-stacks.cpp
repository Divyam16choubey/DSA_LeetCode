class MyQueue {
    stack<int> rear;
    stack<int> front;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        rear.push(x);
    }
    
    int pop() {
        if(rear.empty())
            return -1;
        while(!rear.empty()){
            front.push(rear.top());
            rear.pop();
        }
        int val = front.top();
        front.pop();
        while(!front.empty()){
            rear.push(front.top());
            front.pop();
        }
        return val;
    }
    
    int peek() {
        if(rear.empty())
            return -1;
        while(!rear.empty()){
            front.push(rear.top());
            rear.pop();
        }
        int val = front.top();
        while(!front.empty()){
            rear.push(front.top());
            front.pop();
        }
        return val;  
    }
    
    bool empty() {
        return rear.empty();
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