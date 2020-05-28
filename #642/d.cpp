#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[200001];
void solv(){
	cin>>n;

	priority_queue<pair<int, int>> pq;
	pq.push({n, -1});

	int i = 1;
	while(!pq.empty()){
		int len = pq.top().first, ind = -pq.top().second;
		pq.pop();
		int l = ind, r = ind + len - 1;
		int mid = (l + r)/2;
		a[mid] = i;
		if(l <= mid - 1)
			pq.push({mid - 1 - l + 1, -l});
		
		if(r >= mid + 1)
			pq.push({r - (mid + 1) + 1, - mid - 1});
		i++;
	}

	for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
		cout<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;

    while(t--) solv();
}