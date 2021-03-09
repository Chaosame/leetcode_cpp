/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp求出从左到右得最小 从右到左得最大
        //再遍历一遍求出 max(rl_max-lr_min)
        int n = prices.size();
        int min_price = 1e4+1;
        int max_profit = 0;
        for(int i=0;i<n;i++){
            min_price =min(min_price,prices[i]);
            max_profit =max(max_profit,prices[i]-min_price); //利润取决于当前位置之前得最低价
        }
        return max_profit;
    }
};
// @lc code=end

