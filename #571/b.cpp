#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>m;

 	if(n > m) swap(n, m);
 	
 	if(n == 1){
 		cout<<m/3 + (m%3 == 2);
 		return 0;
 	}
 	if(n == 2 and m > 2){
 		cout<<m/2 + (m&1);
 		return 0;
	}

 	int a = n/3 + (n%3 == 2), b = m/2 + (m&1);
 	int ans1 = (a*b);
 	if(n%3 == 1)
 		ans1 += (m/3 + (m%3 == 2));

 	a = n/2 + (n&1);
 	b = m/3 + (m%3 == 2);

 	int ans2 = a*b;
 	if(m%3 == 1){
 		ans2 += (n/3 + (n%3 == 2));
 	}
 	
 	cout<<max(ans2, ans1);
 }