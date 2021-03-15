/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
            //二分
            int n = nums.size();
            int l =0;
            int r = n-1;
            // m大于r 说明左边有序 反之 右边有序
            // 在考虑查找 当左边有序时 检查数是不是落在范围里
            // 右边同理 
            // 否则去另一半区间查找
            while(l<r){
                // cout<<l<<r<<endl;
                int m = (l+r)>>1;
                if(nums[m]==target) return m;
                if (nums[m]>=nums[0]){
                    //左边有序 检查是不是在中间
                    if(nums[0]<=target&&target<nums[m]) {r=m-1;}
                    else {l=m+1;}
                }
                else{
                    if(nums[m]<target&&nums[n-1]>=target) {l=m+1;}
                    else {r = m-1;}
                }
                // cout<<l<<r<<endl;
            }
            return nums[l]==target?l:-1;
    }
};
// @lc code=end

