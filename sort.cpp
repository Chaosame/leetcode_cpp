#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>& nums){
    int n  = nums.size();
    int flag= 0;
    for(int i=0;i<n;++i){
        for(int j=n-1;j>i;--j){
            if(nums[j]<nums[j-1]){
                int tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
                flag=1;
            }
        }
        if(!flag) break;
    }

}

void choose(vector<int>& nums){
    int n = nums.size();
    for(int i=0;i<n;++i){
        int min = i;
        for(int j=i;j<n;++j){
            if(nums[j]<nums[min]){
                min = j;
            }
        }
        swap(nums[min],nums[i]);
    }
}

void quick_sort(vector<int>& nums,int start,int end){
    int l = start;
    int r = end;
    if(l>=r) return;
    int piv = nums[l];
    while(l<r){
        while(l<r&&nums[r]>=piv) --r;
        while(l<r&&nums[l]<=piv) ++l;
        if(l<r){
            swap(nums[l],nums[r]);
        }
    }
    nums[start] = nums[l];
    nums[l] = piv;
    quick_sort(nums,start,l-1);
    quick_sort(nums,r+1,end);
}

void print(vector<int> nums){
    int n = nums.size();
    for(int i=0;i<n;++i){
        cout<<nums[i]<<endl;
    }
}
int main(){
    vector<int> nums ={2,3,4,1,5,7,8,9,0,11};
    quick_sort(nums,0,nums.size()-1);
    print(nums);

}