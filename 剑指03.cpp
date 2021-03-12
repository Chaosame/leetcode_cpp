class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int re = -1;
        int zero = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])]<0) re = abs(nums[i]);
            else if (nums[abs(nums[i])]>0) nums[abs(nums[i])] = -nums[abs(nums[i])]; //改成负的
            else zero = abs(nums[i]);
        }
        return re==-1?zero:re;
    }
};