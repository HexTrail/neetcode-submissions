class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int max = 0, minH=0, len = heights.size();
        for (int i = 0; i < len - 1; i++) {
            for (int j = len - 1; j > i; j--) {
                int h = min(heights[i], heights[j]);
                if (h > minH) {
                    int diff = h * (j - i);
                    if (diff > max) {
                        minH = h;
                        max = diff;
                    }
                }
            }
        }
        return max;
    }
};
