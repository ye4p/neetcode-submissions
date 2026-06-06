class KthLargest {
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for (int n : nums) {
            minHeap.push(n);
        }
        while (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size()>k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
