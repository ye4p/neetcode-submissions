class Solution {
public:
    bool isHappy(int n) {
        int newNum=0;
            std::unordered_set<int> s;
        while (newNum!=1) {
            newNum=0;
            while (n>0) {
                int num= (n%10) * (n%10);
                // if (num!=0 && s.count(num)) {
                //     return false;
                // } else {
                //     s.insert(num);
                // }
                newNum+= num;
                n/=10;
            }
            if (s.count(newNum)) {
                return false;
            } else {
                s.insert(newNum);
            }
            n=newNum;
        }
        return true;

    }
};
