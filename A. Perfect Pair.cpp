#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int x, y, m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>x>>y>>m;

 	if(x >= m|| y >= m) return cout<<0, 0;
 	if(x == 0 && y == 0 && m != 0) return cout<<-1, 0;
 	if(m > 0 && (x <= 0 && y <= 0)) return cout<<-1, 0;
 	if(m == 0 && (x < 0 and y < 0)) return cout<<-1 ,0;
 	if(m < 0){
 		if(x < m and y < m) return cout<<-1 ,0;
 		return cout<<0, 0;
 	}

 	if(x > y) swap(x,y);
 	int ans = (x<0)? (-x)/y + ((-x)%y != 0):0;
 	if(x < 0) x = (x%y + y)%y;
 	bool t = 1;
 	
 	while(x < m && y < m){
 		ans++;
 		if(t) x += y;
 		else y += x;
 		t ^= 1;
 	}

 	cout<<ans;
}