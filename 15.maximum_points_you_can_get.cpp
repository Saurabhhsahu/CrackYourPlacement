class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> prefix(n);
        int total = card[0];
        prefix[0] = card[0];

        for(int i = 1;i < n;i++){
            prefix[i] = card[i] + prefix[i-1];
            total += card[i];
        }

        if(n == k)  return total;

        int len = n-k;
        int ans = INT_MIN;
        for(int i = 0;i+len <= n;i++){
            int pre = (i == 0) ? (0) : prefix[i-1];
            int post = total - prefix[i+len-1];

            ans = max(ans,pre + post);
        }

        return (ans == INT_MIN) ? (total) : (ans);
    }
};