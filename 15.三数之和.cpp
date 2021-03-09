/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
//回溯不行得双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        vector<vector<int>> res;
        vector<int> tmp_res;
         if (nums.size()<3){
            return res;
        }
        sort(nums.begin(),nums.end()); // 排序防重复
        dfs(0,nums,tmp_res,res,0);
        // set<vector<int>> s(res.begin(),res.end());
        // res.assign(s.begin(),s.end());
        return res;
        }
    
    void dfs(int cur,vector<int>& nums,vector<int> &tmp_res,vector<vector<int>> &res,int target){
        int n = nums.size();
        if(tmp_res.size()>=3){
            if(target == 0){
                res.push_back(tmp_res);
            }
            return; //深度到3说明已经到底直接返回
        }
        if(cur>=n){
            return;
        }
        for(int i=cur;i<n;i++){
            //选取元素
            tmp_res.push_back(nums[i]);
            //递归
            dfs(i+1,nums,tmp_res,res,target-nums[i]);
            //回溯
            tmp_res.pop_back();
            //去重
            while(i<n-1&&nums[i+1]==nums[i]){
                i++;
            }
        }
        
    }
};
// @lc code=end

