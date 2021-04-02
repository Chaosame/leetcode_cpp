#define SIZE 100
#include <iostream>
int pa[SIZE];

inline void init(){
    for(int i =0;i<SIZE;++i){
        pa[i] = i;//初始化父亲是自己
    }
}

inline int find(int i){//找i的头头
    if(pa[i] == i) return i;//找到头头了直接返回
    return find(pa[i]);//不然递归查头头
}

inline void merge(int i,int j){
    pa[find(i)]=find(j);//把j的头头变成i的头头即可
}

int main(){
    init();
    merge(3,4);
    std::cout<<find(3)<<std::endl;
}