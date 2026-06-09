class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int small = 0;
        int big= numbers.size()-1;

        int sum = numbers[small]+numbers[big];
        while (sum != target) {
            if (sum>target) {
                big--;
            } else {
                // if (sum<target)
                small++;
            }
            sum = numbers[small]+numbers[big];
        }

        //  std::vector<int> vec;
        // vec.push_back(small+1);
        // vec.push_back(big+1);
        return {small+1, big+1};
    }
};
