#include <iostream>
using namespace std;

const int N = 25;
bool dp[N];

int main() {
    
    dp[1] = true;
    dp[2] = true;
    dp[4] = true;
    for (int i = 5; i <= 20; ++i) {
        if (!dp[i - 1] || !dp[i - 2] || !dp[i - 4]) dp[i] = true;
    }
    cout << dp[20] << endl;
    // 把所有的都打印出来，观察规律，然后再从数学上解释这个规律
    for (int i = 1; i <= 20; ++i) {
        cout << i << ' ' << dp[i] << endl;

    }
    return 0;
    
}

#include<iostream>
using namespace std;

int n,m;
cin>>n>>m;

int sum =0;

for (int i=0;i<m;++i){
    sum+=double(n);
    n = sqrt(n);
}

cout<<sum;