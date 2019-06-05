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

 	int s = 0;
 	fr(i, 1, 30000001)
 	{
 		if(i%2 == 0 && i%3 == 0)
 		{
 			s++;
 		}
 		else if(i%2 == 0 && n > 0) n--;
 		else if(i%3 == 0 && m > 0) m--;
 		if(s >= n + m) return cout<<i<<"\n", 0;
 	}
}