#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	int i1 = 1, j1 = 1, i2 = n, j2 = m;


 	fr(i, 1, n/2 + 1){
 		fr(j, 1, m + 1){
 			cout<<i1<<" "<<j1<<"\n";
 			cout<<i2<<" "<<j2<<"\n";
 			j1++;
 			j2--;
 		}

 		i1++;
 		i2--;
 		j1 = 1;
 		j2 = m;
 	}
 	
 	if(n&1){
 		j1 = 1, j2 = m;
 		for(int j = 1; j <= m; j++){
 			if(j&1){
 				cout<<(n + 1)/2<<" "<<j1++<<"\n";
 			}
 			else cout<<(n + 1)/2<<" "<<j2--<<"\n";
 		}
 	}		
}