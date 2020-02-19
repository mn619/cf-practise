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
	VI a(n - 1);

	set <int> s;

	fr(i, 1, n + 1) s.insert(i);
	VI cnt(n + 1, 0);

	fr(i, 0, n - 1){
		cin>>a[i];
		s.erase(a[i]);
		cnt[a[i]]++;
	}

	VII ans;
	int root = a[0];

	for(int i = n - 2; i >= 0; i--){
		int child = *(s.begin());
		s.erase(child);

		ans.pb({child, a[i]});
		cnt[a[i]]--;

		if(a[i] != root and cnt[a[i]] == 0)
			s.insert(a[i]);
	}

	assert(s.size() == 0);

	cout<<root<<'\n';
	for(auto x: ans) cout<<x.S<<" "<<x.F<<'\n';
}
