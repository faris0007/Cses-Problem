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
const int N = 5e5;
vi conv(ll n,ll add) {
    vi a;
    while (n) {a.push_back(n % 10);n /= 10;}
    ll z = a.size();
    for (int i = 0; i < add - z; ++i) {a.push_back(0);}
    reverse(all(a));
    return a;
}
vi nl,nr,res;
ll dp[20][2][2][10][2],ans;
ll fun(ll i,ll st,ll en, ll lst,ll zelead) {
    if (i == nr.size()) { return 1; }
    if (dp[i][st][en][lst][zelead] != -1)return dp[i][st][en][lst][zelead];
    ll opt1 = 0;
    ll f1 = (st) ? nl[i] : 0;
    ll f2 = (en) ? nr[i] : 9;
    for (int j = f1; j <= f2; ++j) {
        if (lst == j && !zelead)continue;
        ll tst = (j == nl[i]);
        ll ten = (j == nr[i]);
        opt1 += fun(i + 1, st && tst, en && ten, j, zelead && j == 0);
    }
    return dp[i][st][en][lst][zelead] = opt1;
}

void solve() {
    res.clear();
    memset(dp, -1, sizeof(dp));
    ll l, r;
    cin >> l >> r;
    nr = conv(r, 0);
    nl = conv(l, nr.size());
    ans = fun(0, 1, 1, -1, 1);
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }


}