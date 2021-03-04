/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // 转置行变列 列变行
        int x = matrix.size(); // 行数
        int y = matrix[0].size(); // 列数
        vector<vector<int>> t_matrix(y,vector<int>(x));
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                t_matrix[j][i] = matrix[i][j];
            }
        }
        return t_matrix;
    }
};
// @lc code=end

