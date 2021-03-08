/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
//单调栈
// class Solution {
// public:
//     int trap(vector<int>& height) { 
//     //单调栈 栈中存放序号 遇到一个小于栈顶的直接累加 否则一直pop到栈顶大于等于或者栈为空 
//     //记录下 pop出来的值 最后能接的雨水 就是 (j-i-1)*(min(nums[i],nums[j])中的最大-当前高度)
//     //最后把当前遍历到的元素入栈
//     int n = height.size();
//     int ans = 0;
//     stack<int> stk;
//     for(int i=0;i<n;i++){
//         while(!stk.empty() && height[stk.top()]<height[i]){
//         // 出栈 计算距离 填充 更新ans 最后新的入栈
//             int top = stk.top(); // 先弹出目前的需要弹出的栈顶
//             stk.pop();
//             if (stk.empty()){ // 弹出完发现栈中没有元素了立即结束
//                 break;
//             }
//             int dis = i-stk.top()-1; //计算top和当前元素的距离
//             int full_h = min(height[i],height[stk.top()])-height[top];//填充高度
//             ans += dis*full_h;
//         }
//         stk.push(i);
//     }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int trap(vector<int>& height) { 
//         //dp 通过暴力法可以发现 一个块能储的水是max(它左的最大,右的最大)-块高度。
//         //我们可以用dp预处理求出所有位置的左右最高 从而一次遍历中完成对水的求解。
//         //为什么这种解法用的空间小 也许跟stack的底层是deque而这种使用的是vector有关。
//         if(height.size()==0){
//             return 0;
//         }
//         int n = height.size();
//         vector<int> left_max(n),right_max(n);
//         left_max[0] = height[0];
//         right_max[n-1] = height[n-1];
//         int ans = 0;
//         for(int i=1;i<n;i++){
//             left_max[i] = max(left_max[i-1],height[i]);
//         }
//         for(int k=n-2;k>=0;k--){
//             right_max[k] = max(right_max[k+1],height[k]);
//         }
//         for(int j = 0;j<n;j++ ){
//             ans+= min(left_max[j],right_max[j]) - height[j];
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int trap(vector<int>& height) { 
        //双指针写法
        //1这道题一个位置的蓄水量显然和两边都有关系
        //2蓄水量取决于左边的最大值和右边的最大值中的较小值
        //3我们可以用两个指针一个从左一个从右进行计算
        //4对于左针如果右边的最大值已经大于它,根据2我们就可以确定这块的蓄水量
        //5对于4的反面,我们无法确定左针但是我们此时右针的最大是小于左针最大 我们可以确定右针的蓄水量
        //6由此得到双指针写法

        //这种写法时间O(n) 空间O(1) 应是本题最优解
        int n = height.size();
        if(n==0){
            return 0;
        }
        int l = 0;
        int r = n-1;
        int ans = 0;
        int l_max = height[l];
        int r_max = height[r];
        while(l<r){ // 两指针相遇停止
            l_max= max(l_max,height[l]);
            r_max =max(r_max,height[r]);
            if (l_max<r_max){
               ans+=l_max-height[l];
               l++;
            }
            else{
               ans+=r_max-height[r];
               r--;
            }
        }
        return ans;
    }
};
// @lc code=end

