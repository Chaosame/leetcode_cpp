#include <vector>
#include <iostream>
using namespace std; 

vector<int> a{2,4,1,23,5,76,0,43,24,65};


void partition(vector<int>& nums,int start,int end){
    if (start>=end){
        return;
    }
    int l = start;
    int r = end;//左闭右闭
    int target = nums[l];
    while(l<r){
        while(l<r&&nums[r]>=target){
            r--;
        }
        while(l<r&&nums[l]<=target){
            l++;
        }
        if (r > l) {
            swap(nums[l], nums[r]);
        }
    }
    
    nums[start] = nums[l]; //防止l位置的元素丢失 由于右指针会停在第一个小于的位置所以这个值应该放在开头
    nums[l] = target;
    partition(nums,start,l-1);
    partition(nums,l+1,end);
}
/**
 * 快排模板，这里的每一个变量，每个符号都不能随意改变。
 * @param q
 * @param l  闭区间的左端点
 * @param r  闭区间的右端点
 */
void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
       do i ++;  while (q[i] < x);
       do j --;  while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}



int main(){
    int n = a.size()-1;
    partition(a,0,n-1);
    for (int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    char a;
    cin>>a;
}