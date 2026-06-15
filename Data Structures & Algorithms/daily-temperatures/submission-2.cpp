class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> s; // {temp, index}

        s.push({temperatures[0], 0});
        for (int i = 1; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                std::pair<int, int> p = s.top();
                s.pop();
                result[p.second]=i-p.second;
            }
            s.push({temperatures[i], i});


        }

        return result;
    }
};
