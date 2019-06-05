#include<bits/stdc++.h>
using namespace std;
#define pb push_back

#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);


int a, b;

int main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin>>a>>b;
	if(a > b) swap(a, b);

	int s = a + b;
	int k = 0;
	while(k*(k + 1) <= 2*s) k++;

	k--;
	vector <int> v1, v2;
	int cur = 1, used = 0;
	while(used  + cur <= a){
		v1.pb(cur);
		used += cur;
		cur++;
	}
	
	used = 0;
	while(used + cur <= b){
		v2.pb(cur);
		used += cur;
		cur++;
	}


	cout<<v1.size()<<'\n';
	for(auto x: v1){
		cout<<x<<" ";
	}

	cout<<endl;
	cout<<v2.size()<<'\n';
	for(auto x: v2){
		cout<<x<<" ";
	}


}