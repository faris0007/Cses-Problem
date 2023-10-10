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
ll multi(ll a, ll b) {
    return ((a % MOD * b % MOD) + MOD) % MOD;
}
ll fastpow(ll a, ll b) {
    if (b == 0)return ll(1);
    ll temp = fastpow(a, b / 2);
    ll total = multi(temp, temp);
    if (b % 2 == 1) {
        total = multi(total, a);
    }
    return total;
}vi parent;
vi siz;
void intiz(ll n) {
    parent.resize(n + 1);
    siz.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        siz[i] = 1;
    }
}

ll findParent(ll s){
    if(parent[s]==s){
        return s;
    }
    return parent[s]= findParent(parent[s]);
}
ll  connect(ll u,ll v) {
    u = findParent(u);
    v = findParent(v);
    if (u == v) {
        return 1;
    }
    if (siz[u] > siz[v]) {
        parent[v] = parent[u];
        siz[u] += siz[v];
    } else {
        parent[u] = parent[v];
        siz[v] += siz[u];
    }
    return 0;
}

void solve() {


    ////////////here not count cycle but count edge will make cycle
    //////////////to count cycle dp mask hamilton cycle (simple task codeforces)

    ll n, m;
    cin >> n >> m;
    intiz(n);
    ll res = 1;
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        ll z = connect(x, y);
        res = multi(res, fastpow(2, z * 1));
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
  //  cin >> tc;
    while (tc--) {
        solve();
    }
}