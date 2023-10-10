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
vi dp,lst,a;
ll C(ll l,ll r) {
    return (a[r] - a[l - 1]) * (a[r] - a[l - 1]);
}
void d_and_c(ll l,ll r,ll x,ll y) {
    if (r < l)return;
    ll md = (l + r) / 2;
    pi bst = {oo, -1};
    for (int i = x; i <= min(md, y); ++i) {
        bst = min(bst, {lst[i] + C(i + 1, md), i});
    }
    dp[md] = bst.first;
    d_and_c(l, md - 1, x, bst.second);
    d_and_c(md+1, r, bst.second, y);
}

void solve() {

    int n, k;
    cin >> n >> k;
    a=dp=lst=vi(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
        lst[i] = C(1, i);

    for (int i = 2; i <= k; i++) {
        d_and_c(1, n, 1, n);
        lst = dp;
    }
    cout << dp[n] << " ";
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
