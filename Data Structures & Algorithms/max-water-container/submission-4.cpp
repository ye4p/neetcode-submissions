class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area=0;
        int small=0;
        int big = heights.size()-1;
        while (small<big) {
            area=std::max(area, std::min(heights[small], heights[big])*(big-small));
            if (heights[small]<heights[big]) {
                small++;
            } else {
                big--;
            }
        }
        return area;
    }
};
