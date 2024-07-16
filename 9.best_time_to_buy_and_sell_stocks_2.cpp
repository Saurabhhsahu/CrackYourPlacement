class Solution {
public:
    int solve(vector<int>& prices,int idx,int buy,vector<vector<int>>&dp){
        int n = prices.size();

        if(dp[idx][buy] != -1)  return dp[idx][buy];

        int ans;
        if(buy == 1){
            if(idx == n-1)  return 0;
            //buy and go
            int val1 = -prices[idx] + solve(prices,idx+1,0,dp);

            //skip  and dont buy
            int val2 = solve(prices,idx+1,1,dp);

            ans = max(val1,val2);
        }
        else{
            if(idx == n-1)  return prices[idx] - buy;
            //sell and go
            int val1 = prices[idx] + solve(prices,idx+1,1,dp);

            //skip and dont sell
            int val2 = solve(prices,idx+1,0,dp);

            ans = max(val1,val2);
        }

        return dp[idx][buy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};