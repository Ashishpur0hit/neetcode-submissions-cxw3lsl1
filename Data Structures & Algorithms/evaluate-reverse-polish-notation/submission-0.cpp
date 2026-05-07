class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int a,b;
        for(auto x : tokens)
        {
            if(x=="+")
            {
                 a = s.top(),s.pop();
                 b = s.top(),s.pop();
                s.push(b+a);
            }
            else if(x=="-")
            {
                 a = s.top(),s.pop();
                 b = s.top(),s.pop();
                s.push(b-a);
            }
            else if(x=="*")
            {
                 a = s.top(),s.pop();
                 b = s.top(),s.pop();
                s.push(b*a);
            }
            else if(x=="/")
            {
                 a = s.top(),s.pop();
                 b = s.top(),s.pop();
                s.push(b/a);
            }
            else
            {
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};
