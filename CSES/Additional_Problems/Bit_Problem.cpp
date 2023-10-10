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
const int N=1<<21;
const int M=21;
///// Agamista
////// to understand that you should draw trie and make level by level
//////////   x|y==x   if  we use only forward we have all subset of mask
void forward1(vi &f){
    for (int bit = 0; bit <M ; ++bit) {
        for (int mask = 0; mask < N; ++mask) {
            if (mask & (1 << bit)) f[mask] += f[mask ^ (1 << bit)];
        }
    }
}
//////// if we have subset from array in mask   f[mask] has all subset from array that has  | == mask aw less
////////if i used backward i make inclusion exclusion to f[mask] has exact subset from array that has  | == mask
//////// f[mask] should == fastpow(2,f[mask]);
void backward1(vi &f){
    for (int bit = 0; bit <M ; ++bit) {
        for (int mask = N-1; mask >=0; --mask) {
            if (mask & (1 << bit)) f[mask] -= f[mask ^ (1 << bit)];
        }
    }
}
//////////   x&y==x   if  we use only forward we have all superset of mask
void forward2(vi &f) {
    for (int bit = 0; bit < M; ++bit) {
        for (int mask = N - 1; mask >= 0; --mask) {
            if (mask & (1 << bit)) f[mask ^ (1 << bit)] += f[mask];
        }
    }
}
//////// if we have subset from array in mask   f[mask] has all subset from array that has  & == mask aw more
////////if i used backward i make inclusion exclusion to f[mask] has exact subset from array that has  & == mask
//////// f[mask] should == fastpow(2,f[mask]);
void backward2(vi &f) {
    for (int bit = 0; bit < M; ++bit) {
        for (int mask = 0; mask < N; ++mask) {
            if (mask & (1 << bit)) f[mask ^ (1 << bit)] -= f[mask];
        }
    }
}
void solve() {

    ll n;
    cin >> n;
    vi a(n);
    vi f(N),f2(N);
    for (int i = 0; i < a.size(); ++i) {
        cin >> a[i];
        f[a[i]]++;
        f2[a[i]]++;
    }
    forward1(f);
    forward2(f2);
    for (int i = 0; i <n ; ++i) {
        cout << f[a[i]] << " " << f2[a[i]] << " " << n- f[(N - 1) ^ a[i]] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
  //  cin >> tc;
    while (tc--) {
        solve();
    }
}