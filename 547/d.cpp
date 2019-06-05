#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
string s, t;
int a[26], b[26];	

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>s>>t;

 	int c1 = 0, c2 = 0;
 	fr(i, 0, n)
 	{
 		if(s[i] != '?')
 			a[s[i] - 'a']++;
 		else
 			c1++;
 		if(t[i] != '?') 
 			b[t[i] - 'a']++;
 		else 
 			c2++;
 	}

 	int rem1 = 0, rem2 = 0;

 	int ans = 0;
 	fr(i, 0, 26)
 	{
 		int t = min(a[i], b[i]);
 		ans += t;
 		a[i] -= t;
 		b[i] -= t;
 	}

 	fr(i, 0, 26)
 	{
 		rem1 += a[i];
 		rem2 += b[i];
 	}

 	int t1 = min(c1, rem2);
 	int t2 = min(c2, rem1);
	cout<<c1<<" "<<rem1<<" "<<rem2<<'\n';

	c1 -= t1;
	c2 -= t2;
	ans += t1 + t2 +min(c1,c2);

 	cout<<ans<<'\n';
}