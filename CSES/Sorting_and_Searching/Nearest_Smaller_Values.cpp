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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set2;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b) {
return (a * b) / gcd(a, b);
}

const int N=2e5+10;
ll lg[N];
void Build_sparce(vii & sp,vi &a) {
    ll n = a.size();
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
    if(l>r)return 1e18;
    ll dis = lg[r - l + 1];
    return min(sp[l][dis], sp[r - (1 << dis) + 1][dis]);
}



void solve( ll hh) {


    ll n;
    cin >> n;
    vi a(n);
    vii sp(n + 1, vi(24));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Build_sparce(sp, a);
    for (int i = 0; i < n; ++i) {
        ll st = 0;
        ll en = i - 1;
        while (st < en) {
            ll mid = st + (en - st + 1) / 2;
            if (qmin(mid, i - 1, sp)<a[i]) {
                st = mid;
            } else {
                en = mid - 1;
            }
        }
        if(  i && qmin(en, i - 1, sp)<a[i])
            cout<<en+1<<" ";
        else{
            cout<<0<<" ";
        }
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