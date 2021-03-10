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


int main(){
    int n = a.size()-1;
    partition(a,0,n-1);
    for (int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    char a;
    cin>>a;
}