#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e8+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;
const int M = 30;
ll n,m;

ll fun(ll i, ll j ,string &x ,string &y,vii &dp) {
    if (i == x.size() || j == y.size()) {
        return x.size() + y.size() - i - j;
    }
    if (dp[i][j] != -1)return dp[i][j];
    ll opt1 = oo;
    ll opt2 = oo;
    ll opt3 = oo;
    if (x[i] == y[j]) {
        opt1 = fun(i + 1, j + 1, x, y, dp);
    } else {
        opt1 = fun(i + 1, j, x, y, dp) + 1;
        opt2 = fun(i + 1, j + 1, x, y, dp) + 1;
        opt3 = fun(i, j + 1, x, y, dp) + 1;
    }
    return dp[i][j] = min3(opt1, opt2, opt3);
}

void solve() {
    string x, y;
    cin >> x >> y;
    vii dp(x.size() + 1, vi(y.size() + 1, -1));

    ll z = fun(0, 0, x, y, dp);
    cout << z << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}