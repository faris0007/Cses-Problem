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
ll n,k,tmp;
bool fun(vi &a,vi &b ,ll aim) {
    ll ans = 0;
    for (auto x: a) {
        if (x > aim)continue;
        ll ned = aim / x;
        ans += min(tmp,ned);
    }
    return ans > k;
}

void solve() {
    cin >> n;
    tmp=n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    for (int i = 0; i < n; ++i) b[i] = i + 1;
    k = n*n/ 2;
    ll st = 0;
    ll en = 1e12 + 5;
    while (st < en) {
        ll mid = st + (en - st) / 2;
        if (fun(a, b, mid)) {
            en = mid;
        } else {
            st = mid + 1;
        }
    }
    cout << en << endl;
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