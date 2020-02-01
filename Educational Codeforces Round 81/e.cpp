#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, p[maxn + 1], a[maxn + 1], sm[maxn + 1];
PII dp[maxn + 1];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    fr(i, 1, n + 1) cin>>p[i];
    fr(i, 1, n + 1){
    	int x;
    	cin>>x;
    	a[p[i]] = x;
    }

    fr(i, 1, n + 1) sm[i] = a[i] + sm[i - 1];

    if(p[1] == 1) dp[1] = {0, 1};
    else{
    	if(sm[p[1] - 1] < a[p[1]] + a[1]){
    		dp[1] = {sm[p[1] - 1], p[1]};
    	}
    	else dp[1] = {a[p[1]] + a[1], 1};
    }

    fr(i, 2, n){
    	if(p[i] <= dp[i - 1].S) dp[i] = {dp[i - 1].F -  a[p[i]], dp[i - 1].S};
    	else{
    		if(sm[p[i] - 1] - sm[dp[i - 1].S] < a[p[i]]){
    			dp[i] = {dp[i - 1].F + sm[p[i] - 1] - sm[dp[i - 1].S], p[i]};
    		}
    		else dp[i] = {dp[i - 1].F + a[p[i]], dp[i - 1].S};
    	}
    }

    int ans = inf;
    fr(i, 1, n)
    	ans = min(ans, dp[i].F);
    
    cout<<ans<<'\n';
}