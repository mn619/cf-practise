#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
string s;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s;
	int e=0,o=0,a[4]={0};
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a')i%2?a[1]++:a[0]++;
		else i%2?a[3]++:a[2]++;
		
		if(i%2)
		{
			s[i]=='a'?e+=a[0],o+=a[1]:1;
			s[i]=='b'?e+=a[2],o+=a[3]:1;
		}
		else
		{
			s[i]=='a'?o+=a[0],e+=a[1]:1;
			s[i]=='b'?o+=a[2],e+=a[3]:1;
		}
	}
	cout<<e<<" "<<o;
}



