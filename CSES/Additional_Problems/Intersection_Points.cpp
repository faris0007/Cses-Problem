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
const int N=3e6+10;
///// Agamista
ll seg[N<<2];
void update(ll node,ll l ,ll r,ll idx,ll val) {
    if (l == r) {
        seg[node] += val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx, val);
    else update(node * 2 + 1, mid + 1, r, idx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll query(ll node,ll l ,ll r,ll st, ll en) {
    ll mid = (l + r) / 2;
    if (st > r || en < l)return 0;
    if (l >= st && r <= en)return seg[node];
    return query(node * 2, l, mid, st, en) + query(node * 2 + 1, mid + 1, r, st, en);
}


void solve() {
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll, ll>> a; ///  x , type ,y, add ,
    for (int i = 0; i < n; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            a.push_back({x1, 0, y1, 1});
            a.push_back({x2, 0, y2, -1});
        } else {
            a.push_back({x1, 1, y1, y2});
        }
    }
    sort(all(a));
    ll ans = 0, m = 1e6 + 5;
    for (auto [x, ty, y, add]: a) {
        if (ty == 0) {
            update(1, 0, N, y + m, add);
        } else {
            ans += query(1, 0, N, y + m, add + m);
        }
    }
    cout << ans << endl;
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