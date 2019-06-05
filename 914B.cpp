#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int n;
	cin>>n;
	int t;
	int b[100001]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		b[t]++;
	}
	bool c=0;
	for(int i=1;i<=100000;i++)
	{
		if(b[i]!=0 && b[i]%2==1) {c=1; break;}
	}
	
	if(c==0) cout<<"Agasa\n";
	else cout<<"Conan\n";
}

