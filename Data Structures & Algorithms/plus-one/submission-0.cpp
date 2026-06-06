class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool next=true;
        int index=digits.size()-1;
        while (next && index>=0) {
            digits[index]++;
            digits[index]=digits[index] % 10;
            if (!digits[index]) {
                next=true;
            } else {
                next=false;
            }
            index--;
        }
        if (next) digits.insert(digits.begin(), 1);
        return digits;
    }
};
