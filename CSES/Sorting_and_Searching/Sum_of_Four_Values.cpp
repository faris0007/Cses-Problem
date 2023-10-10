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
typedef tree< pair<pi,ll>, null_type, less<pair<pi,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b) {
    return (a * b) / gcd(a, b);
}

void solve( ll h) {
    ll n, x;
    cin >> n >> x;
    map<ll, pi> mp;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i-1; ++j) {
            mp[a[i-1] + a[j]] = {i , j + 1};
        }
        for (int j = i + 1; j < n; ++j) {
            ll ned = x - a[i] - a[j];
            if (mp[ned].first!=0) {
                cout << i + 1 << " " << j + 1 << " " << mp[ned].first << " " << mp[ned].second << endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

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