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
ll lg[N];
void Build_sparce(vii & sp,vi &a) {
    ll n=a.size();
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i < n; ++i) {
        sp[i][0] = a[i];
    }
    for (int bits = 1; bits < sp[0].size(); ++bits) {
        for (int i = 0; i <= (n - (1 << bits)); ++i) {
            sp[i][bits] = min(sp[i][bits - 1], sp[i + (1 << bits - 1)][bits - 1]);
        }
    }
}
ll qmin(ll l, ll r, vii &sp) { // zero based;
    ll dis = lg[r - l + 1];
    return min(sp[l][dis], sp[r - (1 << dis) + 1][dis]);
}
void solve() {
    ll n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vii sp(n + 1, vi(30));
    Build_sparce(sp, a);
    ll maxo = 0;
    for (int i = 0; i < n; ++i) {
        ll st = i;
        ll en = n;
        while (st < en) {
            ll mid = st + (en - st + 1) / 2;
            if (qmin(st, mid, sp) >= a[i]) {
                st = mid;
            } else {
                en = mid - 1;
            }
        }
        ll fir = en;
        st = 0;
        en = i;
        while (st < en) {
            ll mid = st + (en - st) / 2;
            if (qmin(mid, i, sp) >= a[i]) {
                en = mid;
            } else {
                st = mid + 1;
            }
        }
        if ((fir - en + 1) * a[i] >= maxo) {
            maxo = (fir - en + 1) * a[i];
        }
    }
    cout << maxo << endl;
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