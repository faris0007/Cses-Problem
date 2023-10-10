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
typedef tree< pair<ll,pi>, null_type, less<pair<ll,pi>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set2;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b) {
return (a * b) / gcd(a, b);
}

void solve( ll hh) {

    ll d, n;
    cin >> d >> n;
    vi a(n);
    ordered_set seg;
    ordered_set2 s;
    seg.insert({d,{0,d}});
    s.insert(0);
    s.insert(d);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ll aft = *s.upper_bound(x);
        ll bef = *(--s.upper_bound(x));
        s.insert(x);
        pair<ll,pi> now = {(aft - bef),{bef, aft}};
        seg.erase(now);
        seg.insert({x-bef,{bef,x}});
        seg.insert({aft-x,{x,aft}});
        pair<ll,pi> maxo=*seg.rbegin();
        cout<<maxo.first<<" ";
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