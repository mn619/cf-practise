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

    int n;
    cin>>n;

    int val[n + 1];
    PII a[n + 2];
    VI parent(n + 1), sz(n + 1);
    a[0] = a[n + 1] = {inf, -1};

    fr(i, 1, n + 1){
    	cin>>val[i];
    	a[i] = {val[i], i};
    	parent[i] = i;
    	sz[i] = 1;
    }

    auto find_set = [&](int a){
    	while(parent[a] != a)
    		a = parent[a] = parent[parent[a]];
    	return a;
    };

    auto union_set = [&](int a, int b){
    	a = find_set(a), b = find_set(b);
    	if(a != b){
    		int new_sz = sz[a] + sz[b];
    		if(sz[a] < sz[b])
    			parent[a] = parent[b];
    		else 
    			parent[b] = parent[a];
    		sz[a] = sz[b] = new_sz;
    	}
    };

    map <int, int> cnt;
    sort(a + 1, a + n + 1);
    int mx = 0, ans = 0;

    fr(i, 1, n + 1){
    	int new_sz = 0;
    	if(val[a[i].S - 1] < a[i].F and a[i].S > 1){
    		int s = find_set(a[i].S - 1);
    		new_sz += sz[s];
    		cnt[sz[s]]--;
    		if(cnt[sz[s]] == 0)
    			cnt.erase(sz[s]);
    		union_set(a[i].S, s);
    	}
    	if(val[a[i].S + 1] < a[i].F and a[i].S < n){
    		int s = find_set(a[i].S + 1);
    		new_sz += sz[s];
    		cnt[sz[s]]--;
    		if(cnt[sz[s]] == 0)
    			cnt.erase(sz[s]);
    		union_set(a[i].S, s);
    	}

    	new_sz++;
    	cnt[new_sz]++;
    	if(cnt.size() == 1 and cnt[new_sz] > mx){
    		mx = cnt[new_sz];
    		ans = a[i].F + 1;
    	}
    }

    cout<<ans<<'\n';
}