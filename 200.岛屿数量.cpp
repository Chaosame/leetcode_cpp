/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    queue<char> quee;

    void bfs(int& ans,int i,int j,int dx[],int dy[],vector<vector<char>> grid,vector<vector<int>> &visited){
        // cout<<i<<j<<endl;
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> quee;
        quee.push(pair<int,int>(i,j)); //把1放入
        while(!quee.empty()){
            pair dot = quee.front();
            quee.pop();

            visited[dot.first][dot.second] = 1;//标注已访问
            for (int i=0;i<4;i++){
                int new_x = dot.first+dx[i];
                int new_y = dot.second+dy[i];
                if (new_x>r-1||new_y>c-1||new_x<0||new_y<0) continue;
                if (visited[new_x][new_y] ==1) continue;
                if (grid[new_x][new_y] != '0') {
                    quee.push(pair<int,int>(new_x,new_y));
                    visited[new_x][new_y] =1;
                    }
            }
        }
        ans +=1; //搜完给ans加一

    }
    int numIslands(vector<vector<char>>& grid) {
        // bfs 
        // 方向数组 表示四个方向
        // 直接搜一个是1的点 对他用bfs搜 当队列为空时说明这是一个岛并给ans+1 结束循环后ans就是岛的数量
        int ans = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
        for (int i = 0;i< r;i++){
            for(int j=0;j<c;j++){
                if (visited[i][j] == 1) continue;
                if (grid[i][j] == '0') {visited[i][j] = 1;}
                else if(grid[i][j] == '1') {
                    bfs(ans,i,j,dx,dy,grid,visited);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

