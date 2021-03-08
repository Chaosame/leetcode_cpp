/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // dp
        // 1. D dp[i]为包含下标为i的最长无重复子串
        // 2. T 如果 s[i] 不在含s[i-1]的子串中 dp[i] = dp[i-1]+1 
        // 如果在 求出 s[i]距离上一个与s[i]相同的字符的位置为d
        // 如果d<dp[i-1]  dp[i]=d 如果d>dp[i-1]就是上面的 dp[i] = dp[i-1]+1 
        // 求距离需要花费时间 由于字母个数是有限的 可以用一个map储存 s[i]上一次出现的位置
        // dp[0] =1 
        int n  = s.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        map<char,int> char_map;
        vector<int>dp(n,1);
        char_map[s[0]] = 0;
        int max_len = -1;
        for(int i=1;i<n;i++){
            int dis = char_map.count(s[i])==0?i+1: i-char_map[s[i]]; // 如果没存在则需要把开头的也算上需要加1
            if(dis<=dp[i-1]){
                dp[i]=dis;
            }
            else{
                dp[i]=dp[i-1]+1;
            }
            max_len = max(max_len,dp[i]);
            char_map[s[i]]=i; // 更新一下出现的位置
        }
        return max_len;
    } //此题 dp[i] 依赖于 dp[i-1] 可以状态压缩
};
// @lc code=end

