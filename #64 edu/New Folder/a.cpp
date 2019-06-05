#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int a[101];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, ans = 0;
 	cin>>n;
 	cin>>a[1]>>a[2];
 	if(a[1] != 1 && a[2] != 1) return cout<<"Infinite", 0;
 	
 	if(a[1] == 3 || a[2] == 3) ans += 4;
 	else if(a[1] == 2 || a[2] == 2) ans += 3;


	fr(i, 3, n + 1){
		cin>>a[i];
		if(a[i] == 1){
			if(a[i - 1] == 1) return cout<<"Infinite", 0;
			if(a[i - 1] == 2) ans += 3;
			else if(a[i - 1] == 3) ans += 4;
		}
		else if(a[i] == 2){
			if(a[i - 1] != 1) return cout<<"Infinite", 0;
			if(a[i - 2] == 3) ans += 1;
			else ans += 3;
		}
		else{
			if(a[i - 1] != 1) return cout<<"Infinite", 0;
			ans += 4;
		}
	}
	cout<<"Finite\n";
	cout<<ans;
}