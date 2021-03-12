/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    void bfs(){

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //bfs思想 如果可以全修完 那么bfs中不应该出现沿着边去到visited的情况
        //一旦出现要先完成这课 则说明不能完成
        // 可以把所有的课程对 用什么存可以使得O(1)就能找到前置课程呢

        vector<int> v; //邻接表的链的部分 用vector实现方便存取 存可以去的点位
        vector<vector<int>> adjust(numCourses,v); //邻接表
        vector<int> degree(numCourses,0); //入度表
        queue<int> quee; //队列用于bfs
        int fin = 0;//可以修完的数量

        for(int i =0;i<prerequisites.size();i++){
            //把邻接的情况存入表中
            adjust[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++; //入度加1

        }
        for(int j=0;j<numCourses;j++){
            if(degree[j]==0) {
                quee.push(j);
            }
            //把入度为0的点都放入
        }
        while(!quee.empty()){
            int cur = quee.front(); //当前可以完成的课
            quee.pop();
            fin++;
            //所有以它为前置的点入读均减一 如果为0也入队
            for(int i=0;i<adjust[cur].size();i++){
                degree[adjust[cur][i]]--;
                if (degree[adjust[cur][i]]==0){
                    quee.push(adjust[cur][i]);
                }
            }
        }
        return fin==numCourses;
    }
};
// @lc code=end

