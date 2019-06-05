#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	//FILEIO
 	FLASH
	
	int tests = 1;
	cin>>tests;

	while(tests--)
	{
		int k,x;
		cin>>k>>x;
		cout<<9*(k - 1) + x<<'\n';
	}

}