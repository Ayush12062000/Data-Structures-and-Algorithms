class MinStack {
public:
    stack<long long int> st;
    long long int minEle;
    MinStack() {
        minEle=-1;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minEle=val;
            return;
        }
        if(val>=minEle){
            st.push(val);
            return;
        }else{
            long long int temp=val-minEle+val;
            
            st.push(temp);
            minEle=val;
        }
        return;
    }
    
    void pop() {
        if(st.top()<minEle){
            minEle=2*minEle-st.top();
        }
        st.pop();
        return;
    }
    
    int top() {
        if(st.top()<minEle)
            return minEle;
        return st.top();
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */