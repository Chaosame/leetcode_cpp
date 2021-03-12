class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //从右上出发 大于往下 小于往左
        int r = matrix.size();
        if(r==0) return false;
        int c = matrix[0].size();
        if(c==0) return false;
        int i=0;
        int j=c-1;
        while(i<r&&j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) --j;
            else if(matrix[i][j]<target) ++i;
        }
        return false;
    }
};