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
ll add(ll a, ll b) {
    return ((a % MOD + b % MOD) + MOD) % MOD;
}
struct info {
    ll mx = -oo, mn = oo, nm = 0;
};
ll n,m;
viip adj;
vii dag;
vi dis;
vector<info> dp;
void dij(ll node) {
    priority_queue<pi> q;
    q.push({0, node});
    dis[node] = 0;
    while (q.size()) {
        pi now = q.top();
        q.pop();
        ll no = now.second;
        ll w = now.first * -1;
        if (w > dis[no])
            continue;
        for (auto ch: adj[no]) {
            if (dis[ch.first] > w + ch.second) {
                dis[ch.first] = w + ch.second;
                q.push({-dis[ch.first], ch.first});
            }
        }
    }
}
void dfs(int node) {
    if (node == n) {
        dp[node] = {0, 0, 1};
        return;
    }
    for (auto ch: dag[node]) {
        if (dp[ch].nm == 0)
            dfs(ch);
        dp[node].nm = add(dp[node].nm, dp[ch].nm);
        dp[node].mx = max(dp[ch].mx + 1, dp[node].mx);
        dp[node].mn = min(dp[ch].mn + 1, dp[node].mn);
    }
}
void init(ll nn) {
    adj = viip(nn + 1);
    dag = vii(nn + 1);
    dis = vi(nn + 1,oo);
    dp = vector<info>(nn + 1);
}
void solve() {
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dij(1);
    for (int i = 1; i <= n; ++i) {
        for (auto [ch, w]: adj[i]) {
            if (dis[ch] == dis[i] + w)dag[i].push_back(ch);
        }
    }
    dfs(1);
    cout << dis[n] << " " << dp[1].nm << " " << dp[1].mn <<" "<< dp[1].mx << endl;
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