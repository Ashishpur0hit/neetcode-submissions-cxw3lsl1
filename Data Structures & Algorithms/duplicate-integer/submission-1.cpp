class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()==0) return false;
        unordered_map<int,int>map;
        for(auto x : nums)
        {
            if(map.count(x)) return true;
            map[x]++;
        }
        return false;
    }
};
