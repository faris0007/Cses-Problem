#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e15+5
#define MOD ll(1e9+7)
#define endl '\n'
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


ll n, a, b;
ll lg[N];
void Build_sparce(vii &sp , vi &a) {
    ll n = a.size();
    lg[1] = 0;
    for (int i = 2; i < N; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i < n; ++i) {
        sp[i][0] = a[i];
    }
    for (int b = 1; b < sp[0].size(); ++b) {
        for (int i = 0; i < n; ++i) {
            ll jm = i + (1 << b - 1);
            if (jm >= n)break;
            sp[i][b] = max(sp[i][b - 1], sp[jm][b - 1]);
        }
    }
}
ll qmax(ll l, ll r, vii &sp) {
    if (l >= n) {
        return -oo;
    }
    r = min(r, n - 1);
    ll dis = lg[r - l + 1];
    return max(sp[l][dis], sp[r - (1 << dis) + 1][dis]);
}


void solve() {

    cin >> n >> a >> b;
    vi vec(n);
    ll ans = -oo;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = 1; i < n; ++i) {
        vec[i] += vec[i - 1];
    }
    vii sp(n + 1, vi(30));
    Build_sparce(sp, vec);
    for (int i = 0; i < n; ++i) {
        ll z = qmax(i + a - 1, i + b - 1, sp);
        ans = max(ans, z - ((i!=0)?vec[i-1] : 0));
    }
    cout << ans << endl;
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