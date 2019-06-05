#include<iostream>
using namespace std;

int main()
{
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		if(a[i]>11 || a[i]==3 || a[i]==6 || a[i]==7 || a[i]==9 || a[i]==10 || a[i]==0) {cout<<"YES"<<endl; continue;}
		else cout<<"NO"<<endl;

	}

}

