#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int a[1001]={0};
	int largest=0;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		a[k]++;
		if(a[k]>largest)largest=a[k];
	}
	int ans=0;;
	for(int i=1;i<=1000;i++)
	{
		if(a[i]!=0)ans++;
	}
	
	cout<<largest<<" "<<ans;
}


