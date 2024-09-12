class MinStack {
public:
    stack<int>ss;
    stack<int>s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        
        if(ss.empty() ||  ss.top()>=val) ss.push(val);
    }
    
    void pop() {
        if(!s.empty())  {
        if(ss.top()==s.top()) ss.pop();
        s.pop();
        }
        else return ;
    }
    
    int top() {
        if(!s.empty()) return s.top();
        else return -1;
    }
    
    int getMin() {
        if(!ss.empty()) return ss.top();
        return -1;
    }
};

