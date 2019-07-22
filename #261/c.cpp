#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int ans[1001][1001], n, k, d;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k>>d;
 	bool ok = 0;
 	int temp = 1;
 	fr(i, 1, d + 1){
 		temp *= k;
 		if(temp >= n){
 			ok = 1;
 			break;
 		}
 	}
 	if(!ok) return cout<<-1, 0;
 	
 	fr(j, 0, n + 1){
 		int temp = j;
 		fr(i, 0, d + 1){
 			ans[i][j] = temp%k + 1;
 			temp /= k;
 		}
 	}


 	fr(i, 0, d){
 		fr(j, 0, n) cout<<ans[i][j]<<" ";
 		cout<<'\n';
 	}

}