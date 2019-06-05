#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;
int a[51][51], b[51][51];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i, 1, n + 1){
 		fr(j, 1, m+ 1){
 			cin>>a[i][j];
 		}
 	}

 	fr(i, 1, n + 1){
 		fr(j, 1, m+ 1){
 			cin>>b[i][j];
 		}
 	}

 	int c[n + 1][m + 1], d[n + 1][m + 1];
 	
 	fr(i, 1, n+  1){
 		fr(j, 1, m + 1){
 			c[i][j] = max(a[i][j], b[i][j]);
 			d[i][j] = min(a[i][j], b[i][j]);
 		}
 	}

 	fr(j, 2, m + 1){
 		if(c[1][j - 1] >= c[1][j] || d[1][j - 1] >= d[1][j]) return cout<<"Impossible", 0;
 	}

	fr(j, 2, n + 1){
 		if(c[j - 1][1] >= c[j][1] || d[j - 1][1] >= d[j][1]) return cout<<"Impossible", 0;
	} 	

 	fr(i, 2, n + 1){
 		fr(j, 2, m + 1 ){
 			if(c[i][j] <= max(c[i - 1][j], c[i][j - 1]) || d[i][j] <= max(d[i - 1][j], d[i][j - 1])) return cout<<"Impossible", 0;
 		}
 	}

 	cout<<"Possible";
}	