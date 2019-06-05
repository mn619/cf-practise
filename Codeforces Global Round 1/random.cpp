#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
	int n = 25;
	fr(i,1,n + 1)
	{
		string s;
		cin>>s;
		cout<<s<<",";
	}
	cout<<" oeis";


}