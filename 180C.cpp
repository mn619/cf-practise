#include<bits/stdc++.h>
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int main()
{
    FILEIO
    string s;

    cin>>s;
    int n = s.size();
    int arr[n + 1];
    for(int i = 0; i < n; i++){
    	if('A'<=s[i] and s[i] <= 'Z') arr[i + 1] = 0;
    	else arr[i + 1] = 1;
    }

    int dp[n + 1][2];
    dp[1][0] = (arr[1] == 1);
    dp[1][1] = (arr[1] == 0);

    for(int i = 2; i <= n; i++){
    	dp[i][0] = dp[i - 1][0] + (arr[i] == 1);
    	dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + (arr[i] == 0);
    }

    cout<<min(dp[n][0], dp[n][1]);
}