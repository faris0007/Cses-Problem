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
const int N=5e5+10;
vii adj;
stack<int> stk;
vector<bool> inStack(N,false);
vector<bool> vis(N,false);
vector<int> dfsNum(N,-1);
vector<int> lowLink(N);
vector<int> comps(N);
int tim = 1;
vip res;
void dfs(int node,ll par) {
    vis[node] = true;
    inStack[node] = true;
    stk.push(node);
    dfsNum[node] = lowLink[node] = tim++;
    for (int nei: adj[node]) {
        if (!vis[nei]) {
            dfs(nei,node);
            lowLink[node] = min(lowLink[node], lowLink[nei]);
        } else if (inStack[nei] && nei!=par)
            lowLink[node] = min(lowLink[node], dfsNum[nei]);
    }
    if (dfsNum[node] == lowLink[node] && par!=0) {
        res.push_back({node,par});
    }
}
void solve(ll hh ) {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i])continue;
        dfs(i, 0);
    }
    cout << res.size() << endl;
    for (auto it: res) {
        cout << it.first << " " << it.second << endl;
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