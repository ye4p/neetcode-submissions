class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int index = cost.size();
        std::vector<int> vec(cost.size()+1, 0);
        vec[index-1]=cost[index-1];
        for (int i=index-2; i>-1; i--) {
            int min=std::min(vec[i+1],vec[i+2]);
            vec[i]=min+cost[i];
        }
        return std::min(vec[0], vec[1]);

    }
};
