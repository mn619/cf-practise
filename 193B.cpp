#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n+1]={0};
	int b[n+1]={0};
	
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	
	bool bo=1;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=0 && b[i]<3){bo=0;break;	}
	}
	
	if(bo==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

