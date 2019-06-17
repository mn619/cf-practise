#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;
char c[101][10001];
int l[101][10001], r[101][10001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;
 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			cin>>c[i][j];
 			l[i][j] = r[i][j] = mod;
 		}
 	}

 	fr(i, 1, n + 1){
 		int las = 0;
 		fr(j, 0, 2*m){
 			int ind = (j%m) + 1;
 			if(c[i][ind] == '1') las = j%m + 1;
 			if(las != 0){
 				l[i][j%m + 1] = min((m + las - ind)%m, (m + ind - las)%m);
 			}
 		}
 	}

 	fr(i, 1, n + 1){
 		int las = 0;
 		for(int j = 2*m - 1; j >= 0; j--){
 			int ind = j%m + 1;
 			if(c[i][ind] == '1') las = ind;
 			if(las != 0){
 				r[i][ind] = min((m + las - ind)%m, (m + ind - las)%m);
 			}
 		}
 	}

 	int ans = mod;

 	fr(j, 1, m + 1){
 		int ans1 = 0;
 		fr(i, 1, n + 1){
 			ans1 += min(r[i][j], l[i][j]);
 		}
 		ans = min(ans, ans1);
 	}

 	if(ans != mod)
 	cout<<ans;	
 	else cout<<-1;
}