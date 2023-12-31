#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=2e5+10;

struct FlowEdge {
    int v, u;ll cap, flow = 0;FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};
struct Dinic {
    const ll FLOW_INF = 1e18;
    int n, m = 0, s, t;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m++);   //// instead of has two construction we will
        adj[v].push_back(m++);   /// has a graph in edges and pointer from node to thier nei in adj
    }
    ///// this bfs make as pavin said each time check if there is a path to t  which is shortest layerd graph
    ////  at second time get path has length increased
    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id: adj[v]) {
                if (edges[id].cap - edges[id].flow < 1) continue;////// to make layerd and should be layerd
                if (level[edges[id].u] != -1) continue; //// to get shortest
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;   ///// there is a path
    }
    ll dfs(int v, ll pushed) {
        if (pushed == 0) return 0;  ///// to terminate
        if (v == t) return pushed;      //// finish
        ///// here cid is a pointer when cid++ ptr inc
        for (int &cid = ptr[v]; cid < (int) adj[v].size(); cid++) {
            ///// id is the place of nei or edge in edges
            int id = adj[v][cid], u = edges[id].u; //// u my nei
            ////////fir cond to check is in my layerd and shortest - sec is can flow
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) continue;
            ///// get min in path and do changes in path in front me
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;//// if no path cid++ and vis this nei no check again
            edges[id].flow += tr;           //// do change     here no minus but inc flow val which subtract
            edges[id ^ 1].flow -= tr;       //// inc reverse edge
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1); /// new layerd
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(),0);   ///// this is imp to make as a vis array to not to check nei already failed
            while (ll pushed = dfs(s, FLOW_INF)) f += pushed; //// to get all paths in layerd when fail make new layered
        }
        return f;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    Dinic dinic(n + 1, 1, n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dinic.addEdge(u, v, w);
    }
    cout << dinic.flow() << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
   //  cin >> t;
    while (t--) {
        solve();
    }
}