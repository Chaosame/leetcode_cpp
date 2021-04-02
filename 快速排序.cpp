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

void quicksort(vector<int> nums,int l,int r){
    if(l>=r) return;//下标相等位置已经确定了不用排
    int i=l-1 , j=r+1, mid = nums[i+j>>1];
    while(i<j){
        do i++;while(nums[i]<mid);
        do j--;while(nums[i]>mid);
        if(i<j) swap(nums[i],nums[j]); // ij依然有效则进行交换
    }
    quicksort(nums,l,j);
    quicksort(nums,j+1,r);
}
//撸个快排
void qs(vector<int>nums,int i,int j){
    if(i>=j) return;
    int l=i-1,r=j+1,m=(l+r)>>1;
    while(l<r){
        do l--;while(nums[i]<nums[m]);
        do r++;while(nums[i]>nums[m]);
        if(r>l) swap(nums[l],nums[r]);
    }
    qs(nums,i,l);
    qs(nums,r+1,j);
}


int main(){
    int n = a.size()-1;
    quicksort(a,0,n-1);
    for (int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    char a;
    cin>>a;
}