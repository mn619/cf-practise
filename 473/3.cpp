#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	if(n==2)
	{
		cout<<-1<<endl<<1<<" "<<2<<endl; return 1;
	}
	
	if(n==3)
	{
		cout<<-1<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		return 1;
	}
	
	if(n==4)
	{
		cout<<-1<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<1<<" "<<4<<endl;
		return 1;
	}
	
	if(n==5)
	{
		cout<<-1<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<1<<" "<<4<<endl;
		cout<<1<<" "<<5<<endl;
		return 1;
	}
	
	
	
	cout<<1<<" "<<2<<endl;
	cout<<1<<" "<<3<<endl;
	cout<<2<<" "<<4<<endl;
	cout<<3<<" "<<5<<endl;
		
		
	for(int i=6;i<=n;i++)
	{
	cout<<5<<" "<<i<<endl;	
	}
	
	
	for(int i=2;i<=n;i++)
	{
		cout<<1<<" "<<i<<endl;
	}
	
	
	
}

