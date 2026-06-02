class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=0;
        int high=0;
        int best=0;
        for (int i=1; i <prices.size(); i++) {
            if (prices[i]<prices[low]) low=i;
            if ((prices[i]>prices[high] && i>low) || low>high) high=i;
            if (high>low && ((prices[high]-prices[low]) > best)) best = prices[high]-prices[low];
        }
        return best;
    }
};
