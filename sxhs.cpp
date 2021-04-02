#include<iostream>
#include<cmath>
using namespace std;
bool check(int i){
    int sum =0;
    int tar =i;
    while(i>1){
        int last = i%10;
        i = i/10;
        sum += pow(last,3);
    }
    return sum==tar?true:false;
}


int main(){
    int m,n;
    int flag =0;
    while(cin>>m>>n){
    	for(int i=m;i<=n;++i){
        	if (check(i)){
                if (flag==1){
                    cout<<' '<<i;
                }
                else cout<<i;
                flag=1;
               
                
            } 
    	}
        if(!flag) cout<<"no";
        flag =0;
    	cout<<endl;
    }
}


