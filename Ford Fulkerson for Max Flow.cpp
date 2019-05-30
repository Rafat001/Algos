// LightOJ 1153

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1050;
const int INF = (int) 1e9;

struct edge {
    int from, to, f, cap;
};

int n, m;
vector <edge> e;
vector <int> g[MAXN];
bool used[MAXN];
int s, t;
long long ans;

void init() {

    e.clear();
    for(int i=0;i<MAXN;i++)
        g[i].clear();
    memset(used,0,sizeof(used));
    ans=0;
}

void addEdge(int from, int to, int cap) {
    edge ed;

    ed.from = from; ed.to = to; ed.f = 0; ed.cap = cap;
    e.push_back(ed);
    g[from].push_back((int) e.size() - 1);

    ed.from = to; ed.to = from; ed.f = cap; ed.cap = cap;
    e.push_back(ed);
    g[to].push_back((int) e.size() - 1);
}

long long pushFlow(int v, long long flow = INF) {
    used[v] = true;
    if (v == t)
        return flow;

    for (int i = 0; i < (int) g[v].size(); i++) {
        int ind = g[v][i];
        int to = e[ind].to;
        int f = e[ind].f;
        int cap = e[ind].cap;

        if (used[to] || cap - f == 0)
            continue;

        long long pushed = pushFlow(to, min(flow, (long long)cap - f));
        if (pushed > 0) {
            e[ind].f += pushed;
            e[ind ^ 1].f -= pushed;
            return pushed;
        }
    }

    return 0;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++)
    {
        init();
        scanf("%d", &n);
        scanf("%d%d%d",&s,&t,&m);

        for (int i = 1; i <= m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            addEdge(a, b, c);
            addEdge(b, a, c);
        }

        while (true) {

        memset(used, 0, sizeof(used));
        long long add = pushFlow(s);
        if (add == 0)
            break;
        ans += add;

        }
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
