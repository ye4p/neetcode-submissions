class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);
        std::vector<int> postfix(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            prefix[i]=prefix[i-1]*nums[i-1];
        }

        for (int i=nums.size()-2; i>-1; i--) {
            postfix[i]=postfix[i+1]*nums[i+1];
        }

        std::vector<int> result;
        for (int i=0; i<nums.size(); i++) {
            result.push_back(prefix[i]*postfix[i]);
        }

        return result;
    }
};
