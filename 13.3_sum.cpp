class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i = 0;i < n - 2;i++){
            cout<<"i : "<<i<<endl;
            int p1 = i;
            while(p1 != 0 && p1 < n-2 && nums[p1] == nums[p1-1]) p1++;
            i = p1;

            int p2 = p1+1;
            int p3 = n-1;

            while(p2 < p3){
                int sum = nums[p1] + nums[p2] + nums[p3];

                if(sum == 0){
                    ans.push_back({nums[p1],nums[p2],nums[p3]});
                    p2++;
                    p3--;
                    while(p2 < n && nums[p2] == nums[p2-1])   p2++;
                    while(p3 > 0 && nums[p3] == nums[p3+1]) p3--;
                } 
                else if(sum < 0)    p2++;
                else    p3--;
            }
        }

        return ans;
    }
};