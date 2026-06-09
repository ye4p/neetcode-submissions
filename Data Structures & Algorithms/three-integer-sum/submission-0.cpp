class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> res;
        for (int i=0; i<nums.size(); i++) {
            if (i>0 &&  nums[i]==nums[i-1]) continue;

            int small = i+1;
            int big = nums.size()-1;
            while (small<big) {
                int threeSum = nums[i] + nums[small] + nums[big];
                if (threeSum>0) {
                    big--;
                } else if (threeSum<0) {
                    small++;
                } else {
                    res.push_back({nums[i], nums[small], nums[big]});
                    small++;
                    while ((nums[small]==nums[small-1]) && small<big) {
                        small++;
                    }
                }
            }
        }
        
        return res;
    }
};
