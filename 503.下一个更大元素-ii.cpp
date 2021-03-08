/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n,-1);
        stack<int> stk;       //单调栈里面存元素的下标
        for(int i=0;i<2*n-1;i++){
            while(!stk.empty() && nums[i%n]>nums[stk.top()]){
                ret[stk.top()] = nums[i%n]; //对应下标的后一个大值就是它
                stk.pop();
            }
            stk.push(i%n);
        }
        return ret;
    }
};
// @lc code=end

