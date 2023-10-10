#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e16+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;
const int M = 25;
vi  pw(1e6+9);				// size of string   imp
vi inv(1e6+9);
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
void pre(ll base) {
    pw[0] = 1;
    inv[0] = 1;
    ll mul_inv = fastpow(base, MOD - 2);
    for (int i = 1; i < 1e6+9; ++i) {
        pw[i] = multi(pw[i - 1], base);
        inv[i] = multi(inv[i - 1], mul_inv);
    }
}
void make_hash(string &x, vi &prifx) {
    for (int i = 0; i < x.size(); ++i) {
        ll ind = x[i] - 'a' + 1;   				 // if lower case  impor
        prifx[i] = multi(ind, pw[i]);
        if (i > 0) {
            prifx[i] = add(prifx[i], prifx[i - 1]);
        }
    }
}

ll get_value(ll fir, ll sec, vi &prifx) {    /// if fir =0  sec=size-1   all value     ;;  zero based;
    if(fir==0)
        return prifx[sec];
    return multi(minu(prifx[sec],prifx[fir-1]),inv[fir]);
}

void kmp(string &x, vi &fail) {
    for (int i = 1; i < x.size(); ++i) {
        ll j = fail[i - 1];
        while (j > 0 && x[j] != x[i])
            j = fail[j - 1];
        if (x[i] == x[j])
            fail[i] = j + 1;
        else
            fail[i] = 0;
    }
}
void solve() {
    string x;
    cin >> x;
    vi fail(x.size() );
    vi z_algo(x.size(),0);
    kmp(x, fail);
    vi prifx(x.size());
    make_hash(x,prifx);
    for (int i = 1; i < fail.size(); ++i) {
        ll st = 0;
        ll en = x.size() - i;
        while (st < en) {
            ll mid = st + (en - st + 1) / 2;
            if (get_value(0, mid-1, prifx) == get_value(i, i + mid-1, prifx)) {
                st = mid;
            } else {
                en = mid - 1;
            }
        }
        z_algo[i]=en;
    }
    for (auto it:z_algo) {
        cout<<it<<" ";
    }
    cout<<endl;
    for (auto it:fail) {
        cout<<it<<" ";
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    pre(31);
    //  cin >> t;
    while (t--) {
        solve();
    }
}