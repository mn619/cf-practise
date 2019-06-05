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


	signed main()
	{
		FILEIO
	 	//start_routine
		
		int tests = 1,i;
		//cin>>tests;

		priority_queue <int> pq;
		fr(i,1,100000+1)pq.push(-i);
		while(tests--)
		{
			int a, b;
			cin>>a>>b;
			int sum = 0;
			
			int mx = max(a,b), mn = min(a,b);
			int ans1[100001] = {0}, ans2[100001] = {0};


			while(sum<mx)
			{
				if(sum-pq.top() <= mx)
				{
					ans1[-pq.top()] = 1;
					sum+=-pq.top();
					pq.pop();
				}
				else break;
			}

			int rem = mx - sum;
			
			if(rem!=0)
			{
				ans1[-pq.top() - rem] = 0;
				ans1[-pq.top()] = 1;
				int temp = -pq.top()-rem;
				pq.pop();
				pq.push(-temp);
			}	
			
			int x =0, y = 0;
			
			sum = 0;
			while(sum < mn)
			{
				if(sum-pq.top() <= mn)
				{
					ans2[-pq.top()] = 1;
					sum+=-pq.top();
					pq.pop();
				}
				else break;
			}

			fr(i,1,70000)
			{
				x += ans1[i];
				y+=ans2[i];
			}
			if(mx == a && mn == b)
			{
				cout<<x<<'\n';
				fr(i,1,70000+1)
				{
					if(ans1[i] == 1) cout<<i<<" ";
				}

				cout<<"\n"<<y<<'\n';
				fr(i,1,70000+1)
				{
					if(ans2[i] == 1) cout<<i<<" ";
				}
			}
			else
			{
				cout<<y<<'\n';
				fr(i,1,70000+1)
				{
					if(ans2[i] == 1) cout<<i<<" ";
				}

				cout<<"\n"<<x<<'\n';
				fr(i,1,70000+1)
				{
					if(ans1[i] == 1) cout<<i<<" ";
				}
			}
		}

	 	//end_routine
	}
