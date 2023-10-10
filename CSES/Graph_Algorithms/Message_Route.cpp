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

vi path;
void bfs(ll node,vii &adj,vi &dis) {
    dis[node] = 1;
    queue<ll> q;
    q.push(node);
    while (q.size()) {
        ll now = q.front();
        q.pop();
        for (auto ch: adj[now]) {
            if (dis[ch] > dis[now] + 1) {
                q.push(ch);
                dis[ch] = dis[now] + 1;
            }
        }
    }
}

void dfs(ll node, vii &adj,vector<ll> &dis) {
    for (auto ch: adj[node]) {
        if (dis[ch] == dis[node] - 1) {
            dfs(ch, adj, dis);
            path.push_back(ch);
            break;
        }
    }
}

void solve() {

    ll n, m;
    cin >> n >> m;
    vii adj(n + 1);
    vi dis(n + 1, 1e10);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(1, adj, dis);
    if (dis[n] < 1e7) {
        dfs(n, adj, dis);
        cout << dis[n] << endl;
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << " ";
        }
        cout<<n<<endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
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