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
typedef pair<ll,pi> pii;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;
const int M = 30;
ll n,x;


void solve() {
    cin >> n >> x;
    vip c(n + 5);
    vi dp(x + 5);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i].second;
    }
    ///////// if we use for loop from 0 to x   i can use item more than one
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >=0; --j) {
            if (j >= c[i].first) {
                dp[j] = max(dp[j], dp[j - c[i].first] + c[i].second);
            }
        }
    }
    cout << dp[x];
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