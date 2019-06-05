#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a,b, h[2001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>a>>b;

 	fr(i,1, n + 1){
 		cin>>h[i];
 	}

 	sort(h + 1, h + n + 1);
 	reverse(h + 1, h + n+ 1);

 	int l = h[a], r =  h[a + 1];
 	cout<<abs(l - r);
 }