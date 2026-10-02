class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(auto x : s)
        {
            if((x>='a' && x<='z') || (x>='A' && x<='Z')) ans.push_back(tolower(x));
            else if(x>='0'  && x<='9') ans.push_back(x);
        }
        int n = ans.size();
        int left=0,right=n-1;
        while(left<right)
        {
            if(ans[left]!=ans[right]) return false;
            left++,right--;
        }
        
        return true;
    }
};
