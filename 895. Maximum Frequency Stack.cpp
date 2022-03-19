class FreqStack {
public:
    unordered_map<int, int> cnts;
    unordered_map<int, stack<int>> stacks;
    int  maxi = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        ++cnts[val];
        
        stacks[cnts[val]].push(val);
        
        if(cnts[val] > maxi) maxi = cnts[val];
    }
    
    int pop() {
        int top = stacks[maxi].top();
        cnts[top]--;
        stacks[maxi].pop();
        if(stacks[maxi].empty()) --maxi;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */