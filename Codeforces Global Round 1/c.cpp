#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
int powr[30] = {1};
int val[30] = {0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401,67108863,22369621,19173961};

int logf(int x)
{
	fr(i,1,30)
	{
		if(powr[i + 1] > x) return i;
	}
	return 30; 
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;
 	int p = 1;
 	fr(i,1,30)
 	{
 		p *= 2;
 		powr[i] = p;
 	}

 	int a;

 	while(q--)
 	{
 		cin>>a;
 		int len = logf(a);
 		if(powr[len + 1] - 1 != a) cout<<powr[len + 1] - 1<<'\n';
 		else
 		{
 			cout<<val[len]<<'\n';
 		}
 	}



}