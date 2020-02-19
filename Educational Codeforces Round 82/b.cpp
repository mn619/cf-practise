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

    int t;
    cin>>t;

    while(t--){
    	int n, g, b;
    	cin>>n>>g>>b;
    	if(g <= b){
    		cout<<n<<'\n';
    	}
    	else{
    		int l = 1, r = 1e18;
    		int ans = 1e18;

    		while(l <= r){
    			int mid = (l + r)>>1;
    			int good = (mid/(b + g))*g + min((mid%(b + g)), g);
    			int bad = mid - good;
    			if(good >= n){
    				ans = mid;
    				r = mid - 1;
    			}
    			else if(good >=  n - good and good + bad >= n){
    				ans = mid;
    				r = mid - 1;
    			}
    			else l = mid + 1;
    		}

    		cout<<ans<<'\n';
    	}
    }
}