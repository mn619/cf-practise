#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    const int N = 60;
    int dp[N + 1];

    dp[0] = 0;
    int las = 0;
    for(int i = 1; i <= 20; i++){
    	for(int j = 1; j <= i + 1; j++){
    		if(las + j > N) break;
    		dp[las + j] = i;
    	}
    	las = las + i + 1;
    }

    int n, x = 0;
    cin>>n;

    for(int i = 1; i <= n; i++){
    	int s;
    	cin>>s;
    	x ^= dp[s];
    }

    if(x == 0){
    	cout<<"YES\n";
    }
    else cout<<"NO\n";
}