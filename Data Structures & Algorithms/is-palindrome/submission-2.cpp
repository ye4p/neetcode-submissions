class Solution {
public:
    bool isPalindrome(string s) {
        int ptr1=0;
        int ptr2=s.length()-1;
        while (ptr2>ptr1) {
            // if (!std::isalnum(s[ptr1])) ptr1++;
            // if (!std::isalnum(s[ptr2])) ptr2--;
            while (!std::isalnum(s[ptr1]) && ptr2>ptr1) {ptr1++;}
            while (!std::isalnum(s[ptr2]) && ptr2>ptr1) {ptr2--;}

            // ".,"

            if (std::tolower(s[ptr1])!=std::tolower(s[ptr2])) return false;
            ptr1++;
            ptr2--;
        }
        return true;
    }
};
