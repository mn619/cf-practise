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
	
 	int n, k;
 	cin>>n>>k;
 	int a[n + 1];
 	string s;
 	fr(i,0,n) cin>>a[i];
 	cin>>s;
 	int ans = 0;
 	vector <int> v;
 	v.pb(a[0]);
 	fr(i,1,n)
 	{
 		if(s[i] == s[i - 1])
 		{
 			v.pb(a[i]);
 		}
 		else
 		{
 			sort(v.begin(), v.end());
 			reverse(v.begin(), v.end());
 			fr(j,0,min(k, (int)v.size()))
 			{
 				ans+=v[j];
 			}
 			v.clear();
 			v.pb(a[i]);	
 		}
 	}
 	sort(v.begin(), v.end());
 	reverse(v.begin(), v.end());
 	fr(j,0,min(k,(int)v.size())) ans += v[j];

 	cout<<ans<<'\n';
}
