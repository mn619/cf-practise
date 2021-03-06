#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

const int C=26;
const int maxn = 300005;

struct SAM{int len; SAM *child[C],*back; int ans = 0, cnt = 0; bool vis = 0; } *root,*tail,*p,*q,*w,*v;
int N,a[maxn];char st[maxn];
int cnt[26], f[200001] = {0};
string s;

map <pair<int, int>, int> ans;


void dfs(SAM *node){
	if(node->vis) return;
	node->vis = 1;
	node -> ans = 1;

	for(int i = 0; i < 26; i++){
		if(node->child[i] != 0){
			dfs(node->child[i]);
			node -> ans += node -> child[i] -> ans;
		}
	}
}

void compute(SAM *node, int depth){
	ans[{depth, node->ans}]++;
	for(int i = 0; i < 26; i++){
		if(node->child[i] != 0){
			compute(node->child[i], depth + 1);
		}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif

 	FLASH
 	cin>>s;

 	N = s.size();
 	for(int i = 0; i < N; i++){
 		a[i + 1] = s[i] - 'a';
 	}

 	root=new SAM,root->back=0,root->len=0,tail=root;
 	for (int i=0;i<C;i++) root->child[i]=0;
	
	for (int t=1;t<=N;t++){
	    p=new SAM,p->len=tail->len+1;
	    for (int i=0;i<C;i++) p->child[i]=0;
	    tail->child[a[t]]=p,v=tail->back,tail=p;
	    while ((v!=0)&&(v->child[a[t]]==0)) v->child[a[t]]=p,v=v->back;
	    if (v==0) p->back=root; 
	    else{
	    	if (v->len+1==v->child[a[t]]->len)
	        p->back=v->child[a[t]];
	    	else{
		        q=v->child[a[t]],w=new SAM,w->back=q->back;
		        for (int i=0;i<C;i++) w->child[i]=q->child[i];
		        w->len=v->len+1,p->back=q->back=w;
		        while ((v!=0)&&(v->child[a[t]]==q)) v->child[a[t]]=w,v=v->back;
	     	}
	    }
	}
 	
 	dfs(root);
 	compute(root, 0);

 	int q;

  	cin>>q;

  	for(auto x: ans){
  		cout<<x.first.first<<" "<<x.first.second<<"\n";
  	}

  	while(q--){
  		int l, p;
  		cin>>l>>p;
  		cout<<ans[{l, p}]<<"\n";
  	}
}