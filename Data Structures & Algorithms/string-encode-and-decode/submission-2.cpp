class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res;
        for (std::string s : strs) {
            for (char c : s) {
                c+=1;
            }
            res+=s;
            res+="\n";
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string token;
        while (std::getline(ss, token, '\n')) {
            words.push_back(token);
        }
        for (std::string str : words) {
            for (char c : str) {
                c=char(c-'1');
            }
        }
        return words;
    }
};
