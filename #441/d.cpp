#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
bool in[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	int las = n + 1;

 	cout<<1<<" ";
 	fr(i, 1, n + 1){
 		int p;
 		cin>>p;
 		in[p] = 1;
 		while(in[las - 1]) las--; 

 		int ans = 1 + i - (n - las + 1);
 		cout<<ans<<' ';
 	}
}