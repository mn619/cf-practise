#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

string a, b;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>a>>b;
 	int n = a.size();
 	if(b.size() != n) return cout<<"NO", 0;

	bool ok1 = 0, ok2 = 0;

	fr(i, 0, n){
		if(a[i] == '1') ok1 = 1;
	}
	fr(i, 0, n){
		if(b[i] == '1') ok2 = 1;
	}

	ok1 == ok2? cout<<"YES": cout<<"NO";
}