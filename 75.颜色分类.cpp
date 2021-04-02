/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
void quicksort(vector<int>& nums,int l,int r){
    if(l>=r) return;//下标相等位置已经确定了不用排
    int i=l-1 , j=r+1, mid = nums[i+j>>1];
    while(i<j){
        do i++;while(nums[i]<mid);
        do j--;while(nums[j]>mid);
        if(i<j) swap(nums[i],nums[j]); // ij依然有效则进行交换
    }
    quicksort(nums,l,j);
    quicksort(nums,j+1,r);
}
void quick_sort(vector<int>& q, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
       do i ++;  while (q[i] < x);
       do j --;  while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
void qs(vector<int>&nums,int l,int r){
    if(l>=r) return;
    int i=l-1,j=r+1,m=nums[i+j>>1];
    // cout<<m<<"!!!"<<nums[n]<<endl;
    while(i<j){
        do i++;while(nums[i]<m); //不能用nums[m]的原因是序号的地方可能会变化
        do j--;while(nums[j]>m);
        if(i<j) swap(nums[i],nums[j]);
    }
    qs(nums,l,j);
    qs(nums,j+1,r);
}
    void sortColors(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
    }
};
// @lc code=end

