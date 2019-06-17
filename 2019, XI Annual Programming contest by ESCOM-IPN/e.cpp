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

 	int n, x, day;
 	string firstday;
 	cin>>n>>firstday>>x;

 	if(firstday == "Monday") day = 1;
 	else if(firstday == "Tuesday") day = 2;
 	else if(firstday == "Wednesday") day = 3;
 	else if(firstday == "Thursday") day = 4;
 	else if(firstday == "Friday") day = 5;
 	else if(firstday == "Saturday") day = 6;
 	else day = 0;

 	int ans = 0;

 	fr(i, 1, n + 1){
 		int a;
 		cin>>a;
 		if(a >= x and day != 0 and day != 6) ans++;
 		day++;
 		if(day == 7) day = 0;
 	}

 	cout<<ans;

}