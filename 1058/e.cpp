#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int a[300001], prefix[300001], ans = 0, n;
int maxTree[600001], cntTree[600001][2];

void build_maxTree(int l, int r, int node){
	if(l == r) {
		maxTree[node] = l;
		return;
	}

	int mid = (l + r)/2;

	build_maxTree(l, mid, 2*node);
	build_maxTree(mid + 1, r, 2*node + 1);

	if(a[maxTree[2*node]] > a[maxTree[2*node + 1]]) maxTree[node] = maxTree[2*node];
	else maxTree[node] = maxTree[2*node + 1];
}

int findMax(int l, int r, int l1, int r1, int node){
	if(l1 > r || r1 < l) return 0;
	if(l <= l1 and r1 <= r) return maxTree[node];

	int mid = (l1 + r1)/2;

	int x1 = findMax(l, r, l1, mid, 2*node);
	int x2 = findMax(l, r, mid + 1, r1, 2*node + 1);
	if(a[x1] > a[x2]) return x1;
	return x2;
}

void build_cntTree(int l, int r, int node){
	if(l == r){
		cntTree[node][1] = 0;
		cntTree[node][0] = 0;

		if(prefix[l]&1) cntTree[node][1] = 1;
		else cntTree[node][0] = 1;
		return;
	}

	int mid = (l + r)/2;
	build_cntTree(l, mid, 2*node);
	build_cntTree(mid + 1, r, 2*node + 1);

	cntTree[node][0] = cntTree[2*node][0] + cntTree[2*node + 1][0];
	cntTree[node][1] = cntTree[2*node][1] + cntTree[2*node + 1][1];
}

int findCnt(int l, int r, int l1, int r1, int node, bool b){
	if(l1 > r || r1 < l) return 0;
	if(l <= l1 and r1 <= r) return cntTree[node][b];

	int mid = (l1 + r1)/2;
	return  findCnt(l, r, l1, mid, 2*node, b) + findCnt(l, r, mid + 1, r1, 2*node + 1, b);
}

void solve(int l, int r){

	if(r <= l + 1) {ans += (r ==l ); return;}

	int x = findMax(l, r, 1, n, 1);

	if(x - l < r - x){
		fr(i, l, x + 1){
			int l1 = x, r1 = n;
			int ans1 = -1;

			while(l1 <= r1){
				int mid = (l1 + r1)/2;
				if(prefix[mid] - prefix[i - 1] < 2*a[x]){
					l1 = mid + 1;
				}
				else{
					ans1 = mid;
					r1 = mid - 1;
				}
			}

			if(ans1 == -1) continue;
			ans += findCnt(ans1 + 1, n, 1, n, 1, (prefix[ans1] - prefix[i - 1])&1);
			ans += !((prefix[ans1] - prefix[i - 1])&1);
		}
	}
	else{
		fr(i, x, n + 1){
			int l1 = 1, r1 = x;
			int ans1 = -1;

			while(l1 <= r1){
				int mid = (l1 + r1)/2;
				if(prefix[i] - prefix[mid - 1] < 2*a[x]){
					r1 = mid - 1;
				}
				else{
					ans1 = mid;
					l1 = mid + 1;
				}
			}

			if(ans1 == -1) continue;
			ans += findCnt(1, ans1, 1, n, 1, (prefix[i] - prefix[ans1 - 1])&1);
			ans += !((prefix[i] - prefix[ans1 - 1])&1);
		}
	}

	solve(l, x - 1);
	solve(x + 1, r);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1)
 	{
 		int x;
 		cin>>x;
 		while(x){
 			a[i] += x&1;
 			x /= 2;
 		}

 		prefix[i] = prefix[i - 1] + a[i];
 	}


 	build_cntTree(1, n, 1);
 	build_maxTree(1, n, 1);

 	solve(1, n);
 	cout<<ans;
}	