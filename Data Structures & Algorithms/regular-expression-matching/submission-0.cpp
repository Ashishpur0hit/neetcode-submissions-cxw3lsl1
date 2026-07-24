class Solution {
public:
    int n1,n2;
    bool fun(string &s,string &t,int i,int j)
    {
        if(i==n1 && j==n2 || i==n1 && t[n2-1]=='*') return true;
        if(i==n1 || j==n2) return false;

        if(j!=n2-1 && t[j+1]=='*')
        {
            if(s[i]==t[j] || t[j]=='.')
            {
                return fun(s,t,i,j+2) || fun(s,t,i+1,j);
            }
            return fun(s,t,i,j+2);
        }
        
        
        if(s[i]==t[j] || t[j]=='.') 
        {
            return fun(s,t,i+1,j+1);
        }
        return false;
        
    }
    bool isMatch(string s, string p) {
        n1 = s.length(),n2=p.length();
        return fun(s,p,0,0);
    }
};
