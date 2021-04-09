# include<iostream>

using namespace std;

int nums[10] = {1,2,3,3,5,6,7,8,9,10};


//上下边界的查找是根据不加1的那边来确定的 哪边边不加一说明他是主边界 次边界+1去追赶主界
int binarySearch(int low,int high,int target){
    while(low<high){
        cout<<"low: "<<low<<"high: "<<high<<endl;
        int mid = low+high>>1;
        if(nums[mid]<target){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}


int main(){
    int target = 3;
    int judge = binarySearch(0,9,3);
    cout<<judge<<endl;
}