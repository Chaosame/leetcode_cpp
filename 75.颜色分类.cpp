/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
void partition(vector<int>& nums,int start,int end){
    if (start>=end){
        return;
    }
    int l = start;
    int r = end;//左闭右闭
    int target = nums[l];
    while(l<r){
        while(l<r&&nums[r]>=target){
            r--;
        }
        while(l<r&&nums[l]<=target){
            l++;
        }
        if (r > l) { //
            swap(nums[l], nums[r]);
        }
    }
    
    nums[start] = nums[l];
    nums[l] = target;
    partition(nums,start,l-1);
    partition(nums,l+1,end);
}

    void sortColors(vector<int>& nums) {
        partition(nums,0,nums.size()-1);
    }
};
// @lc code=end

