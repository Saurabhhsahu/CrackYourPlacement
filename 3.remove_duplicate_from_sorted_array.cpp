class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0;
        int p2 = 0;

        while(p2 < n){
            int val = nums[p2];
            while(p2 < n && nums[p2] == val)    p2++;
            nums[p1] = val;
            p1++;
        }

        return p1;
    }
};