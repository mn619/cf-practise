#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, a[5] = {0};

signed main()
{
	//FILEIO
 	FLASH
	
	cin>>n;
	fr(i,1,n + 1) {int s; cin>>s; a[s]++;}

	int ans = a[4] + min(a[1], a[3]) + a[2]/2;

	int temp = min(a[1], a[3]);
	a[2] %= 2;
	a[1] -= temp;
	a[3] -= temp;

	if(a[1] == 0)
	{
		ans += a[2] + a[3];
	}
	else if(a[3] == 0)
	{
		if(a[2])
		{
			ans++;
			a[1] -= 2;
		}
		if(a[1] > 0) ans += a[1]/4 + (a[1]%4 != 0);
	}

	cout<<ans;
}