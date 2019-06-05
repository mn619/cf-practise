#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, x[100001], h[100001];
bool ok[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	ok[1] = 1;
 	fr(i, 1, n + 1){
 		cin>>x[i]>>h[i];
 	}

 	fr(i, 2, n + 1){
 		if(x[i] - x[i - 1] + 1 >= h[i] + h[i - 1] + 2) {ok[i] = ok[i - 1] = 1; continue;}
 		else if(!ok[i - 1] and x[i] > x[i - 1] + h[i - 1]){ok[i - 1] = 1;}
 		else if(x[i] - h[i] > x[i - 1]) ok[i] = 1;
 	}
 	ok[n] = 1;
 	int ans = 0;
 	fr(i, 1, n +  1) ans += ok[i];
 	cout<<ans;
}