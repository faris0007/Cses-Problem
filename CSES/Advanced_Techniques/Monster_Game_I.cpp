#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
//#define oo 1e18+5ll
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
const int N=1e6+10;
///// Agamista
ll oo=1e18+5;
struct Line {
    ll m, b;
    ll operator()(const ll x) const {
        return m * x + b;
    }
} seg[N<<2];
int lo[N<<2], hi[N<<2];
void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    seg[i] = {0,oo};
    if(l == r)  return;
    int m = (l+r)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
}
void insert(int i, Line L) {
    int l = lo[i], r = hi[i];
    if (l == r) {
        if (L(l) < seg[i](l))
            seg[i] = L;
        return;
    }
    int m = (l + r) / 2;
    if (seg[i].m < L.m) swap(seg[i], L);
    if (seg[i](m) > L(m)) {
        swap(seg[i], L);
        insert(2 * i, L);
    } else insert(2 * i + 1, L);
}
ll query(int i, ll x){
    int l = lo[i], r = hi[i];
    if(l == r)
        return seg[i](x);

    int m = (l+r)/2;
    if(x < m)
        return min(seg[i](x), query(2*i, x));
    else
        return min(seg[i](x), query(2*i+1, x));
}
void solve() {
    build(1, 1, N);
    ll n, myf, lst;
    cin >> n >> myf;
    vi s(n), f(n);
    for (int i = 0; i < n; ++i) { cin >> s[i]; }
    for (int i = 0; i < n; ++i) { cin >> f[i]; }
    insert(1, {myf,0});
    for (int i = 0; i < n; ++i) {
        lst = query(1, s[i]);
        insert(1, {f[i], lst});
    }
    cout << lst << endl;
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