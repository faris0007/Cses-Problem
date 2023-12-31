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
///// Agamista
const int N = 6e5;
const int M = 30;
ll n,c1,k1,k2,ans;
vector<int> sz,vis,daddy,dis,freq;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        if(l>r)return 0;
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

ll get_sz(ll x,ll p,vector<vector<int>> & adj) {
    sz[x] = 1;
    for (auto c: adj[x]) {
        if (vis[c] || p == c)continue;
        sz[x] += get_sz(c, x, adj);
    }
    return sz[x];
}
ll get_cen(ll x,ll p,ll nsz,vector<vector<int>> & adj) {
    for (auto c: adj[x]) {
        if (vis[c] || p == c)continue;
        if (sz[c] > nsz / 2) {
            return get_cen(c, x, nsz, adj);
        }
    }
    return x;
}
void get_dis(ll x,ll p,ll d,vector<vector<int>> & adj) {
    dis.push_back(d);
    for (auto c: adj[x]) {
        if (vis[c] || p == c)continue;
        get_dis(c, x, d + 1, adj);
    }
}

int decompose(ll x,ll p,vector<vector<int>> & adj) {
    ll mysz = get_sz(x, p, adj);
    ll cen = get_cen(x, p, mysz, adj);
    if (p == -1) p = cen; //// root
    daddy[cen] = p;
    vis[cen] = 1;

    //// calc

    FenwickTree d1 = FenwickTree(mysz*5);
    d1.add(0, 1);
    for (auto c: adj[cen]) {
        if (vis[c])continue;
        dis.clear();
        get_dis(c, cen, 1, adj);
        for (auto xx: dis) { if (xx <= k2) { ans += d1.sum(max(k1 - xx, 0ll), min(k2 - xx, mysz)); }}
        for (auto xx: dis) d1.add(xx, 1);
    }

    /////end calc
    for (auto c: adj[cen]) {
        if (vis[c])continue;
        decompose(c, cen, adj);
        //// adj2[cen].push_back(decompose(c, cen)); to build tree
    }
    return cen;
}
void init(vector<vector<int>> & adj) {
    ans=0;  //// to get answer
    n = adj.size();
    sz = vector<int>(n);
    vis = vector<int>(n);
    daddy = vector<int>(n);
    freq = vector<int>(n);
    c1 = decompose(1, -1, adj);
}

void solve() {
    cin >> n>>k1>>k2;
    vii adj(n+1);
    for (int i = 0; i < n - 1; ++i) {
        ll x, y, c;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init(adj);
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}