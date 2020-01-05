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
// 
int n, m, c[maxn + 1];
VI cnt[maxn + 1];
VI p;

void sieve(){
	vector <bool> b(maxn + 1);
	for(int i = 2; i <= maxn; i++){
		if(b[i]) continue;
		p.pb(i);
		for(int j = i; j <= maxn; j += i)
			b[j] = 1;
	}
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    sieve();

    cin>>n>>m;
    fr(i, 1, n + 1){
    	int a;
    	cin>>a;
    	if(a > m) continue;
    	else cnt[a].pb(i);
    }

    int ans = cnt[1].size(), ind = 1;

    fr(i, 1, m + 1){
    	// if(cnt[i].size() == 0) continue;
    	for(int j = i; j <= m; j += i){
    		c[j] += cnt[i].size();
    	}
    	if(ans < c[i]) ans = c[i], ind = i;
    }

    vector <int> v;
    vector <int> pwr(p.size(), 0);

    fr(i, 1, ind + 1){
    	if((ind%i != 0) or (cnt[i].size() == 0)) continue;

		int temp = i;
		for(auto x: cnt[i]) v.pb(x);

		fr(j, 0, (int)p.size()){
			if(temp == 1) break;
			int c = 0;
			while(temp%p[j] == 0){
				c++;
				temp /= p[j];
			}
			pwr[j] = max(pwr[j], c);
		}
    }

    ans = 1;
    fr(i, 0, (int)p.size()){
    	while(pwr[i]){
    		ans *= p[i];
    		pwr[i]--;
    	}
    }

    sort(v.begin(), v.end());

    cout<<ans<<' '<<v.size()<<'\n';
    for(auto x: v) cout<<x<<" ";
}