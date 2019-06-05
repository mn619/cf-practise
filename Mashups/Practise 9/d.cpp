#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s;
int ans[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s;
 	int l = s.size();
 	stack <int> st;
 	deque <int> q;

 	for(int i = l; i >=0; i--){
 		if(s[i] == '('){
 			if(st.empty() and q.empty()) return cout<<-1, 0;
 			if(st.empty()){
 				ans[q.front()]++;
 				q.push_back(q.front());
 				q.pop_front();
 			}
 			else{
 				st.pop();
 			}
 		}
 		else if(s[i] == ')') st.push(i);
 		else if(s[i] == '#') q.push_front(i);
 	}
 
 	fr(i, 0, l){
 		if(s[i] == '#' and ans[i] == 0) return cout<<-1, 0;
 	}

 	fr(i, 0, l) if(s[i] == '#') cout<<ans[i]<<'\n';

}