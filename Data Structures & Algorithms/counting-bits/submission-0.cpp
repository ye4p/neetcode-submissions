class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> vec;

        for (int i=0; i<=n; i++) {
            int count = 0;
            int copy_i=i;
            for (int j=0; j< 32; j++) {
                if (copy_i & 1) count++;
                copy_i=copy_i>>1;
            }
            vec.push_back(count);
        }
        return vec;
    }
};
