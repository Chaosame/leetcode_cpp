/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //先用前k个数建一个最小堆 堆顶就是k个数种第k大的数
        //后面的每个数进来都与k比较小于k则进堆
        //最后的顶就是所求元素
        priority_queue<int,vector<int>,greater<int>> heap; // 小顶堆
        int n = nums.size();
        for(int i=0;i<k;i++){ // 大小为k的小堆的顶是第k大的数
            heap.push(nums[i]);
        }
        for(int j=k;j<n;j++){
            if(nums[j]>heap.top()){
                heap.pop();
                heap.push(nums[j]);
            }
        }
        return heap.top();
    }
};
// @lc code=end

