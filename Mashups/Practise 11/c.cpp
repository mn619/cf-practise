#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, m;
 	cin>>n>>m;
 	cout<<min(n,m) + 1<<'\n';

 	if(n < m){
 		int j = n;
 		fr(i, 0, n + 1){
 			cout<<i<<" "<<j<<'\n';
 			j--;
 		}
 	}
 	else{
 		int j = m;
 		fr(i, 0, m+ 1){
 			cout<<j<<" "<<i<<"\n";
 			j--;
 		}
 	}

}