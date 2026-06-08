class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> zeros;
        int final=1;
        for (int i=0; i<nums.size(); i++) {
            if (!nums[i]) {
                zeros.push_back(i);
                continue;
            }
            final*=nums[i];
        }
        std::vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (zeros.size() > 1) {
                res.push_back(0);
            } else if (std::ranges::contains(zeros, i)) {
                res.push_back(final);
            } else if (zeros.size()>0) {
                res.push_back(0);
            } else {
                res.push_back(final/nums[i]);
            }
        }
        return res;
    }
};
