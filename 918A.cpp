#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n;
	cin >>n;
	bool b=0;
	
	int x=1,y=1;
	int fib[17]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
	
	for(int i=1;i<=n;i++)
	{
		char c='o';
		for(int j=1;j<=16;j++)
		{
			if(fib[j]==i){c='O'; break;}
		}
		cout<<c;
	}
	cout<<endl;
}

