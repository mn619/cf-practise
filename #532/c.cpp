#include<bits/stdc++.h>
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);
#define pi 3.141592653589793238462
using namespace std;

signed main()
{
	//FILEIO
 	FAST
 	int las = 4;
 	fr(n,9,10000)
 	{
 		int t = 4*n*n + 1;
 		if(t%65 == 0) {cout<<n - las<<' '<<n<<'\n'; las = n;}
 	}
}