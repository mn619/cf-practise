#include<bits/stdc++.h>
#define ll long long int

int f(ll n, ll k, int a[])
{
	
}


using namespace std;

int main()
{
	ll n,k;
	cin>>n>>k;
	
	int a[100000]={0};//ao correspond to a power of -16, ai::power of i-16
	ll ab=n, sum=0;
	int count =0;
	for(int i=0;ab!=0;i++)
	{
		if(ab&1){a[count]=i;count++;}
		ab/=2;
	}

	cout<<endl;
	int m=count+1;
	
	for(int i=count;m!=k;i++)
	{
		
	}
}

