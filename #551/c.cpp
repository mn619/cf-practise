#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


bool check(string s){
	int n = s.size();
	int cnt = 0;
	fr(i, 0, n){
		if(s[i] == '(') cnt++;
		else cnt--;
		if(i != n - 1)
		if(cnt <= 0) return 0;
	}
	return (cnt == 0);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;
 	if(n&1) return cout<<":(", 0;
 	string s;
 	cin>>s;

 	deque <int> q;
 	queue <int> qq;

 	if(s[0] == ')' || s[n - 1] == '(') return cout<<":(", 0;
 	string ans = s;
 	ans[0] = '(';
 	ans[n - 1] = ')';

 	fr(i, 1, n - 1){
 		if(s[i] == '(') qq.push(i);
 		if(s[i] == ')')
 		{
 			if(qq.empty() && q.empty()) return cout<<":(", 0;
			else if(!qq.empty()) {ans[qq.front()] = '('; qq.pop();}
			else if(!q.empty()) {ans[q.front()] = '('; q.pop_front();}
		}
 		if(s[i] == '?'){
 			q.push_back(i);
 		}
 	}

 	bool b = 0;
 	
 	while(!qq.empty()){
 		q.push_front(qq.front());
 		qq.pop();
 	}

 	while(!q.empty()){
 		ans[q.back()] = ')';
 		ans[q.front()] = '(';
 		q.pop_front();
 		q.pop_back();
 	}

 	if(check(ans)) cout<<ans;
 	else cout<<":(";
}