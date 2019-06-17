#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define int long long 

using namespace std;

const int logN  = 18;
const int maxn  = 200000;
int a[200001], n;
int dp[2*maxn + 1][logN + 1], dpmax[2*maxn + 1][logN + 1];
int ans = 0, cnt = 0;

void calc(){
	for(int k = 0; k <= logN; k++){
		for(int i = 1; i <= n; i++){
			if(k == 0) dp[i][k] = a[i];
			else{
				dp[i][k] = (dp[i][k - 1]|dp[i + (1<<(k - 1))][k - 1]);
			}
		}
	}

	for(int k = 0; k <= logN; k++){
		for(int i = 1; i <= n; i++){
			if(k == 0) dpmax[i][k] = i;
			else{
				if(a[dpmax[i][k - 1]] > a[dpmax[i + (1<<(k - 1))][k - 1]])
					dpmax[i][k] = dpmax[i][k - 1];
				else dpmax[i][k] = dpmax[i + (1<<(k - 1))][k - 1];
				//dp[i][k] = (dp[i][k - 1]|dp[i + (1<<(k - 1))][k - 1]);
			}
		}
	}
}

int calor(int l, int r){
	int len = r - l + 1, res = 0;
	for(int k = logN; k >= 0; k--){
		if(len&(1<<k)){
			res |= dp[l][k];
			l += (1<<k);
		}
	}
	return res;
}

int find_max(int l, int r){
	int len = r - l + 1, res = l;
	for(int k = logN; k >= 0; k--){
		if(len&(1<<k)){
			if(a[dpmax[l][k]] > a[res]) res = dpmax[l][k];
			l += (1<<k);
		}
	}
	return res;
}

int bsl(int l1, int mxind){
	int l = l1, r = mxind, res = -1	;
	while(l <= r){
		int mid = (l + r)/2;
		if(calor(mid, mxind) > a[mxind]){
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}

int bsr(int mxind, int r1){
	int l = mxind, r = r1, res = -1;
	while(l <= r){
		int mid = (l + r)/2;
		if(calor(mxind, mid) > a[mxind]){
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}

void solve(int l, int r){
	if(r - l < 1) return;

	cnt++;
	assert(cnt <= n);
	
	int mxind = find_max(l, r);
	
	int l1 = mxind - l + 1, l2 = r - mxind + 1;
	int lind = bsl(l, mxind), rind = bsr(mxind, r);
	if(lind != -1){
		ans += (lind - l + 1)*(r - mxind + 1);
	}
	if(rind != -1){
		if(lind != -1)ans += (r - rind + 1)*(mxind - lind);
		else ans += (r - rind + 1)*(mxind - l + 1);
	}

	solve(l, mxind - 1);
	solve(mxind + 1, r);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	for(int i = 1; i<=n;i++){
 		cin>>a[i];
 	}

 	calc();
 	solve(1, n);

 	cout<<ans;
}