#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e18+5
#define MOD ll(1e9+7)
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
const int N=1e6+1;



void solve() {

    ll n, k;
    cin >> k >> n;
    vi a(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int b = 1; b <= (1 << n); b++) {
        ll now = 1;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) {
                if (LONG_LONG_MAX / a[i] <= now) {
                    now = k + 1;
                    break;
                }
                now *= a[i];
            }
        }
        if (now != 1) {
            ll numofdvisor = k / now;
            if (__builtin_popcount(b) % 2 == 1) {
                ans += numofdvisor;
            } else {
                ans -= numofdvisor;
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}