#include<bits/stdc++.h>
#define int long long
#define maxn 500000
#define inf 10000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, c;
vector <int> v[maxn + 1];
signed main()
{
	//FILEIO
	cin>>n>>c;
	int ans = 0;
	vector <int> pref(n + 1);
	for(int i = 1; i <= n; i++){
		int a;
		cin>>a;
		v[a].push_back(i);
		pref[i] = pref[i - 1] + (a == c);
		if(a == c)
			ans++;
	}

	for(int i = 1; i <= maxn; i++){
		if(i == c or ((int)v[i].size() == 0)) continue;
		int ans1 = pref[n] + 1, sum = 1;
		for(int j = 1; j < (int)v[i].size(); j++){
			sum += 1 - (pref[v[i][j]] - pref[v[i][j - 1]]);
			if(sum <= 0)
				 sum = 1;
			if(sum + pref[n] > ans1){
				ans1 = sum + pref[n];
			}
		}
		ans = max(ans, ans1);
	}

	cout<<ans<<'\n';

}
