class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i=0; i<nums.size(); i++) {
            auto it = seen.find(nums[i]);
            if (it != seen.end()) {
                return {it->second, i}; 
            }
            seen[target-nums[i]]=i;
        }
        return {};
    }
};
