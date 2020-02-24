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

using namespace std;

void solv(){
	int n, m;
	string s;

	cin>>n>>m>>s;


	vector <int> sm(n + 2, 0);
	int p[m + 1];

	fr(i, 1, m + 1){
		cin>>p[i];

		sm[1]++;
		sm[p[i] + 1]--;
	}
	sm[1]++;

	fr(i, 1, n + 1){
		sm[i] += sm[i - 1];
	}

	vector<int> cnt(26, 0);


	fr(i, 1, n + 1){
		cnt[s[i - 1] - 'a'] += sm[i];
	}

	fr(i, 0, 26) cout<<cnt[i]<<" ";
	cout<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;
    while(t--) solv();
}