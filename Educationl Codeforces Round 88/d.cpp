#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[100001], p[100001], dpa[100001][20], dp_min[100001][20], dp_max[100001][20];


int find_mx(int l, int r){
	int len = r - l + 1;

	int ans = -10000000000;

	for(int j = 19; j >= 0; j--){
		if(len>>j&1){
			ans = max(ans, dpa[r][j]);
			r -= (1<<j);
		}
	}
	return ans;
}

int find_mxp(int l, int r){
	int len = r - l + 1;
	int ans = -10000000000;
	for(int j = 19; j >= 0; j--){
		if(len>>j&1){
			ans = max(ans, dp_max[r][j]);
			r -= (1<<j);
		}
	}

	return ans;
}

int find_mnp(int l, int r){
	int len = r - l + 1;
	assert(len >= 0);
	int ans = 10000000000;
	for(int j = 19; j >= 0; j--){
		if(len>>j&1){
			ans = min(ans, dp_min[r][j]);
			r -= (1<<j);
		}
	}

	return ans;
}
void solv(){
	cin>>n;

	a[0] = 100000;
	p[0] = 0;

	for(int j = 0; j < 19; j++) dpa[0][j] = a[0];

	for(int i = 1; i <= n; i++){
		cin>>a[i];
		p[i] = p[i - 1] + a[i];
		dpa[i][0] = a[i];
		dp_max[i][0] = p[i];
		dp_min[i][0] = p[i];

		for(int j = 1; j < 20; j++){
			dpa[i][j] = dpa[i][j - 1];
			dp_min[i][j] = dp_min[i][j - 1];
			dp_max[i][j] = dp_max[i][j - 1];
			
			if(i >= (1<<(j - 1))){
				dpa[i][j] = max(dpa[i][j], dpa[i - (1<<(j - 1))][j - 1]);
				dp_min[i][j] = min(dp_min[i][j], dp_min[i - (1<<(j - 1))][j - 1]);
				dp_max[i][j] = max(dp_max[i][j], dp_max[i - (1<<(j - 1))][j - 1]);
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int l = 0, r = i, L = i, R = i;

		while(l <= r){
			int mid = (l + r)>>1;
			int mx = find_mx(mid, i);
			if(mx <= a[i]){
				assert(mx == a[i]);
				L = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		l = i, r = n;
		while(l <= r){
			int mid = (l + r)>>1;
			int mx = find_mx(i, mid);
			if(mx <= a[i]){
				assert(mx == a[i]);
				R = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		int mxp = find_mxp(i, R);
		int mnp = find_mnp(L - 1, i - 1);

		ans = max(ans, mxp - mnp - a[i]);
		// cout<<i<<" "<<L<<" "<<R<<"\n";
	}

	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t = 1;
    // cin>>t;

    while(t--) solv();
}