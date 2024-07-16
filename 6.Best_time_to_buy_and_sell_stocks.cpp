class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_val = prices[n-1];
        int ans = 0;

        for(int i = n-2;i >= 0;i--){
            ans = max(ans,max_val - prices[i]);
            max_val = max(max_val,prices[i]);
        }

        return ans;
    }
};