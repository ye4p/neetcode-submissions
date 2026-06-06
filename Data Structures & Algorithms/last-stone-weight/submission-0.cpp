class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxHeap;
        for (int n : stones) {
            maxHeap.push(n);
        }

        while (maxHeap.size()>1) {
            int n1 = maxHeap.top();
            maxHeap.pop();
            int n2 = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(std::abs(n1-n2));
        }
        
        return maxHeap.top();
    }
};
