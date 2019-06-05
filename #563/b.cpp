#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int a[100001], n;
bool o = 0, e = 0;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1) {
 		cin>>a[i];
 		if(a[i]&1) o = 1;
 		else e = 1;
 	}

 	if(o and e){
 		sort(a + 1, a + n + 1);
 		fr(i, 1, n  + 1) cout<<a[i]<<" ";
 	}
 	else{
 		fr(i, 1, n+ 1) cout<<a[i]<<" ";
 	}


 	
}