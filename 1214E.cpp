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

int n;
map <int, int> val;
pair <int, int> d[maxn];
VII s;

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    // FLASH

    cin>>n;
    fr(i, 1, n + 1){
    	cin>>d[i].F;
    	d[i].S = i;
    }

    sort(d + 1, d + n + 1);
    reverse(d + 1, d + n + 1);

    fr(i, 1, n + 1){
    	val[i] = 2*d[i].S - 1;
    	if(i > 1) s.pb({val[i], val[i - 1]});
    }

    fr(i, 1, n + 1){
    	if(val[i + d[i].F - 1] != 0){
    		s.pb({val[i + d[i].F - 1], 2*d[i].S});
    		if(val[i + d[i].F] == 0) val[i + d[i].F] = 2*d[i].S;
    	}
    	else{
    		assert(val[i - d[i].F + 1] != 0);
    		if(val[i - d[i].F] == 0) val[i - d[i].F] = 2*d[i].S;
    		s.pb({val[i - d[i].F + 1], 2*d[i].S});
    	}
    }

    for(auto x: s){
    	cout<<x.F<<" "<<x.S<<'\n';
    	if(x.F == 9 and x.S == 11) cerr<<"911 lol\n";
    }
}