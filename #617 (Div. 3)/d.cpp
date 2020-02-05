#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000001

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;
int n, a, b, k;

int bs(int x){
	int l = 1, r = inf;

	int ans = 0;
	while(l <= r){
		int mid = (l + r)>>1;
		if(((mid  + 1)/2)*a + (mid/2)*b >= x){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>a>>b>>k;

    int ans = 0;

    vector <int> req;
    fr(i, 1, n + 1){
    	int h;
    	cin>>h;
    	int c = bs(h);
    	int d = ((c + 1)/2)*a + (c/2)*b - b;
    	if(c&1){
    		ans++;
    		continue;
    	}
    	else {
    		int k1 = (h - d)/a + ((h - d)%(a) != 0);
    		req.pb(k1);
    	}
    }

    sort(all(req));

    fr(i, 0, (int)req.size()){
    	if(k >= req[i]){
    		k -= req[i];
    		ans++;
    	}
    }
    cout<<ans<<'\n';
}