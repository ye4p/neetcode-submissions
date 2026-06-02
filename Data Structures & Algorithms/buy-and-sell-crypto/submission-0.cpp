class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=0;  //index
        int high=0; // index
        int best=0; // actual price diff
        for (int i=0; i <prices.size(); i++) {
            if (prices[i]<prices[low]) low=i;
            // if (prices[i]>prices[high] && i>low) high=i;
            if ((prices[i]>prices[high] && i>low) || low>high) high=i;
            if (high>low && ((prices[high]-prices[low]) > best)) best = prices[high]-prices[low];
        }
        return best;
    }
};
