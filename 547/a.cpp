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
 	if(m%n != 0) return cout<<-1, 0;
 	int t = m/n;

 	int a = 0, b = 0;
 	while(t%2 == 0) {a++; t/=2;}
 	while(t%3 == 0) {b++; t/=3;}
	if(t != 1) return cout<<-1, 0;
	cout<<a + b<<'\n';

}