class Solution {
public:
    vector<string>res;
    void fun(string &str,int n,int open,int close)
    {
        if(close>open) return ;
        if(open==n && close==n)
        {
            cout<<str<<endl;
            res.push_back(str);
            return;
        }

        if(open<n)
        {
            str.push_back('(');
            fun(str,n,open+1,close);
            str.pop_back();
        }

        if(close<n)
        {
            str.push_back(')');
            fun(str,n,open,close+1);
            str.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string str="";
        res=vector<string>(0);
        fun(str,n,0,0);
        return res;
    }
};
