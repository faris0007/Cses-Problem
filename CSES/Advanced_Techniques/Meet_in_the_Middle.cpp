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
void solve() {

    ll n, x;
    cin >> n >> x;
    vi a, a2;
    unordered_map<ll, ll> mp1;
    ll ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        ll f;
        cin >> f;
        a.push_back(f);
    }
    for (int i = n / 2; i < n; ++i) {
        ll f;
        cin >> f;
        a2.push_back(f);
    }
    for (int b = 0; b < (1 << a.size()); b++) {
        ll sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (b & (1 << i))sum += a[i];
        }
        mp1[sum]++;
    }
    for (int b = 0; b < (1 << a2.size()); b++) {
        ll sum = 0;
        for (int i = 0; i < a2.size(); i++) {
            if (b & (1 << i))sum += a2[i];
        }
        if (mp1.count(x - sum))
            ans += mp1[x - sum];
    }
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