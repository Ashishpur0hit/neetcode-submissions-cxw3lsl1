class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(auto x : nums) s.insert(x);
        return (s.size()==n)?false:true;
    }
};