class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> seen;
        std::priority_queue<std::pair<int, int>> q;
        for (int n : nums) {
            auto it = seen.find(n);
            if (it == seen.end()) {
                seen[n]=1;
            } else {
                it->second++;
            }
        }

        for (const auto& [first, second] : seen) {
            q.push(std::pair(second, first));
        }

        std::vector<int> res;
        for (int i=0; i<k; i++) {
            std::pair<int, int> p = q.top();
            q.pop();
            res.push_back(p.second);
        }

        return res;
    }
};
