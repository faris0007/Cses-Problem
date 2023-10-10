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
const int N=2e5+10;
///// Agamista
ll vis[8][8]={0};
bool valid(ll i,ll j) {
   return (i >= 0 && i < 7 && j >= 0 && j < 7 && !vis[i][j]);
}
string st;
map<char, pi> mp;
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
string cc="RLDU";
ll ans=0;
void fun(ll inx,ll i,ll j) {

    //// this hep from marck to rid of many cases invalid
    if (valid(i + 1, j) && valid(i - 1, j) && !valid(i, j + 1) && !valid(i, j - 1)) return;
    if (!valid(i + 1, j) && !valid(i - 1, j) && valid(i, j + 1) && valid(i, j - 1)) return;
    if (!valid(i + 1, j) && !valid(i, j + 1) && valid(i + 1, j + 1)) return;
    if (!valid(i - 1, j) && !valid(i, j + 1) && valid(i - 1, j + 1)) return;
    if (!valid(i + 1, j) && !valid(i, j - 1) && valid(i + 1, j - 1)) return;
    if (!valid(i - 1, j) && !valid(i, j - 1) && valid(i - 1, j - 1)) return;

    if (inx == 48 || (i==6 && j==0)) {
        ans += (i == 6 && j == 0 && inx==48);
        return;
    }
    vis[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
        if(st[inx]=='?' || st[inx]==cc[k]) {
            ll xx = i + dx[k];
            ll yy = j + dy[k];
            if (valid(xx, yy)) {
                fun(inx + 1, xx, yy);
            }
        }
    }
    vis[i][j] = 0;
}
void solve() {
    cin >> st;
    vis[0][0] = 1;
    fun(0, 0, 0);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
 //   cin >> tc;
    while (tc--) {
        solve();
    }
}