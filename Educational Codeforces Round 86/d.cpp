#include<bits/stdc++.h>
#define maxn 200000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k,  c[maxn + 1];
int cnt[maxn + 1];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k;
    vector <int> m(n);

    for(int i = 0; i < n; i++) {
    	cin>>m[i];
    	cnt[m[i]]++;
    }

    sort(m.begin(), m.end());
    reverse(m.begin(), m.end());

    for(int i = k - 1; i >= 1; i-- ) cnt[i] += cnt[i + 1];

    for(int i = 1; i <= k; i++) cin>>c[i];
    int l = 0;
	for(int i = 1; i <= k; i++) l = max(l, cnt[i]/c[i] + (cnt[i]%c[i] != 0));

	vector <vector<int>> ans(l);
	
	for(int i = 0; i < n; i++){
		ans[i/c[m[i]]].push_back(m[i]);
	}

	cout<<ans.size()<<'\n';

	for(auto x: ans){
		cout<<x.size()<<' ';
		for(auto y: x) cout<<y<<" ";
			cout<<'\n';
	}
}