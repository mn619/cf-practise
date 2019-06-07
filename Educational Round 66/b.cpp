#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int l;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	
 	int maxn =1;
 	fr(i, 1, 33) maxn *= 2;
 	maxn--;

 	cin>>l;

 	stack <pair<int ,int>> s;
 	s.push({1, 0});
 	
 	fr(i, 1, l + 1){
 		string cm;
 		cin>>cm;
 		if(cm == "for"){
 			int t;
 			cin>>t;
 			s.push({t, 0});
 		}
 		else if(cm == "add"){
 			auto x = s.top();
 			s.pop();
 			x.second += x.first;
 			s.push(x);
 		}	
 		else{
 			auto x = s.top();
 			s.pop();
 			s.top().second += x.second*s.top().first;
 		}
 		if(s.top().second >  maxn) return cout<<"OVERFLOW!!!", 0;
 	}
 	
 	assert(s.size() == 1);

	if(s.top().second >  maxn) return cout<<"OVERFLOW!!!", 0;
	cout<<s.top().second;
}