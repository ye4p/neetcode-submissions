class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one=cost[cost.size()-1];
        int two=0;
        for (int i=cost.size()-2; i>-1; i--) {
            int curr= std::min(one,two)+ cost[i];
            two=one;
            one=curr;
        }
        return std::min(one, two);

    }
};
