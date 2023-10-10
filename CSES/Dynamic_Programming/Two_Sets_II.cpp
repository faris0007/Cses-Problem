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
const int N=70000;
ll a[501];
ll dp[501][N];
ll n;

ll add(ll a, ll b) {
    return ((a % MOD + b % MOD) + MOD) % MOD;
}

ll multi(ll a, ll b) {
    return ((a % MOD * b % MOD) + MOD) % MOD;
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
int nCr( ll n , ll r)
{
    return multi(fact[n],multi(inv[n-r],inv[r]));
}


ll rec(ll inx,ll sum,ll dis) {
    if (inx == n) {
        if (sum == dis) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[inx][sum] != -1)return dp[inx][sum];

    ll opt1 = 0, opt2 = 0;
    if (sum < dis) {
        opt1 =(opt1%MOD+ rec(inx + 1, sum + a[inx], dis)%MOD)%MOD;
    }
    opt2 =(opt2%MOD+ rec(inx + 1, sum, dis)%MOD)%MOD;
    return dp[inx][sum] = (opt1%MOD+ opt2%MOD)%MOD;
}




void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    ll sum = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    if (sum % 2 == 0) {
        sum /= 2;
        cout << (rec(1, a[0], sum) % MOD)<< endl;
    } else {
        cout << 0 << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = multi(i, fact[i - 1]);
        inv[i] = fastpow(fact[i], MOD - 2);
    }
    //cin >> t;
    while (t--) {
        solve();
    }
}