#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	float ans=100000000000000;
	int a,b;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		float k=1.0*m*a/b;
		if(k<ans) ans=k;	
	}
	cout<<setprecision(20)<<ans<<endl;
		

}



