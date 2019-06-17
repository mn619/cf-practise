#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001];
vector<pair<int ,int>> pos, neg, zer;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;

	fr(i, 1, n + 1) {
		cin>>a[i];
		if(a[i] > 0){
			pos.pb({a[i], i});
		}
		else if(a[i] < 0)neg.pb({-a[i], i});
		else zer.pb({0, i});
	}


	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	int lp = pos.size(), ln = neg.size();

	int ok = (ln&1);
	

	int p0 = zer.size(), p2 = pos.size(), p1 = neg.size();
	p0--;
	p1--;
	p2--;

	while(p0 > 0){
		cout<<"1 "<<zer[p0].second<<" "<<zer[p0 - 1].second<<'\n';
		p0--;
	}

	while(p2 > 0){
		cout<<"1 "<<pos[p2].second<<" "<<pos[p2 -1].second<<'\n';
		p2--;
	}

	while(p1 > ok){
		cout<<"1 "<<neg[p1].second<<" "<<neg[p1 -1].second<<'\n';
		p1--;
	}
	
	if((neg.size() > 1) and !pos.empty() ){
		cout<<"1 "<<pos[0].second<<" "<<neg[ok].second<<'\n';
	}

	if(!zer.empty()){
		if(ok){
			cout<<"1 "<<zer[p0].second<<' '<<neg[0].second<<'\n';
			if(pos.size() > 0 || neg.size() > 1) cout<<"2 "<<neg[0].second<<'\n';
		}
		else if(zer.size() != n)cout<<"2 "<<zer[0].second<<'\n';
	}

	else if(ok){
		cout<<"2 "<<neg[0].second<<"\n";
	}

}