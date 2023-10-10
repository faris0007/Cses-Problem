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

ll add(ll a, ll b) {
    return ((a % MOD + b % MOD) + MOD) % MOD;
}

ll multi(ll a, ll b) {
    return ((a % MOD * b % MOD) + MOD) % MOD;
}

ll minu(ll a, ll b) {
    return ((a % MOD - b % MOD) + MOD) % MOD;
}
ll fastpow(ll a, ll b) {
    if (b == 0)return ll(1);
    ll temp = fastpow(a, b / 2);
    ll total = multi(temp, temp);
    if (b % 2 == 1) {
        total = multi(total, a);
    }
    return total;
}
int fact[N], inv[N];
int nCr(ll n, ll r) {
    return multi(fact[n], multi(inv[n - r], inv[r]));
}
void build() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = multi(i, fact[i - 1]);
        inv[i] = fastpow(fact[i], MOD - 2);
    }
}

void solve() {

  ll n,m;
  cin>>n>>m;
  cout<<nCr(n+m-1,m)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    build();
  //  cin >> tc;
    while (tc--) {
        solve();
    }
}