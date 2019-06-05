#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, m, hh, a[101], b[101], t[101][101], h[101][101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>hh;

 	fr(i, 1, m + 1) cin>>a[i];
 	fr(i, 1, n + 1) cin>>b[i];
 	fr(i, 1, n + 1)
 	{
 		fr(j, 1, m + 1){
 			cin>>t[i][j];
 		}
 	}

 	fr(j, 1, m + 1){
 		int x = a[j];
 		fr(i, 1, n + 1){
 			if(t[i][j] && b[i] >= x){
 				h[i][j] = x;
 				break;
 			}
 		}
 	}


 	fr(i, 1, n + 1){
 		int x = b[i];
 		fr(j, 1, m + 1){
 			if(t[i][j] && h[i][j] == 0){
 				if(a[j] >= x){
 					h[i][j] = x;
 					break;
 				}
 			}
 		}
 	}

 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			cout<<max(t[i][j], h[i][j])<<" ";
 		}
 		cout<<'\n';
 	}

}