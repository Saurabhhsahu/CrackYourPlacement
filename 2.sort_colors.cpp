class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3,0);
        for(int i = 0;i < nums.size();i++){
            cnt[nums[i]]++;
        }

        int p = 0;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < cnt[i];j++){
                nums[p++] = i;
            }
        }
    }
};