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


void solve() {
    ll n;
    cin >> n;
    vi coin(n);
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }
    ll zz = accumulate(all(coin), 0ll);
    vi dp(zz + 1, 0);
    dp[0] = 1;
    for (auto c: coin) {
        for (int i = zz; i >= 0; --i) {
            if (i - c >= 0)dp[i] = (dp[i] + dp[i - c]) % MOD;;
        }
    }
    vi res;
    for (int i = 1; i <= zz; ++i) {
        if (dp[i])res.push_back(i);
    }
    cout<<res.size()<<endl;
    for (auto it: res)cout << it << " ";
    cout << endl;
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