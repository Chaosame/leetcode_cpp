#include<iostream>

//手撸线段树
int p[6] = {1,3,5,7,9,11};
int tree[1000];


void build_tree(int node,int start,int end){ //node是数的节点 start end是原数组的起点和终点 左闭右闭
    if (start==end) {
        tree[node] = p[start];
        return;
        }
    int mid = start+end>>1;
    int left_node = 1+node<<1;
    int right_node = 2+node<<1;
    build_tree(left_node,start,mid);
    build_tree(right_node,mid+1,end);
    tree[node] = tree[left_node]+tree[right_node];
}

void update(int val,int idx,int node,int start,int end){
    if(idx<start||idx>end){
        return;
    }
    if (start==end){
        tree[node] = val;
        return;
    }
    int mid = start+end>>1;
    int left_node = 1+node<<1;
    int right_node = 2+node<<1;
    update(val,idx,left_node,start,mid);
    update(val,idx,right_node,mid+1,end);
    tree[node] = tree[left_node]+tree[right_node];
}

int query(int node,int start,int end,int l,int r){
    if (r<start||l>end) return 0 ;
    if(start==end) return tree[node];
    int mid = start+end>>1;
    int left_node = 1+node<<1;
    int right_node = 2+node<<1;
    int l_res = query(left_node,start,mid,l,r);
    int r_res = query(right_node,mid+1,end,l,r);
    return l_res+r_res;

}


void print(){
    for(int i=0;i<30;++i){
        std::cout<<tree[i]<<std::endl;
    }
}

int main(){
    build_tree(0,0,5);
    print();

    std::cout<<"update!!!!"<<std::endl;
    update(2,0,0,0,5);
    print();

    std::cout<<"query!!!"<<std::endl;
    int res = query(0,0,5,2,5);
    std::cout<<res<<std::endl;
    
    
}