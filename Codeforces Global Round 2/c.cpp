#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

bool a[501][501] = {{0}}, b[501][501] = {{0}};
int n, m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;


 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			cin>>a[i][j];
 		}
 	}
 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			cin>>b[i][j];
 		}
 	}


 	fr(i, 1, n + 1){
 		int suma= 0, sumb = 0;
 		fr(j, 1, m + 1){
 			suma += a[i][j];
 			sumb += b[i][j];
 		}

 		suma %= 2;
 		sumb %= 2;
 		if(suma != sumb) return cout<<"No", 0;
 	}

 	fr(j, 1, m + 1){
 		int suma= 0, sumb = 0;
 		fr(i, 1,n + 1){
 			suma += a[i][j];
 			sumb += b[i][j];
 		}
 		suma %= 2;
 		sumb %= 2;
 		if(suma != sumb) return cout<<"No", 0;
 	}

 	cout<<"Yes";
}