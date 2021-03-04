/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    // 这题需要考虑的问题就是究竟哪部分需要旋转 旋转对应的四个位置 划分需要不重不漏强烈建议看官方题解的图
    // 我们考察对应的四个位置的交换情况 发现只需要四分之一部位的元素和对应位置的元素
    // 进行交换 就可以完成矩阵的旋转
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==0){
            return;
        }
        int x = (n>>1)-1; // 最大行号
        int y = (n-1)>>1; // 最大列号
        for(int i = 0;i<=x;i++){
            for(int j=0;j<=y;j++){
                swap(matrix[i][j],matrix[j][n-i-1]);
                swap(matrix[i][j],matrix[n-i-1][n-j-1]);
                swap(matrix[i][j],matrix[n-j-1][i]);
            }
        }
    }
};
// @lc code=end

