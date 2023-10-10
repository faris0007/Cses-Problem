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
#define endl '\n'
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

const int N = 5 * 1e5;
const int M = 30;
ll ansector[N][M];
ll lvl[N];
vii adj;
void dfs(ll node, ll par) {
    ansector[node][0] = par;
    lvl[node] = lvl[par] + 1;
    for (int i = 1; i < M; ++i) {
        ansector[node][i] = ansector[ansector[node][i - 1]][i - 1];
    }
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        dfs(ch, node);
    }
}

ll findKthAncestor(ll u, ll k) {
    for (int i = M - 1; i >= 0; --i) {
        if ((1 << i) & k)
            u = ansector[u][i];
    }
    return u;
}

ll LCA(ll u, ll v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    u = findKthAncestor(u, lvl[u] - lvl[v]);
    if (u == v)return v;

    for (int i = M - 1; i >= 0; --i) {
        if (ansector[u][i] == ansector[v][i])continue;
        u = ansector[u][i];
        v = ansector[v][i];
    }
    return ansector[u][0];
}

ll dis(ll u ,ll v ) {
    return lvl[u] + lvl[v] - 2 * lvl[LCA(u, v)];
}


void solve() {
    ll n,q;
    cin>>n>>q;
    adj.resize(n+1);
    for (int i = 0; i < n-1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 0; i <q ; ++i) {
        ll x, y;
        cin >> x >> y;
        cout << dis(x, y) << endl;
    }

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}