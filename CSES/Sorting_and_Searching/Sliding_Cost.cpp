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
//#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef long long ll;
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
const int N=2e5+10;

void solve( ll h) {
    ll n, q, need;
    cin >> n >> q;
    vi a(n);
    ordered_set se;
    multiset<ll> s1, s2;
    ll sum1 = 0, sum2 = 0;
    if (q % 2 == 0) { need = q / 2 - 1; }
    else { need = q / 2; }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < q) {
            se.insert({a[i], i});
            s1.insert(a[i]);
            sum1 += a[i];
        }
    }
    ll i = 0;
    ll j = q - 1;
    while (j < n) {
        ll z = (*se.find_by_order(need)).first;
        while ( s1.size() && *s1.rbegin() > z) {
            ll ff = *s1.rbegin();s1.erase(s1.find(*s1.rbegin()));s2.insert(ff);sum1 -= ff;sum2 += ff;
        }
        while ( s2.size()&& *s2.begin() < z) {
            ll ff = *s2.begin();s2.erase(s2.find(*s2.begin()));s1.insert(ff);sum1 += ff;sum2 -= ff;
        }
        cout << (sum2 - s2.size() * z) + (s1.size() * z - sum1) << " ";
        se.erase({a[i], i});
        if (s1.count(a[i])) {
            s1.erase(s1.find(a[i]));
            sum1 -= a[i];
        } else {
            s2.erase(s2.find(a[i]));
            sum2 -= a[i];
        }
        i++;
        j++;
        se.insert({a[j], j});
        s1.insert(a[j]);
        sum1+=a[j];
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
//    cin >> t;
    cout << fixed << setprecision(9);
    ll h = 1;
    while (t--) {
        solve(h++);
    }
}