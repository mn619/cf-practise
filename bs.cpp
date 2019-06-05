#include<iostream>
using namespace std;

int bs(int x,int l, int r, int a[])
{
	int m=(l+r)/2;
	cout<<a[m]<<endl;
	if(a[m]==x) return m;
	
	if(l-r==0) return 0;
	
	if(a[m]>x)return bs(x,l,m-1,a);
	if(a[m]<x)return bs(x,m+1,(r),a);
	
}

int main()
{
	
	int a[10]={1,2,3,7,11,64,72,89,91,100};
	
	cout<<bs(1,0,9,a);
	
}
