class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seen;
        int smallest = nums.size() ? nums[0] : 0;
        int biggest = nums.size() ? nums[0] : 0;
        for (int el : nums) {
            seen.insert(el);
            smallest=std::min(smallest, el);
            biggest=std::max(biggest, el);
        }

        int count = 0;
        int sequence = 0;
        int curr;
        int prev = smallest;
        for (int i=smallest; i<=biggest; i++) {
            if (seen.find(i) == seen.end()) {
                count = 0;
            } else {
                count++;
                sequence=std::max(sequence, count);
            }
        }   
        return sequence;
    }
};
