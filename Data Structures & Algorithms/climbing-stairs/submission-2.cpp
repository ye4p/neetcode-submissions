class Solution {
public:
    int climbStairs(int n) {
        // if (n <= 1) {
        //     return 1;
        // }
        // return climbStairs(n-2) + climbStairs(n-1);

        int n1=0;
        int n2=1;
        int sum=0;
        for (int i=0; i<n; i++) {
            sum=n2+n1;
            n1=n2;
            n2=sum;
        }
        return sum;
    }
};
