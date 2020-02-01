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
    	string s, t;
    	cin>>s>>t;


    	vector <bool> a(26), b(26);

    	int n = s.size(), m = t.size();
    	fr(i, 0, n) a[s[i] - 'a'] = 1;
    	fr(i, 0, m) b[t[i] - 'a'] = 1;

    	bool ok = 1;
    	fr(i, 0, 26){
    		if(b[i] and !a[i]) ok = 0;
    	}

    	if(!ok){
    		cout<<"-1\n";
    		continue;
    	}

    	vector <vector<int>> las(n + 1, vector <int>(26, -1));

    	for(int i = n - 1; i >= 0; i--){
    		if(i < n - 1){
    			for(int j = 0; j < 26; j++) las[i][j] = las[i + 1][j];
    		}
    		las[i][s[i] - 'a'] = i;
    	}

    	fr(i, 0, 26) las[n][i] = -1;

    	int ans = 0, ptr = 0;
    	int i = 0;
    	while(i < m){
    		if(las[ptr][t[i] - 'a'] == -1){
    			ans++;
    			ptr = 0;
    		}
    		else{
    			ptr = las[ptr][t[i] - 'a'] + 1;
    			i++;
    		}
    	}

    	cout<<ans + 1<<'\n';
    }
}