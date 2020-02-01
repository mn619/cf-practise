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

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int n, m;
    cin>>n>>m;

    vector <vector <int>> a(n + 1, vector <int> (m + 1));
    fr(i, 0, n)
    fr(j, 0, m){
    	cin>>a[i][j];
    	a[i][j]--;
    }


    int ans = 0;
    for(int j = 0; j < m; j++){
    	vector <int> dis(n + 1, 0);
    	for(int i = 0; i < n; i++){
    		if(a[i][j]%m != j or a[i][j] >= n*m){
    			continue;
    		}
    		
    		int t = (a[i][j] - j)/m;
    		if(t < 0 or t > n) continue;

    		if(t <= i){
    			dis[i - t]++;
    		}
    		else dis[n + i - t]++;
    	}

    	int sm = 0;
    	fr(i, 0, n) sm += dis[i];
    	int ans1 = inf;
    	fr(i, 0, n){
    		ans1 = min(ans1, n - dis[i] + i);
    	}

    	ans += ans1;
    }

    cout<<ans<<'\n';

}