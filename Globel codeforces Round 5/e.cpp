#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[maxn], segmx[4*maxn], segmn[4*maxn];
	
void build(int l, int r, int node){
	if(l == r){
		segmx[node] = a[l];
		segmn[node] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, 2*node);
	build(mid + 1, r, 2*node + 1);
	segmx[node] = max(segmx[2*node], segmx[2*node + 1]);
	segmn[node] = min(segmn[2*node], segmn[2*node + 1]);
}

int querimx(int l, int r, int l1, int r1, int node){
	if(l1 > r or r1 < l) return -inf;
	if(l <= l1 and r1 <= r) return segmx[node];
	int mid = (l1 + r1)/2;

	return max(querimx(l, r, l1, mid, 2*node), querimx(l, r, mid + 1, r1, 2*node + 1));
}

int querimn(int l, int r, int l1, int r1, int node){
	if(l1 > r or r1 < l) return inf;
	if(l <= l1 and r1 <= r) return segmn[node];
	int mid = (l1 + r1)/2;

	return min(querimn(l, r, l1, mid, 2*node), querimn(l, r, mid + 1, r1, 2*node + 1));
}

bool check(int l, int r){
	if(r <= n){
		int mx = querimx(l, r, 1, n, 1), mn = querimn(l, r, 1, n, 1);
		cout<<mn<<" "<<mx<<'\n';
		return mx <= 2*mn;
	}
	else{
		r = r%n + 1;
		int mx = max(querimx(l, n, 1, n, 1), querimx(1, r, 1, n, 1));
		int mn = min(querimn(l, n, 1, n, 1), querimn(1, r, 1, n, 1));
		cout<<mn<<" "<<mx<<'\n';
		return mx <= 2*mn;
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];
 	build(1, n, 1);
 	cout<<check(3, 4)<<'\n';
return 0;
 	fr(i, 1, n + 1){
 		int l = 1, r = n, ans = -1;
 		while(l <= r){
 			int mid = (l + r)/2;
 			int l1 = i, r1 = i + mid - 1;
 			if(check(l1, r1)){
 				ans = mid;
 				l = mid + 1;
 			}
 			else r = mid - 1;
 		}

 		cout<<ans<<'\n';
 	}

}