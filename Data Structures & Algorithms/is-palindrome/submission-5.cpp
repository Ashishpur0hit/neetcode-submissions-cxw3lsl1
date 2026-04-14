class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(auto ch : s) if((ch>=65 and ch<=90) or (ch>=97 and ch<=122) or (ch>=48 and ch<=57)) ans+=tolower(ch);
        cout<<ans<<endl;
        int i=0,j=ans.length()-1;
        while(i<j)
        {
            if(ans[i]!=ans[j]) return false;
            i++,j--;
        }
        
        return true;
    }
};
