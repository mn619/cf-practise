#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
#define logn 18
using namespace std;

int n, a[maxn + 1], b[maxn], m;
int max_a[maxn + 1][logn + 1], max_b[maxn + 1][logn + 1];

bool check(int l, int r){
	int len = r - l + 1;
	int mxreq = 0;
	fr(bit, 0, logn + 1){
		if(len&(1<<bit)){
			mxreq = max(mxreq, max_a[r][bit]);
			r -= (1<<bit);
		}
	}
	l = len, r = n;
	len = r - l + 1;
	int mxava = 0;

	fr(bit, 0, logn + 1){
		if(len&(1<<bit)){
			mxava = max(mxava, max_b[r][bit]);
			r -= (1<<bit);
		}
	}

	return (mxreq <= mxava);
}

void solv(){
	cin>>n;
	
	fr(i, 1, n + 1) {cin>>a[i]; b[i] = 0;}
	cin>>m;

	fr(i, 1, m + 1){
		int p, s;
		cin>>p>>s;
		b[s] = max(b[s], p);
	}

	fr(i, 1, n + 1){
		max_a[i][0] = a[i];
		max_b[i][0] = b[i];
		fr(j, 1, logn + 1){
			max_a[i][j] = max_a[i][j - 1];
			max_b[i][j] = max_b[i][j - 1];
			int k = (1<<(j - 1));
			if(i - k > 0) {
				max_a[i][j] = max(max_a[i][j], max_a[i - k][j - 1]);
				max_b[i][j] = max(max_b[i][j], max_b[i - k][j - 1]);
			}
		}
	}

	int i = 1, ans = 0;
	while(i <= n){
		int l = i, r = n, nex = -1;
		while(l <= r){
			int mid = (l + r)/2;
			if(check(i, mid)){
				l = mid + 1;
				nex = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		i = nex;
		if(nex == -1){
			ans = -1;
			break;
		}
		ans++;
	}

	cout<<ans<<'\n';


}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	//FLASH

 	int t;
 	cin>>t;
 	while(t--) solv();	
}