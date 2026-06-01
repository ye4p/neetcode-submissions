class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i=0; i<nums.size(); i++) {
            int search = target-nums[i];
            if (seen.count(nums[i])) {
                return {seen[nums[i]], i}; 
            }
            seen[search]=i;
        }
        return {};
    }
};
