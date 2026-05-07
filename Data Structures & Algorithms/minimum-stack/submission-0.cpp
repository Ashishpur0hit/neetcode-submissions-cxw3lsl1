class MinStack {
public:

    stack<int>st;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    unordered_map<int,int>map;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        min_heap.push(val);
        map[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        map[val]--;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        while(map[min_heap.top()]<=0) min_heap.pop();
        return min_heap.top();
    }
};
