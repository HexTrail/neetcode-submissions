class Solution {
public:
//The idea is to maintain a stack of indices with increasing heights. When we encounter a bar that is shorter than the bar at the top of the stack, it means the taller bar has hit its right boundary (this is as long as we can stretch the area of that taller bar. So here we are taking the approach of stretching each bar as long as possible until a shorter one is encountered.). We can then pop it and calculate its maximum possible area
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;
        int maxA = 0, n = heights.size();
        for(int i=0;i<=n;i++){
            int currentHeight = (i==n)?0:heights[i];
            while(!s.empty() && currentHeight < heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : (i - s.top() - 1);
                int a = h *w;
                if(a>maxA) maxA = a;
            }
            s.push(i);
        }
        //in the end the last element is pushed to stack so it needs to be removed. For that run the loop one extra time and take the height at that step as 0. Now the last thing that remains pushed to stack is n, which is not a valid index.
        return maxA;
    }
};
