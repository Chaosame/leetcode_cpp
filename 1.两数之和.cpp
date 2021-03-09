/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //哈希表法 把数组中所有得数存入一个哈希表 如果map[target-nums[i]]存在就返回即可
        int n = nums.size();
        unordered_map<int,int> s;
        for(int i=0;i<n;i++){
            auto it  = s.find(target-nums[i]);
            if (it!=s.end()){
                return {it->second,i};
            }
            s[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

