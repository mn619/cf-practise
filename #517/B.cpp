#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int n, a[100011], b[100011], t[100011];
bool check(int n)
{
	int i;
	fr(i,1,n)
		{
			if(b[i] == 3)
			{
				if(t[i] != 3)
				{

					return 0;
				}
				t[i+1] = 3;
			}
			if(b[i] == 2)
			{
				if(a[i] == 2)
				{
					if(t[i] != 2)
					{
						return 0;
					}
					else 
					{
						t[i+1] = 2;
					}
				}
				else if(a[i] == 3)
				{
					if(t[i] == 2)
					{
						t[i+1] = 3;
					}
					else if(t[i] == 3)
					{
						t[i+1] = 2;
					}
					else 
						{
							return 0;
						}
				}
			}
			if(b[i] == 1)
			{
				if(a[i] == 1)
				{
					if(t[i] != 1)
					{
						return 0;
					}
					else t[i+1] = 1;
				}
				else if(a[i] == 3)
				{
					if(t[i] == 1)
					{
						t[i+1] = 3;
					}
					else if(t[i] == 3)
					{
						t[i+1] = 1;
					}
					else 
					{
						return 0;
					}
				}
			}
			if(b[i] == 0)
			{
				if(a[i] == 0)
				{
					if(t[i] != 0)
					{
						return 0;
					}
					else t[i+1] = 0;
				}
				if(a[i] == 1)
				{
					if(t[i] == 0)
					{
						t[i+1] = 1;
					}
					else if(t[i] == 1)
					{
						t[i+1] = 0;
					}
					else 
					{
						return 0;
					}
				}
				if(a[i] == 2)
				{
					if(t[i] == 0)
					{
						t[i+1] = 2;
					}
					else if(t[i] == 2)
					{
						t[i+1] = 0;
					}
					else 
					{
						return 0;
					}
				}
				if(a[i] == 3)
				{
					if(t[i] == 0)
					{
						t[i+1] = 3;
					}
					else if(t[i] == 1)
					{
						t[i+1] = 2;
					}
					else if(t[i] == 2)
					{
						t[i+1] = 1;
					}
					else if(t[i] == 3)
					{
						t[i+1] = 0;
					}
				}
			}
		}
		fr(i,1,n)
		{
			if(a[i] != (t[i]|t[i+1])) return 0;
			if(b[i] != (t[i]&t[i+1])) return 0;
		}
		return 1;
}
signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		cin>>n;
		int i;
		fr(i,1,n)
		{
			cin>>a[i];
		}

		fr(i,1,n)
		{
			cin>>b[i];
		}

		fr(i,1,n)
		{
			if(b[i] == 3)
			{
				if(a[i]!=3)
				{
					return cout<<"NO\n",0;
				}
			}
			if(b[i] == 2)
			{
				if(a[i] != 2 && a[i]!=3)
				{
					cout<<"NO\n";
					return 0;
				}
			}
			if(b[i] == 1)
			{
				if(a[i] == 2 || a[i] ==	 0)
				{
					cout<<"NO\n"; return 0;
				}
			}
		}
		
		t[1] = 0;
		if(check(n))
		{
			cout<<"YES\n";
			fr(i,1,n+1)
			{
				cout<<t[i]<<" ";
			}
			return 0;
		}
		t[1] = 1;
		if(check(n))
		{
			cout<<"YES\n";
			fr(i,1,n+1)
			{
				cout<<t[i]<<" ";
			}
			return 0;
		}
		t[1] = 2;
		if(check(n))
		{
			cout<<"YES\n";
			fr(i,1,n+1)
			{
				cout<<t[i]<<" ";
			}
			return 0;
		}
		
		t[1] = 3;
		if(check(n))
		{
			cout<<"YES\n";
			fr(i,1,n+1)
			{
				cout<<t[i]<<" ";
			}
			return 0;
		}
		cout<<"NO\n";
		return 0;
	}

 	//end_routine
}
