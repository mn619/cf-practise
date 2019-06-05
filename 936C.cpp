#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

void f(char s[],char t[],int n,int set, vector <int> v)
{
	int b;
	for(int i=n;i>=1;i--)
	{
		if(t[i]==s[set]) {b=i; break;}
	}

	v.pb(n);
	


}

int main()
{
	//cout<<'a'-97<<"\n"<<'b'-97;
	int n;
	cin>>n;
	char s[n],t[n];
	int as[26]={0},ts[26]={0};
	cin>>s>>t;
	

	
}

