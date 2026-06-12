class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<std::string> s;
        for (int i =0; i < tokens.size(); i++) {
            // bool is_num= std::all_of(tokens[i].begin(), tokens[i].end(), [](unsigned char c) {
            //     return std::isdigit(c);
            // });
            bool is_num= true;
            for (char c : tokens[i]) {
                if (!std::isdigit(c)) {
                    is_num=false;
                    break;
                }
            }
            if (tokens[i].length()>1 && tokens[i][0]=='-') is_num=true;
            if (is_num) {
                s.push(tokens[i]);    
            } else {
                int n1 = std::stoi(s.top());
                s.pop();
                int n2 = std::stoi(s.top());
                s.pop();
                int res;
                if (tokens[i]=="+") {
                    res = n1+n2;
                } else if (tokens[i]=="*") {
                    res = n1*n2;
                }
                else if (tokens[i]=="-") {
                    res = n2-n1;
                } else {
                    res = n2/n1;
                }
                s.push(std::to_string(res));
            }
        }
        return std::stoi(s.top());
    }
};
