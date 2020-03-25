#include<bits/stdc++.h>
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int main()
{
    FILEIO
    int n, a, b, c;
    cin>>n>>a>>b>>c;

    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
    	dp[i] = -100000000;
    	if(i >= a){
    		dp[i] = max(dp[i], 1 +dp[i - a]);
    	}
    	if(i >= b){
    		dp[i] = max(dp[i], 1 + dp[i - b]);
    	}
    	if(i >= c){
    		dp[i] = max(dp[i], 1 + dp[i - c]);
    	}
    }
    cout<<dp[n]<<'\n';
}