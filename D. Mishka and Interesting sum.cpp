#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 2000000

using namespace std;


//point update and range query, with reversible functions
struct BIT{
	int N;
	vector <int> bit;
	BIT(int x): bit(x + 1), N(x) {};

	void update(int x, int val){
		while(x <= N) bit[x] ^= val, x += x&-x;
	}
	int queri(int l, int r){
		int x = r, ans = 0;
		while(x > 0) ans ^= bit[x], x -= x&-x;
		x = l - 1;
		while(x > 0) ans ^= bit[x], x -= x&-x;
		return ans;
	}
};

int n, m;
BIT e(maxn), o(maxn);
map<int, int> m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		int a;
 		cin>>a;
 		if(cnt[a]){
 			o.update(i, a);
 		}
 		else e.update(i, a);
 	}


 	cin>>m;
 	while(m--){
 		int l, r;
 		
 	}

 	
}