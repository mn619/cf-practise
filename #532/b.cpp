#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n = 7, m =  13exit;


int power(int a,int b, int m)
{
	if (b==0)
	return 1;
	int temp = power(a,b/2,m);
	temp = (temp*temp)%m;
	if (b&1)
	return (temp*(a%m))%m; 
	return temp;
}

int inv(int a, int b)
{
	fr(i,0,b)
	{
		if((i*a)%b == 1) return i; 
	}
}
signed main()
{
	FILEIO
 	FLASH
	
	int t = m*n;
	int y = inv(n,m);
	int z = inv(m,n);
	
	cout<<y<<" "<<z<<'\n';

	fr(i,0,n)
	{
		fr(j,0,m)
		{
			int val = (j*n*y + i*m*z)%t;
			cout<<val<<" ";
		}
		cout<<endl;
	
	}

}