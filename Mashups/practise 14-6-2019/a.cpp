#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, l[100001], r[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	int a = 0, b = 0, ans = 0, ansind = 0;
 	fr(i, 1, n+  1){
 		cin>>l[i]>>r[i];
 		a += l[i];
 		b += r[i]; 
 	}
	 
	ans = abs(a - b);

	fr(i, 1, n  + 1){
		int a1 = a - l[i] + r[i];
		int b1 = b - r[i] + l[i];
		if(ans < abs(a1 - b1)){
			ansind = i;
			ans = abs(a1 - b1);
		}
	}

	cout<<ansind;
}
