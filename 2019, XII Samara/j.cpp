#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[500001], b[500001], c[500001];
int sum1[500001], sum2[500001], sum3[500001];

int bs1(int x){
	int ans = 0;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r)/2;
		if(sum1[mid] < x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int bs2(int x){
	int ans = 0;
	int l = 1, r = n;

	while(l <= r){
		int mid = (l + r)/2;
		if(sum2[mid] < x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int bs3(int x){
	int ans = 0;
	int l = 1, r = n;

	while(l <= r){
		int mid = (l + r)/2;
		if(sum3[mid] < x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;
	fr(i, 1, n + 1){
		cin>>a[i]>>b[i]>>c[i];
		sum1[i] = b[i] + c[i];
		sum2[i] = c[i] + a[i];
		sum3[i] = b[i] + a[i];
	}

	sort(sum1 + 1, sum1 + n + 1);
	sort(sum2 + 1, sum2 + n + 1);
	sort(sum3 + 1, sum3 + n + 1);

	fr(i, 1, n + 1)
	{
		int ans = 0;
		ans = bs1(a[i] + b[i] + c[i] - 1) - (a[i] > 1);
		ans = max(ans, bs2(a[i] + b[i] + c[i] - 1) - (b[i] > 1));
		ans = max(ans, bs3(a[i] + b[i] + c[i] - 1) - (c[i] > 1));
		cout<<ans<<" ";
	}
}