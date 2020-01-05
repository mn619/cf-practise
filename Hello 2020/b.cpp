#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 1000010
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;


int n, mx[maxn], mn[maxn], bit[maxn];
VI s[maxn];
bool b[maxn];

void update(int ind){
	int x = ind;
	while(x <= maxn){
		bit[x]++;
		x += x&-x;
	}
}

int query(int ind){
	int x = ind;
	int ans = 0;
	while(x){
		ans += bit[x];
		x -= x&-x;
	}
	return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH	

    cin>>n;
    fr(i, 1, n + 1){
    	int l;
    	cin>>l;
    	mn[i] = inf;
    	fr(j, 1, l + 1){
    		int x;
    		cin>>x;
    		x++;
    		s[i].pb(x);
    		if(x > mn[i]) b[i] = 1;
    		mx[i] = max(mx[i], x);
    		mn[i] = min(mn[i], x);
    	}

    	if(!b[i])
    		update(mn[i]);
    }

    int cnt = 0;
    fr(i, 1, n + 1){
    	if(b[i]) cnt++;
    }
    int ans = 0;

    fr(i, 1, n + 1){
    	if(b[i]) continue;
    	else  ans += query(mx[i] - 1);
    }

    ans += cnt*n + (n - cnt)*cnt;
    cout<<ans<<'\n';
}