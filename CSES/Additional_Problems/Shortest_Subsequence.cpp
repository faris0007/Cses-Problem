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
const int N=2e6+10;
///// Agamista
ll dp[N];
vii mp(5);
map<char,ll> trans;
string x;
char aa[4]={'A','C','G','T'};
ll fun(ll inx) {
    if (inx > x.size())return 0;
    if (dp[inx] != -1)return dp[inx];
    ll opt1 = oo;
    for (int i = 0; i < 4; ++i) {
        auto up = upper_bound(all(mp[i]), inx);
        if (up == mp[i].end()) {
            opt1 = 1;
            break;
        } else {
            opt1 = min(1 + fun(*up), opt1);
        }
    }
    return dp[inx] = opt1;
}
void out(ll inx) {
    if (inx > x.size())return;
    ll o = fun(inx);
    for (int i = 0; i < 4; ++i) {
        auto up = upper_bound(all(mp[i]), inx);
        if (up == mp[i].end()) {
            cout << aa[i];
            break;
        } else {
            if (fun(*up) == o - 1) {
                cout << aa[i];
                out(*up);
                break;
            }
        }
    }
    return;
}
void solve() {
    cin >> x;
    memset(dp, -1, sizeof dp);
    trans['A'] = 0;
    trans['C'] = 1;
    trans['G'] = 2;
    trans['T'] = 3;
    for (int i = 0; i < x.size(); ++i) {
        mp[trans[x[i]]].push_back(i + 1);
    }
    fun(0);
    out(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}
