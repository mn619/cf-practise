#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, l, x, y, a[100001];
map <int, int> m;

void read()
{
	cin>>n>>l>>x>>y;
	fr(i,1,n + 1) {cin>>a[i]; m[a[i]] = i;}
}

int f(int d)
{
	fr(i,1,n + 1)
	{
		if(m.count(a[i] + d)) return i;
	}
	return 0;
}
signed main()
{
	FILEIO
 	FLASH
	read();

	int temp1 = f(x), temp2 = f(y);
	if(temp1 > 0)
	{
		if(temp2 > 0)return cout<<0, 0;
		else return cout<<"1\n"<<y, 0;
	}
	if(temp2 > 0)
	{
		return cout<<"1\n"<<x, 0;
	}

	int temp = f(x + y);
	if(temp > 0)
	{
		return cout<<1<<"\n"<<a[temp] + x, 0;
	}

	fr(i,1,n + 1)
	{
		if(m.count(a[i] + y - x) && a[i] - x >= 0) return cout<<"1\n"<<a[i] - x, 0;
		if(m.count(a[i] + y - x) && a[i] + y <= l) return cout<<"1\n"<<a[i] + y, 0;
	}


	cout<<2<<"\n"<<x<<" "<<y;
	return 0;

}