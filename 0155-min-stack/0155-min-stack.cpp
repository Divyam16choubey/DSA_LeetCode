class MinStack {
    stack<int> st;
    stack<int> minElement;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minElement.push(value);
        }
        else{
            st.push(value);
            minElement.push(min(minElement.top(), value));
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        st.pop();
        minElement.pop();
    }
    
    int top() {
        if(st.empty())
            return {};
        return st.top();
    }
    
    int getMin() {
        if(minElement.empty())
            return {};
        return minElement.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */