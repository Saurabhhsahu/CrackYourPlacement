class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int p1 = 0;
        int p2 = n-1;
        int ans = INT_MIN;

        while(p1 < p2){
            int val = (p2-p1) * min(heights[p1],heights[p2]);
            ans = max(ans,val);

            if(heights[p1] < heights[p2])   p1++;
            else    p2--;
        }

        return ans;
    }
};