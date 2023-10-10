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
const int N = 5 * 1e5;

void dij(ll node , viip &adj ,vi &dis) {

    priority_queue<pi> q;
    q.push({0, node});
    dis[node]=0;
    while (q.size()) {
        pi now = q.top();
        q.pop();
        ll no = now.second;
        ll w = now.first * -1;

        if(w > dis[no])		// to improve order
            continue;
        for (auto ch: adj[no]) {
            if (dis[ch.first] > w + ch.second) {
                dis[ch.first] = w + ch.second;
                q.push({-dis[ch.first], ch.first});
            }
        }
    }
}
void solve() {

    ll n, m;
    cin >> n >> m;
    viip adj(n + 1);
    vi dis(n + 1, 1e18);
    ll x, y,w;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y>>w;
        adj[x].push_back({y,w});
    }
    dij(1,adj,dis);
    for (int i = 1; i <=n ; ++i) {
        cout<<dis[i]<<" ";
    }

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