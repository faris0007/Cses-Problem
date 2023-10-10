#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e18+5
#define MOD ll(1e9+7)
//#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=5e4+10;
vii adj,dag;
stack<int> stk;
vector<bool> inStack(N,false);
vector<bool> vis(N,false);
vector<int> dfsNum(N,-1);
vector<int> lowLink(N);
vector<int> comps(N);
vi res,visdag;
int cc=0;
int tim = 1;
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
        cc++;
        while (stk.top() != node) {
            int pop = stk.top();
            stk.pop();
            inStack[pop] = false;
            comps[pop] = cc;
        }
        int pop = stk.top();
        stk.pop();
        inStack[pop] = false;
        comps[pop] = cc;
    }
}

void toplogical(ll node,ll par) {
    for (auto ch: dag[node]) {
        if (ch != par && !visdag[ch]) {
            visdag[ch] = 1;
            toplogical(ch, node);
        }
    }
    res.push_back(node);
}
void solve(ll hh ) {
    ll n, m, q;
    cin >> n >> m >> q;
    adj.resize(n + 1);
    dag.resize(n + 1);
    vector<bitset<N>> dp(N + 1);
    visdag.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i])continue;
        dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (auto ch: adj[i]) {
            if (comps[ch] != comps[i]) {
                dag[comps[i]].push_back(comps[ch]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!visdag[i]) {
            visdag[i] = 1;
            toplogical(i, 0);
        }
    }
    for (auto s: res) {
        dp[s][s] = 1;
        for (auto it: dag[s]) {
            dp[s] |= dp[it];
        }
    }
    for (int i = 0; i < q; ++i) {
        ll u, v;
        cin >> u >> v;
        if (dp[comps[u]][comps[v]]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
//    cin >> t;
    cout << fixed << setprecision(9);
    ll h = 1;
    while (t--) {
        solve(h++);
    }
}