#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
#define MOD ll(998244353)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=1e6+1;

ll seg[N];
ll arr[N];
ll lazy[N];
ll cnt[N];
void Build_seg(ll node,ll l, ll r) {
    ll mid = (l + r) / 2;
    lazy[node] = 0;
    cnt[node]=0;
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
void propagate(ll node,ll l,ll r) {
    if (lazy[node] == 0) {
        return;
    }
    ll n = r - l + 1;
    ll start = lazy[node] - (r - l) * cnt[node];
    seg[node] += n * (2 * start + (n - 1) * cnt[node]) / 2;
    if (l != r) {
        int md = l + r >> 1;
        lazy[node << 1] += lazy[node] - (r - md) * cnt[node];
        lazy[node * 2 + 1] += lazy[node];
        cnt[node << 1] += cnt[node];
        cnt[node << 1 | 1] += cnt[node];
    }
    lazy[node] = 0;
    cnt[node] = 0;
}
void update(ll node, ll l , ll r, ll st,ll en,ll val) {
    ll mid = (l + r) / 2;
    propagate(node, l, r);
    if (l > en || r < st) {
        return;
    }
    if (l >= st && r <= en) {
        lazy[node] += val - (en - r);
        cnt[node]++;
        propagate(node, l, r);
        return;
    }
    update(node * 2, l, mid, st, en, val);
    update(node * 2 + 1, mid + 1, r, st, en, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll query(ll node, ll l , ll r, ll st,ll en) {
    propagate(node, l, r);
    if (l > en || r < st)
        return 0;
    if (l >= st && r <= en)
        return seg[node];
    ll mid = l + r >> 1;
    return query(node *2, l, mid, st, en) + query(node *2+1, mid + 1, r, st, en);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Build_seg(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        ll qq;
        cin >> qq;
        ll u, v;
        cin >> u >> v;
        u--,v--;
        if (qq == 1) {

            update(1, 0, n - 1, u, v, v - u + 1);
        } else {

            cout << query(1, 0, n - 1, u, v) << '\n';
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}