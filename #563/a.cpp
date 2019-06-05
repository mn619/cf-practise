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

 	int n;
 	cin>>n;
 	int a[2*n + 1];

 	cin>>a[1];
 	bool ok = 0;
 	fr(i, 2, 2*n + 1){
 		cin>>a[i];
 		if(a[i] != a[i - 1]) ok = 1;
 	}
 	if(!ok) return cout<<-1, 0;
 	sort(a + 1, a + n*2 + 1);

 	fr(i, 1, 2*n + 1) cout<<a[i]<<" ";
}