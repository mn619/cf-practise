#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n,k,A,B, a[100001] = {0}, pre[100001];

int find(int l, int r)
{
	int l1 = 1, r1 = k;
	int x = k + 100,y = -k - 100;

	while(l1 <= r1)
	{
		int mid = (l1 + r1)/2;
		if(a[mid] >= l)
		{
			x = mid;
			r1 = mid - 1;
		}
		else
		{
			l1 = mid + 1;
		}
	}

	l1 = 1, r1 = k;

	while(l1 <= r1)
	{
		int mid = (l1 + r1)/2;
		if(a[mid] <= r)
		{
			y = mid;
			l1 = mid + 1;
		}
		else
		{
			r1 = mid - 1;
		}
	}

	return max((int) 0, y - x + 1);
}


int solve(int l, int r)
{
	int cnt = find(l,r);
	if(cnt == 0) return A;
	if(r == l) return B*cnt;
	int mid = (l + r)/2;
	return min(B*cnt*(r - l + 1), solve(l, mid) +  solve(mid + 1, r));
}

signed main()
{
	FILEIO
 	FLASH

 	cin>>n>>k>>A>>B;
 	n = (1<<n);

 	fr(i,1,k + 1)

 	{
 		cin>>a[i];
 	}

 	sort(a + 1, a + k + 1);
 	int ans = 0;
 	cout<<solve(1,n);
}