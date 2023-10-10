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
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
#define foor(i,a,b) for (ll i = a; i < b; i++)
#define num_ocur_insort(vec,x) equal_range(all(vec), x) /* return pair upper lower   auto r=num_ocur_insort(a,6);*/
typedef int ll;
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
const int N=2e5+10;
ll n;
vii adj;
ll add(ll a, ll b) {
    return ((a % MOD + b % MOD) + MOD) % MOD;
}

ll fun(ll node,ll msk,vii &dp) {
    if (__builtin_popcount(msk) == n)
        return node == n - 1;
    if (node == n - 1)return 0;
    if (dp[node][msk] != -1)
        return dp[node][msk];
    ll ans = 0;
    for (auto it: adj[node]) {
        if (msk & (1 << it))continue;
        ans = add(ans, fun(it, msk | (1 << it), dp));
    }
    return dp[node][msk] = ans;
}

void solve() {
    cin >> n;
    ll m;
    cin >> m;
    adj.resize(n + 1);
    vii dp(n, vi(1 <<n, -1));
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    cout << fun(0, 1, dp) << endl;
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