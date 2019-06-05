#include<bits/stdc++.h>
#define int long long
#define pq priority_queue

using namespace std;
int n,a[100001];

void read()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
}

void solve()
{
	int top=n+1;
	pq <int> q;
	for(int i=0;i<n;i++)
	{
		q.push(a[i]);
		while(q.top()==top-1)
		{
			cout<<q.top()<<" ";
			top=q.top();
			q.pop();
		}
		cout<<"\n";
	}
	
}
signed main() {read(),solve();}


/*
 © Copyright 			all rights reserved
     __           __      __       __    	   __	   _
    //\\         //||    //||     //\\        //||    //
   //  \\       // ||   // ||    //  \\      // ||   //
  //----\\     //  ||  //  ||   //----\\    //  ||  //
 //      \\   //   || //   ||  //      \\  //   || //
//        \\ //    ||//    || //        \\//    ||//

*/

