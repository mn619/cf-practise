#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, k, ans[2001];
char c;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>k;

 	fr(i, 1, n + 1){
 		fr(j, 1, m + 1){
 			cin>>c;
 			if(c == 'U'){
 				ans[j] += (i&1);
 			}
 			else if(c == 'R'){
 				if(i + j - 1 <= m){
 					ans[i + j - 1]++;
 				}
 			}
 			else if(c == 'L'){
 				if(j - (i - 1) >= 1){
 					ans[j - (i - 1)]++;
 				}
 			}
 		}
 	}


 	fr(i, 1, m + 1){
 		cout<<ans[i]<<" ";
 	}


}