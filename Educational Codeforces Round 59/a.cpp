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
	FILEIO
 	FLASH
	
	int tests = 1;
	cin>>tests;

	while(tests--)
	{
		string s;
		int n;
		cin>>n;
		cin>>s;
		if(s.size() == 2)
		{
			int z = s[0] - '0', o = s[1] - '0';
			if(z < o)
			{
					cout<<"YES\n"<<2<<'\n'<<z<<" "<<o<<"\n";
			}
			else cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n"<<2<<'\n';
			cout<<s[0]<<" ";
			fr(i,1,s.size())cout<<s[i];
			cout<<endl;
		}
	}

}