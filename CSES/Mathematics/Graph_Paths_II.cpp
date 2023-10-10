#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 2e18
#define MOD ll(1e9+7)
//#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
#define foor(i,a,b) for (ll i = a; i < b; i++)
#define num_ocur_insort(vec,x) equal_range(all(vec), x) /* return pair upper lower   auto r=num_ocur_insort(a,6);*/
typedef int ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N = 5 * 1e5;
ll add(ll a, ll b) {
    return a+b;
}
vii mult(vii &a, vii &b) {
    int n = a.size(), m = b[0].size(), f = b.size();
    vii c(n, vi(m, oo));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < f; k++)
                c[i][j] = min(c[i][j], add(a[i][k], b[k][j]));
    return c;
}
vii idendity(int n) {
    vii arr(n, vi(n, 0));
    for (int i = 0; i < n; i++) arr[i][i] = 1;
    return arr;
}
vii expo(vii a, int x) {
    int n = a.size();
    if (x == 0) return idendity(n);
    if (x == 1) return a;
    vii newa = expo(a, x / 2);
    vii ans = mult(newa, newa);
    if (x % 2 == 1) ans = mult(ans, a);
    return ans;
}
void solve() {


    ///////   like floyd warchal  same as him but here is more advanced
    ll n, m, k;
    cin >> n >> m >> k;
    vii a(n, vi(n, oo));
    for (int i = 0; i < m; ++i) {
        ll x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        a[x][y] = min(a[x][y], w);
    }
    vii z = expo(a, k);
    ll ans = z[0][n - 1];
    if (ans >= oo) {
        ans = -1;
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}