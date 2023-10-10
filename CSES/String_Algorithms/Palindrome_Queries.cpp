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
vi  pw(N);				// size of string   imp
vi inv(N);
ll add(ll a, ll b) {
    return ((a % MOD + b % MOD) + MOD) % MOD;
}
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
}
void pre(ll base) {
    pw[0] = 1;
    inv[0] = 1;
    ll mul_inv = fastpow(base, MOD - 2);
    for (int i = 1; i < N; ++i) {
        pw[i] = multi(pw[i - 1], base);
        inv[i] = multi(inv[i - 1], mul_inv);
    }
}
void update(ll node,ll l ,ll r,ll idx,ll val,vi &seg) {
    if (l == r) {
        seg[node] = val;return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx, val,seg);
    else update(node * 2 + 1, mid + 1, r, idx, val,seg);
    seg[node] = add(seg[node * 2] , seg[node * 2 + 1]);
}
ll query(ll node,ll l ,ll r,ll st, ll en,vi &seg) {
    ll mid = (l + r) / 2;
    if (st > r || en < l)return 0;
    if (l >= st && r <= en)return seg[node];
    return add(query(node * 2, l, mid, st, en, seg), query(node * 2 + 1, mid + 1, r, st, en, seg));
}
void solve() {

    ll n, q;
    cin >> n >> q;
    string x;
    cin >> x;
    vi seg(n * 4);
    vi seg2(n * 4);
    for (int i = 0; i < n; ++i) {
        ll ind = x[i] - 'a' + 1;
        update(1, 0, n - 1, i, multi(ind, pw[i]), seg);
        update(1, 0, n - 1, n - 1 - i, multi(ind, pw[n - 1 - i]), seg2);
    }
    for (int i = 0; i < q; ++i) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll ii;
            char ch;
            cin >> ii >> ch;
            ii--;
            ll ind = ch - 'a' + 1;
            update(1, 0, n - 1, ii, multi(ind, pw[ii]), seg);
            update(1, 0, n - 1, n - 1 - ii, multi(ind, pw[n - 1 - ii]), seg2);
        } else {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            ll forw = multi(query(1, 0, n - 1, l, r, seg), inv[l]);
            ll back = multi(query(1, 0, n - 1, n - 1 - r, n - 1 - l, seg2), inv[n-1-r]);
            if (forw == back) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    pre(29);
  //  cin >> tc;
    while (tc--) {
        solve();
    }
}