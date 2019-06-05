#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, a[101];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i,1,n + 1)
 	{
 		cin>>a[i];
 	}

 	sort(a + 1, a + n + 1);
 	deque <int> q;

 	fr(i,1,n +1)
 	{
 		if(i&1) q.push_front(a[i]);
 		else q.push_back(a[i]);
 	}
 	fr(i,1,n + 1)
 	{
 		cout<<q.front()<<" ";
 		q.pop_front();
 	}

}