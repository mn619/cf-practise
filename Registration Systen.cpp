#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
int n;


int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 	cin>>n;
 	string s;
 	
 	map<string,int> m;
 	
 	for(int i=0;i<n;i++)
 	{
 		cin>>s;
 		if(m[s])
 		{
 			cout<<s<<m[s]<<"\n";
 			m[s]++;
		}
		
		else
		{
			cout<<"OK\n";
			m[s]=1;
		}
	}
	
	
}


