class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> vec(n+1);

        for (int i=1; i<=n; i++) {
            vec[i]=vec[i>>1] + (i & 1);
        }
        return vec;
    }
};
