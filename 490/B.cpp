#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n;
string s;

void rev(int i)
{
	stack <char> c;
	int j;
	for(j=0;j<i;j++) c.push(s[j]);
	
	for(j=0;j<i;j++) {s[j]=c.top();c.pop();}	
}

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>s;
	
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			rev(i);
		}
	}
	
	cout<<s<<"\n";
}



