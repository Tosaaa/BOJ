#include <bits/stdc++.h>
#define eb emplace_back
#define all(V) (V).begin(),(V).end()
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ=4e2+5;
struct edge
{
	int to, flow, rev;
	edge() {}
	edge(int to,int flow,int rev):to(to),flow(flow),rev(rev) {}
};
int n, m, ans, res;
int ch[SZ], lev[SZ], w[SZ];
vector<edge> v[SZ];
void make_edge(int x, int y)
{
	v[x].eb(y,1,v[y].size());
	v[y].eb(x,0,v[x].size()-1);
}
void bfs(int s)
{
	queue<int> q;
	q.emplace(s);
	lev[s]=1;
	while (q.size()) {
		int now=q.front();
		q.pop();
		for (auto c:v[now]) {
			if (!c.flow||lev[c.to]) continue;
			lev[c.to]=lev[now]+1;
			q.emplace(c.to);
		}
	}
}
void dfs(int now, int maxflow)
{
	ch[now]=1;
	if (now==n) {
		res=maxflow;
		ans+=maxflow;
		return;
	}
	for (int &i=w[now]; i<v[now].size(); i++) {
		edge c=v[now][i];
		if (!c.flow||lev[c.to]-lev[now]!=1||ch[c.to]) continue;
		dfs(c.to,min(maxflow,c.flow));
		if (res) {
			v[now][i].flow-=res;
			v[c.to][c.rev].flow+=res;
			return;
		}
	}
}
int main()
{
	int i, a, b;
	scanf("%d %d", &n, &m);
	for (i=1; i<=n; i++) {
		scanf("%d", &a);
		make_edge(1,i+1);
		for (int j=1; j<=a; j++) {
			scanf("%d", &b);
			make_edge(i+1,n+b+1);
		}
	}
	for (i=1; i<=m; i++) make_edge(n+i+1,n+m+2);
	n+=m+2;
	while (1) {
		fill(lev+1,lev+n+1,0);
		bfs(1);
		if (!lev[n]) break;
		fill(w+1,w+n+1,0);
		fill(ch+1,ch+n+1,0);
		res=0;
		dfs(1,1<<30);
	}
	printf("%d\n", ans);
	return 0;
}