#include<bits/stdc++.h>
using namespace std;
#define file freopen("/home/aman/Desktop/testing/in", "r", stdin); freopen("/home/aman/Desktop/testing/out", "w", stdout);

int main()
{
	#ifndef ONLINE_JUDGE
	file
	#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n, k;

	cin>>n>>k;
	if(k > n*n) return cout<<-1 ,0;
	int a[n + 1][n + 1] = {{0}};

	int cnt = k;
	for(int i = 1 ; i<=n ;i++)
	{
		for(int j = i; j<=n; j++)
		{
			if(cnt <= 1) break;
			a[i][j] = 1; 
			a[j][i] = 1;
			cnt--;
			if(i != j)cnt--;
		}
		if(cnt <= 1) break;
	}
	

	for(int i =1; i<=n ;i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(cnt && i==j && a[i][j] == 0) {a[i][j] = 1; cnt--;}
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}


}