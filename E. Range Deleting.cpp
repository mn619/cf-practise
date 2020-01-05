#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 1000000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, x, mx[maxn + 1], mn[maxn + 2], mnsuf[maxn + 1];
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>x;
    memset(mx, -x,  sizeof mx);
    memset(mn, x, sizeof mn);
    memset(mnsuf, x, sizeof mnsuf);

    fr(i, 1, n + 1){
    	int a;
    	cin>>a;
    	mn[a] = min(mn[a], i);
    	mnsuf[a] = mn[a];
    	mx[a] = max(mx[a], i);
    }

    for(int i = 1; i <= x; i++){
    	mx[i] = max(mx[i], mx[i - 1]);
    }
    for(int i = x; i >= 1; i--){
    	mnsuf[i] = min(mnsuf[i], mnsuf[i + 1]);
        cout<<i<<" "<<mnsuf[i]<<"\n";
    }

    int l1 = x,temp = 0;
    for(int i = x; i >= 1;  i--){
        temp = max(temp, mx[])
        if(mn[])
    }
    int ans = 0, curmax = 0;
    for(int i = 1; i <= x; i++){
    	int l = i, r = x;
		int ans1 = i;
    	while(l <= r){
    		int mid = (l + r)>>1;
    		if(mnsuf[mid] <= curmax){
    			ans1 = mid;
    			l = mid + 1;
    		}
    		else {
    			r = mid - 1;
    		}
    	}
    	ans += x - ans1 + 1;
        cout<<i<<" "<<ans1<<'\n';
    	curmax = max(curmax, mx[i]);
    	if(curmax > mn[i]) break;
    }
    cout<<ans<<'\n';
}