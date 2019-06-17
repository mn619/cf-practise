#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;


bool bs(ll a[],ll k, int l,int r)
{
	int mid=(l+r)/2;
	if(a[mid]==k)return true;
	if(r-l<=0)return false;
	
	if(k<a[mid])return bs(a,k,l,mid-1);
	return bs(a,k,mid+1,r);
}


int main()
{//p*(s[0]-'a'+1)
 char c='<';
 cout<<int(c-'a'+1)*101;
}

