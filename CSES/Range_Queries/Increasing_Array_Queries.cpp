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
typedef vector<vip> viip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=1e6;
ll seg[N];
ll a[N];
ll lazy[N];
void Build_seg(ll node,ll l, ll r) {
    ll mid = (l + r) / 2;
    lazy[node] = -2;
    if (l == r) {
        seg[node] = a[l];
        return;
    }
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    seg[node] = seg[node * 2 + 1] + seg[node * 2];
}

void propagate(ll node,ll l,ll r) {
    if (lazy[node] == -2) {
        return;
    }
    seg[node] = lazy[node]*(r-l+1);
    if (l != r) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = -2;
}
void update(ll node, ll l , ll r, ll st,ll en,ll val) {
    ll mid = (l + r) / 2;
    propagate(node, l, r);
    if (l > en || r < st) {
        return;
    }
    if (l >= st && r <= en) {
        lazy[node] =val;
        propagate(node, l, r);
        return;
    }
    update(node * 2, l, mid, st, en, val);
    update(node * 2 + 1, mid + 1, r, st, en, val);
    seg[node] = seg[node * 2 + 1] + seg[node * 2];
}
ll query(ll node, ll l , ll r, ll st,ll en) {
    propagate(node, l, r);
    if (l > en || r < st)
        return 0;
    if (l >= st && r <= en)
        return seg[node];
    ll mid = (l + r) /2;
    return query(node * 2, l, mid, st, en) + query(node * 2 + 1, mid + 1, r, st, en);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    int mxr[n];
    vi pr(n);
    viip qu(n + 10);
    stack<int> s3;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pr[i] = a[i];
    }
    Build_seg(1, 0, n - 1);
    for (int i = 1; i < n; ++i) { pr[i] += pr[i - 1]; }
    for (int i = 0; i < n; i++) {
        while (!s3.empty() && a[s3.top()] < a[n - 1 - i]) s3.pop();
        mxr[n - 1 - i] = s3.empty() ? n : s3.top() - (n - 1 - i);
        s3.push(n - 1 - i);
    }
    for (int i = 0; i < q; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        qu[u].push_back({v, i});
    }
    vi res(q);
    for (int i = n - 1; i >= 0; --i) {
        ll lst = mxr[i] + i - 1;
        update(1, 0, n - 1, i, min(n - 1, lst), a[i]);
        for (auto it: qu[i]) {
            ll fff = query(1, 0, n - 1, i, it.first);
            ll zzz = pr[it.first] - ((i) ? pr[i - 1] : 0);
            res[it.second] = fff - zzz;
        }
    }
    for (auto it: res)cout << it << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    ll tt = 1;
    // cin >> t;
    while (tt--) {
        solve();
    }

}