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

ll fun(ll i, ll lst ,vi &a ,vii &dp) {
    if (i == n) { return 1; }
    if (dp[i][lst] != -1)return dp[i][lst];
    ll opt1 = 0;
    ll aft = a[i + 1];
    if (a[i] == 0) {
        ll st = max((lst) ? lst - 1 : 1,1ll);
        ll en = min((lst) ? lst + 1 : m,m);
        for (int j = st; j <= en; ++j) {
            if ((lst && (abs(lst - j) > 1)) || (aft && abs(j - aft) > 1))continue;
            opt1 += fun(i + 1, j, a, dp) % MOD;
            opt1 %= MOD;
        }
    } else {
        if (aft && abs(aft - a[i]) > 1)return dp[i][lst] = 0;
        opt1 += fun(i + 1, a[i], a, dp) % MOD;
        opt1 %= MOD;
    }
    return dp[i][lst] = opt1;
}

void solve() {
    cin >> n >> m;
    vi a(n + 2,0);
    vii dp(n + 1, vi(m + 1, -1));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll z= fun(0, 0, a, dp);
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