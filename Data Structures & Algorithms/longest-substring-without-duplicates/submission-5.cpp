class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> seen;

        int biggest=0;
        int length=0;

        for (int i = 0; i < s.length(); i++) {
            auto it = seen.find(s[i]);
            length++;
            if (it == seen.end()) {
                biggest=std::max(biggest, length);
            } else {
                if ((i-length) <= it->second) {   // Is in current substring
                    length= i - it->second;
                } else {
                    biggest=std::max(biggest, length);
                }
            }
            seen[s[i]]=i;
        }

        return biggest;
    }
};
