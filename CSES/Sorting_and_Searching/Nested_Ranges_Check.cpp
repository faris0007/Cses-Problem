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
typedef vector<pair<pi,ll>> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
typedef vector<vip> viip;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set2;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b) {
return (a * b) / gcd(a, b);
}
bool com( const pair<pi,ll> &p1,const pair<pi,ll> &p2) {
    if (p1.first.first != p2.first.first) return p1.first.first < p2.first.first;
    return p1.first.second > p2.first.second;
}

void solve( ll hh) {

    ll n;
    cin >> n;
    ordered_set s1, s2;
    vector<pi> a(n);
    vip seg(n);
    vip seg2(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        seg[i] = {{x, y}, i};
        seg2[i] = {{y, x}, i};
    }
    ll f = 1;
    sort(all(seg), com);
    sort(all(seg2), com);
    for (int i = 0; i < n; ++i) {
        ll z = (s1.size() - s1.order_of_key({seg[i].first.second, 0}));
        a[seg[i].second].first += z;
        s1.insert({seg[i].first.second, f++});
    }

    for (int i = 0; i < n; ++i) {
        ll z = (s2.size() - s2.order_of_key({seg2[i].first.second, 0}));
        a[seg2[i].second].second += z;
        s2.insert({seg2[i].first.second, f++});
    }
    for (int i = 0; i < n; ++i) {
        if(a[i].second)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        if(a[i].first)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
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