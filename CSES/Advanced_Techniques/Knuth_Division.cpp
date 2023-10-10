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
const int N=5005;
///// Agamista

ll dp[N][N];
ll mid[N][N];
vi a,pr;
ll get(ll l,ll r,vi &pr) {
    if(r<l)return 0;
    if (l)return pr[r] - pr[l - 1];
    return pr[r];
}
ll fun(ll l,ll r) {
    if (l>=r) {
        if (l == r)return 0;
    }
    if (dp[l][r] != -1)return dp[l][r];
    ll opt1 = oo;
    ll m1 = mid[l][r - 1];
    ll m2 = mid[l + 1][r];
    for (int i = m1; i <=min(r-1,m2); ++i) {
        ll tmp = fun(l, i) + fun(i + 1, r)+get(l, r, pr);
        if (tmp < opt1) {
            opt1 = tmp;
            mid[l][r] = i;
        }
    }
    return dp[l][r] = opt1;
}



void solve() {
    ll n;
    cin >> n;
    a.resize(n);
    pr.resize(n);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pr[i] = a[i];
        if (i)pr[i] += pr[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <= n; ++j) {
            mid[j][i] = j;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            fun(i, j);
        }
    }
    cout << fun(0, n - 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
}