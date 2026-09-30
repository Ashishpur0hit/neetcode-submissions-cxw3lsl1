class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(auto x : nums)
        {
            if(map.count(x)) return true;
            map[x]++;
        }
        return false;
    }
};