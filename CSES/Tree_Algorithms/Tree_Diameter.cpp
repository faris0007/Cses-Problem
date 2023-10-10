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
const int N=3e5+10;


void dfs(ll node,ll par,vi &dp1,vi &dp2,vii &adj) {
    pi mx = {0, 0};
    ll c=0;
    for (auto ch: adj[node]) {
        if (ch != par) {
            dfs(ch, node, dp1, dp2, adj);
            dp1[node] = max(dp1[node], 1 + dp1[ch]);
            mx.second = max(mx.second, dp1[ch]);
            if (mx.second > mx.first)swap(mx.first, mx.second);
            c++;
        }
    }
    if(c>1)
    dp2[node] = 2 + mx.first + mx.second;
    return;
}


void solve() {
    ll n;
    cin >> n;
    vii adj(n + 1);
    vi dp1(n + 1, 0), dp2(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0, dp1, dp2, adj);
    cout << max(*max_element(all(dp1)), *max_element(all(dp2))) << endl;
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