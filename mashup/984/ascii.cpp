#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
ll gcd(int p,int q)
{
	if(q==1||q==0)return p;
	else return gcd(q,p%q);
}

int main()
{
 cout<<gcd(0,10);
}

