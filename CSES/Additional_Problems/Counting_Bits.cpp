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
vi conv(ll n) {
    vi v;
    while (n) {
        v.push_back(n % 2);
        n /= 2;
    }
    while (v.size() < 64)v.push_back(0);
    reverse(all(v));
    return v;
}
vi nr1;
ll dp[64][2];
ll dp2[64][2];
ll fun(ll i,ll e1) {
    if (i == nr1.size()) { return 1; }
    if (dp[i][e1] != -1)return dp[i][e1];
    ll opt1 = 0;
    ll l1 = 0;
    ll r1 = (e1) ? nr1[i] : 1;
    for (int j = l1; j <= r1; ++j) {
        ll ten1 = (j == nr1[i]);
        opt1 += (fun(i + 1, ten1 && e1));
    }
    return dp[i][e1] = opt1;
}
ll fun2(ll i,ll e1) {
    if (i == nr1.size()) { return 0; }
    if (dp2[i][e1] != -1)return dp2[i][e1];
    ll opt1 = 0;
    ll l1 = 0;
    ll r1 = (e1) ? nr1[i] : 1;
    for (int j = l1; j <= r1; ++j) {
        ll ten1 = (j == nr1[i]);
        opt1 += (fun2(i + 1, ten1 && e1));
        if (j)
            opt1 += fun(i+1, ten1 && e1);
    }
    return dp2[i][e1] = opt1;
}

void solve() {

    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    ll r1;
    cin >> r1;
    nr1 = conv(r1);
    fun(0, 1);
    ll ans = fun2(0, 1);
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