#include<bits/stdc++.h>
#define maxn 200000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

vector <int> a(maxn + 1);
vector <vector<int>> cnt(201, vector <int> (maxn + 1, 0)); 

void solv(){
	int ans = 0;
	int n;
	cin>>n;

	for(int i = 1; i <= n; i++){
		cin>>a[i];
		cnt[a[i]][i] = 1;
		for(int j = 1; j <= 200; j++) cnt[j][i] += cnt[j][i - 1];
		ans = max(ans, cnt[a[i]][i]);
	}

	for(int i = 1; i <= n;i++){
		int x = cnt[a[i]][i], tot = cnt[a[i]][n];
		if(tot < 2*x) continue;

		int l = i, r = n, ind = -1;
		while(l <= r){
			int mid = (l + r)>>1;
			if(cnt[a[i]][mid] <= tot - x){
				ind = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		// assert(ind != -1);
		for(int j = 1; j <= 200; j++){
			if(j == a[i]) continue;
			ans = max(ans, 2*x + cnt[j][ind] - cnt[j][i]);
		}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 200; j++) 
			cnt[j][i] = 0;

	cout<<ans<<'\n';
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