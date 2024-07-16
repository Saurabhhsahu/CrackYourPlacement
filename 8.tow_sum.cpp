class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        sort(nums.begin(),nums.end());
        int p1 = 0;
        int p2 = n-1;

        while(p1 < p2){
            int sum = nums[p1] + nums[p2];
            if(sum < target)    p1++;
            else if(sum > target)   p2--;
            else    break;
        }
        vector<int> ans;
        ans.push_back(mp[nums[p1]][0]);
        mp[nums[p1]].erase(mp[nums[p1]].begin());
        ans.push_back(mp[nums[p2]][0]);
        return ans;
    }
};