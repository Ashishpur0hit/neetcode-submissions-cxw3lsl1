class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<int>st;
        for(auto x : s)
        {
            if(st.empty() && (x==']' || x=='}' || x==')')) return false;
            else if(x=='(' || x=='{' || x=='[') st.push(x);
            else 
            {
                if((x==')' && st.top()!='(') || (x==']' && st.top()!='[') || (x=='}' && st.top()!='{')) return false;
                else st.pop();
            }
            
        }
        return (st.empty())?true:false;
    }
};
