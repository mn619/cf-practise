#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 100000

using namespace std;

int n, k, a[maxn + 1], b[maxn + 1];

int p[maxn + 1];

void sieve(){
	vector <bool> b(maxn + 1);

	fr(i, 2, maxn + 1){
		if(b[i] == 0){
			for(int j = i; j <= maxn; j += i){
				if(p[j]) continue;
				p[j] = i;
			}
		}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;
 	sieve();

 	fr(i, 1, n + 1) {
 		cin>>a[i];
 		int t = a[i];
 		b[i] = 1;
 		a[i] = 1;
 		// cout<<a[i]<<"\n";
 		while(t > 1){
 			int d = p[t];
 			int cnt = 0;
 			while(t%d == 0){
 				cnt++;
 				t /= d;
 			} 
 			cnt %= k;

 			int cnt1 = cnt;
 			while(cnt1--) a[i] *= d;

 			// cout<<d<<" "<<cnt<<'\n';
 			cnt = (k - cnt)%k;
 			while(cnt--){
 				b[i]*=d;
 				if(b[i] > maxn + 1){
 					b[i] = 0;
 					break;
 				}
 			}		
 		}
 	}


 	int ans = 0;
 	map <int, int> m;
 	fr(i, 1, n + 1){
 		if(b[i] == 0) continue;
 		ans += m[b[i]];
 		m[a[i]]++;
 		// cout<<a[i]<<" "<<b[i]<<" "<<ans<<'\n';
 	}

 	cout<<ans<<'\n';
}