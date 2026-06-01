class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> seen;
        for (int i=0; i<s.length(); i++) {
            auto it = seen.find(s[i]);
            if (it==seen.end()) {
                seen[s[i]]=1;
            } else {
                it->second+=1;
            }
        }
        for (int i=0; i<t.length(); i++) {
            auto it = seen.find(t[i]);
            if (it==seen.end()) {
                return false;
            } else {
                it->second-=1;
            }
        }
        for (const auto&[key, value] : seen) {
            if (value!=0) {
                return false;
            }
        }
        return true;
    }
};
