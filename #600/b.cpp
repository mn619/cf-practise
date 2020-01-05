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

int n, a[maxn], las[maxn], d = 1, lasday = 0;
set <int> s;
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    fr(i, 1, n + 1){
    	cin>>a[i];
    }
    vector <int> ans;
    fr(i, 1, n + 1){
    	if(a[i] < 0){
    		if(!s.count(-a[i]))
    			return cout<<"-1", 0;
    		else{
    			s.erase(-a[i]);
    			las[-a[i]] = d;
    		}
    	}
    	else{
    		if(s.count(a[i]) or las[a[i]] == d)
    			return cout<<"-1", 0;
    		else s.insert(a[i]);
    	}
    	
    	if(s.size() == 0){
    		d++;
    		ans.pb(i - lasday);
    		lasday = i;
    	}
    }

    if(s.size() != 0) return cout<<"-1", 0;
    cout<<ans.size()<<'\n';
    for(auto x: ans) cout<<x<<' ';
}
