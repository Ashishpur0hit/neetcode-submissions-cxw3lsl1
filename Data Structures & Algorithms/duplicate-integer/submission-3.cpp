class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool>map;
        for(auto x : nums)
        {
            if(map.count(x)) return true;
            map[x]=true;
        }
        return false;
    }
};