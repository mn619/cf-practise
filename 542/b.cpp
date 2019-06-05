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
 	int n;
 	cin>>n;
 	int a[2*n + 1];
 	map <int, int> m1, m2;

 	fr(i,1,2*n + 1)

 	{
 		cin>>a[i];
 		if(m1.count(a[i])) m2[a[i]] = i;
 		else m1[a[i]] = i;
 	}
 	m1[0] = m2[0] = 1;

 	int d1 = 0, d2 = 0;

 	int las1 = 1, las2 = 1;
 	fr(i,1,n + 1)
 	{
 		if(las1 <= las2)
 		{
 			d1 += abs(min(m1[i], m2[i]) - las1);
 			d2 += abs(max(m1[i], m2[i]) - las2);

 			las1 = min(m1[i], m2[i]);
 			las2 =max(m1[i], m2[i]);
  		}
  		else 
  		{
  			d2 += abs(min(m1[i], m2[i]) - las2);
 			d1 += abs(max(m1[i], m2[i]) - las1);

 			las2 = min(m1[i], m2[i]);
 			las1 =max(m1[i], m2[i]);
  		}

  		//cout<<d1<<" "<<d2<<'\n';
 	}
 	cout<<d1 + d2<<'\n';
 

}