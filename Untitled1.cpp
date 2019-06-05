#include<bits/stdc++.h>
using namespace std;

int f(int d,int a[], int b[],int ans[])
{
	if(d==1)
	{
		if(a[0]<=b[0]) {ans[0]=b[0]; return 1;}
		else return 0;
	}
	
	sort(a,a+d);
	for(int i=d-1;i>=0;i--)
	{
		if(a[i]<b[i])ans[i]=a[i];
		if(a[i]==b[i])
		{
			
		}
		else return 0;
	}
}

int main()
{
	long long int a,b;
	cin>>a>>b;
	int da=log10(a)+1,db=log10(b)+1;
	cout<<da<<"\n"<<db<<"\n\n";
	int x[da]={0},y[db]={0};
	long long int n=a,m=b;
	
	for(int i=0;n!=0;i++)
	{
		x[i]=n%10;
		n=n/10;
		cout<<x[i];
	}
	
	cout<<endl;
	
	for(int i=0;m!=0;i++)
	{
		y[i]=m%10;
		m=m/10;
		cout<<y[i];
	}
	
	cout<<"\n\n";
	int ans[da];
	
	f(da,x,y,ans);
	
	for(int i=da-1;i>=0;i--)
	{
		cout<<ans[i]<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
}
