class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> pairs= {
                {'[', ']'},
                {'{', '}'},
                {'(', ')'}
        };
        std::vector<char> vec;
        for (char c : s) {
            auto it = pairs.find(c);
            if (it != pairs.end()) {
                vec.push_back(c);
            } else {
                if (vec.size()<1 || (pairs.find(vec[vec.size()-1])->second != c)) {
                    return false;
                }
                vec.pop_back();
            }
        }
        return vec.size() == 0;
    }
};
