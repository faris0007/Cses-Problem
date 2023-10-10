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
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=2e5+10;
///// Agamista
vii adj;
stack<int> stk;
vector<bool> inStack(N,false);
vector<bool> vis2(N,false);
vector<int> dfsNum(N,-1);
vector<int> lowLink(N);
int cc=0;
int tim2 = 1;
void dfs(int node) {
    vis2[node] = true;
    inStack[node] = true;
    stk.push(node);
    dfsNum[node] = lowLink[node] = tim2++;
    for (int nei: adj[node]) {
        if (!vis2[nei]) {
            dfs(nei);
            lowLink[node] = min(lowLink[node], lowLink[nei]);
        } else if (inStack[nei])
            lowLink[node] = min(lowLink[node], dfsNum[nei]);
    }
    if (dfsNum[node] == lowLink[node]) {
        cc++;
        while (stk.top() != node) {
            int pop = stk.top();
            stk.pop();
            inStack[pop] = false;
        }
        int pop = stk.top();
        stk.pop();
        inStack[pop] = false;
    }
}

/////////////////
ll tim=0;
vi dfsn(N);
vi used(N,0);
void dfs2(ll node,vi &vis,viip &adj2) {
    if (vis[node])return;
    vis[node] = 1;
    dfsn[node] = tim++;
    for (auto ch: adj2[node]) {
        ll it = ch.first;
        if (!vis[it]) {
            used[ch.second] = 1;
            dfs2(it, vis, adj2);
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    viip adj2(n + 1);
    vi vis(n + 1, 0);
    vip edges;
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj2[u].push_back({v, i});
        adj2[v].push_back({u, i});
        edges.push_back({u, v});
    }
    for (int i = 1; i <= n; ++i) {
        dfs2(i, vis, adj2);
    }
    for (int i = 0; i < edges.size(); ++i) {
        pi it = edges[i];
        if (used[i]) {
            if (dfsn[it.first] > dfsn[it.second]) {
                swap(it.first, it.second);
            }
        } else {
            if (dfsn[it.first] <= dfsn[it.second])swap(it.first, it.second);
        }
        edges[i] = it;
    }
    for (auto it: edges) {
        ll u = it.first;
        ll v = it.second;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if(!vis2[i])
        dfs(i);
    }
    if (cc > 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (auto it: edges) {
        cout << it.first << " " << it.second << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    //   cin >> tc;
    while (tc--) {
        solve();
    }
}