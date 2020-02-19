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
    	string s;
    	cin>>s;
    	int n = s.size();
    	vector <bool> p(n), suf(n);
    	for(int i = 0; i < n; i++){
    		if(s[i] == '1') p[i] = true;
    		if(i > 0 and p[i - 1]) p[i] = true; 
    	}

    	for(int i = n - 1; i >= 0; i--){
    		if(s[i] == '1') suf[i] = true;
    		if(i < n - 1 and suf[i + 1]) suf[i] = true;
    	}

    	int ans = 0;
    	for(int i = 0; i < n; i++){
    		ans += (s[i] == '0' and p[i] and suf[i]);
    	}
    	cout<<ans<<'\n';
    }
}