#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,ans=1000000000;
	cin>>n;
	
	char a[5][n+1][n+1];
	
	
	for(int k=1;k<=4;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[k][i][j];
			}
		}
	}
	
	
	for(int i=1;i<=4;i++)
	{
		for(int j=i+1;j<=4;j++)
		{
			int count =0;
			
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=n;l++)
				{
					if((k+l)%2==0 && a[i][k][l]=='0') count++;
					if((k+l)%2 && a[i][k][l]=='1')count++;
					
					if((k+l)%2==0 && a[j][k][l]=='0') count++;
					if((k+l)%2 && a[j][k][l]=='1')count++;
				}
			}
			//cout<<count<<"\n\n";
			int p,q;
			if(i==1 && j==2){p=3; q=4;};
			if(i==1 && j==3){p=2; q=4;};
			if(i==1 && j==4){p=2; q=3;};
			if(i==2 && j==3){p=1; q=4;};
			if(i==2 && j==4){p=1; q=3;};
			if(i==3 && j==4){p=1; q=2;};
			
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=n;l++)
				{
					if((k+l)%2==0 && a[p][k][l]=='1') count++;
					if((k+l)%2 && a[p][k][l]=='0')count++;
					
					if((k+l)%2==0 && a[q][k][l]=='1') count++;
					if((k+l)%2 && a[q][k][l]=='0')count++;
				}
			}
			
			//cout<<i<<" "<<j<<" "<<count<<endl;
			if(ans>count)ans=count;
						
		}
	}
	
	cout<<ans;
}

