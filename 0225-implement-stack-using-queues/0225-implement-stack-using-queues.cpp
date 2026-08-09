class MyStack {
    queue<int> main;
    queue<int> sec;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        if(main.empty())
            return -1;
        while(main.size()>1){
            sec.push(main.front());
            main.pop();
        }
        int x = main.front();
        main.pop();
        while(!sec.empty()){
            main.push(sec.front());
            sec.pop();
        }
        return x;   
    }
    
    int top() {
        if(main.empty())
            return -1;
        while(main.size()>1){
            sec.push(main.front());
            main.pop();
        }
        int x = main.front();
        sec.push(main.front());
        main.pop();
        while(!sec.empty()){
            main.push(sec.front());
            sec.pop();
        }
        return x; 
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */