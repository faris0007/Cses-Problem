#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e16+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;
const int M = 25;
vii adj;vii dag;
stack<int> stk;vector<bool> inStack(N,false);vector<bool> vis(N,false);
vector<int> dfsNum(N,-1);vector<int> lowLink(N);vector<int> mp(N,0);
vector<int> sums(N,0);int tim = 1;ll inx=1;
vector<int> cost(N,0);
vector<int> inn(N,0);
void dfs(int node) {
    vis[node] = true;
    inStack[node] = true;
    stk.push(node);
    dfsNum[node] = lowLink[node] = tim++;
    for (int nei: adj[node]) {
        if (!vis[nei]) {
            dfs(nei);
            lowLink[node] = min(lowLink[node], lowLink[nei]);
        } else if (inStack[nei])
            lowLink[node] = min(lowLink[node], dfsNum[nei]);
    }
    if (dfsNum[node] == lowLink[node]) {
        vector<int> comp;
        ll acuml = 0;
        while (stk.top() != node) {
            int pop = stk.top();
            stk.pop();inStack[pop] = false;comp.push_back(pop);
            mp[pop] = inx;acuml += cost[pop];
        }
        int pop = stk.top();acuml += cost[pop];stk.pop();
        mp[pop] = inx;sums[inx] = acuml;inStack[pop] = false;
        comp.push_back(pop);inx++;
    }
}
ll fun(ll node,ll par,vi &dp,vi &vis) {
    dp[node] = sums[node];
    ll my = 0;
    for (auto it: dag[node]) {
        if (par == it)continue;
        if (!vis[it]) {
            vis[it]=1;
            fun(it, node, dp, vis);
            my = max(dp[it], my);
        } else {
            my = max(dp[it], my);
        }
    }
    dp[node] += my;
    return dp[node];
}
void solve() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dag.resize(n + 1);
    vi dp(n + 1);
    vi vis2(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (int i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (auto it: adj[i]) {
            if (mp[i] != mp[it]) {
                dag[mp[i]].push_back(mp[it]);
                inn[mp[it]]++;
            }
        }
    }
    ll maxo = 0;
    for (int i = 1; i < inx; ++i) {
        if (!inn[i]) {
            maxo = max(maxo, fun(i, -1, dp, vis2));
        }
    }
    cout << maxo << endl;
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