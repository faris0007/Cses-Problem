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
ll lcm(ll a,ll b) {
return (a * b) / gcd(a, b);
}

ll fun(ll chos,vi &a) {
    ll res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += abs(chos - a[i]);
    }
    return res;
}

void solve( ll hh) {

    ll n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    if (a[0] == 1) {
        pi seg = {0, 1}, seg2;
        for (int i = 1; i < n; ++i) {
            seg2 = {seg.first + a[i], seg.second + a[i]};
            if (seg2.first-1 > seg.second) {
                cout << seg.second + 1 << endl;
                return;
            }
            seg = {seg.first, seg2.second};
        }
        cout<<accumulate(all(a),0ll)+1<<endl;
    } else {
        cout << 1 << endl;
    }
}

signed main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
ll t = 1;
//cin >> t;
cout << fixed << setprecision(9);
ll h = 1;
while (t--) {
solve(h++);
}

}