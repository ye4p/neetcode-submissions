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
                small++;
            }
            sum = numbers[small]+numbers[big];
        }

        return {small+1, big+1};
    }
};
