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

    string s;
    cin>>s;

    set <int> x[26];
    int ans[n + 1];

    fr(i, 0, n){
    	int c = s[i] - 'a';
    	for(int clr = 1; clr < 100; clr++){
    		bool found = 0;
    		for(int j = c + 1; j < 26; j++){
    			if(x[j].count(clr)){
    				found = 1;
    				break;
    			}
    		}
    		if(!found){
    			ans[i] = clr;
    			break;
    		}
    	}
    	x[c].insert(ans[i]);
    }

    int mx = 0;
    fr(i, 0, n) mx = max(mx, ans[i]);
    if(mx > 2){
    	cout<<"NO\n";
    	return 0;
    }
    cout<<"YES\n";
    fr(i, 0, n ){
    	cout<<ans[i] - 1;
    }
}