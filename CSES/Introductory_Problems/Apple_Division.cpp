#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
#define MOD ll(998244353)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 301;
const int M = 300*300+1;


void solve() {

    ll n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    ll mino = 1e10;
    for (int b = 0; b < (1 << n); b++) {
        ll temp = 0;
        if (__builtin_popcount(b) == n)continue;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i))temp += a[i];
        }
        ll t2 = sum - temp;
        mino = min(mino, abs(t2 - temp));
    }
    cout << mino << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    ll t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}