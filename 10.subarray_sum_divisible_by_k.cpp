class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        mp[0] = 1;
        int sum = 0;
        int ans = 0;

        for(int i = 0;i < n;i++){
            sum += nums[i];
            int mod = sum%k;

            if(mod < 0){
                mod += k;
            }
            if(mp.find(mod) != mp.end())    ans += mp[mod];
            mp[mod]++;
        }

        return ans;
    }
};