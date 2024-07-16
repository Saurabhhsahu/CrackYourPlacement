class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i = 0;i < n-3;i++){
            if(i > 0 && nums[i] == nums[i-1])   continue;
            for(int j = i+1;j < n-2;j++){
                if(j > i+1 && nums[j] == nums[j-1])   continue;
                long long tar = (long long)target - (long long)nums[i] - (long long)nums[j];

                int p1 = j+1;
                int p2 = n-1;

                while(p1 < p2){
                    long long sum = (long long)nums[p1] + (long long)nums[p2];

                    if(sum == tar){
                        ans.push_back({nums[i],nums[j],nums[p1],nums[p2]});
                        p1++;
                        while(p1 < p2 && nums[p1] == nums[p1-1])    p1++;
                        p2--;
                    }
                    else if(sum < tar)  p1++;
                    else    p2--;
                }
            }
        }

        return ans;
    }
};