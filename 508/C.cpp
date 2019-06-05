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

using namespace std;
signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

 	int n,i;
 	cin>>n;
 	int a[n+1], b[n+1];
 	priority_queue <int> A,B;
 	fr(i,1,n+1)
 	{
 		cin>>a[i];
 		A.push(a[i]);
 	}

 	fr(i,1,n+1)
 	{
 		cin>>b[i];
 		B.push(b[i]);
 	}
 	int x = 0, y = 0;
 	 i = 1;
 	while(!(A.empty()) || !(B.empty()))
 	{
 		if(i%2)
 		{
 			if(A.empty())
 			{
 				B.pop();
 			}
 			else
 			{
 				if(B.empty())
 				{
 					x+=A.top();
 					A.pop();
 				}
 				else
 				{
 					int temp1 = A.top(), temp2 = B.top();
 					if(temp1 >= temp2)
 					{
 						x+=temp1;
 						A.pop();
 					}
 					else
 					{
 						B.pop();
 					}
 				}
 			}
 		}
 		else
 		{
 			if(B.empty())
 			{
 				A.pop();
 			}
 			else
 			{
 				if(A.empty())
 				{
 					y+=B.top();
 					B.pop();
 				}
 				else
 				{
 					int temp1 = A.top(), temp2 = B.top();
 					if(temp2 >= temp1)
 					{
 						y+=temp2;
 						B.pop();
 					}
 					else
 					{
 						A.pop();
 					}
 				}
 			}
 		}
 		i++;
 	}
 	cout<<x-y<<"\n";	

 	//end_routine
}



