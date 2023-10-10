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
const int N = 5005;

unordered_map<ll,ll> dist;
ll st_of_cyc;
ll en_of_cyc;
vi parent(N);
bool negCycle;
void Bellman_Ford( int src ,ll n,vii &edges) {
    for (int i = 1; i <= n; i++) {
        dist[i] = oo;
    }
    dist[src] = 0;
    for (int lvl = 1; lvl <= n; lvl++) {
        st_of_cyc = -1;
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dist[u] + w < dist[v]) {
                if (lvl == n && st_of_cyc==-1) {
                    negCycle = true;
                    st_of_cyc = u;
                }
                parent[v] = u;
                dist[v] = dist[u] + w;
            }
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    negCycle= false;
    vii  edges(m);
    vii adj(n + 1);
    vi vis(n + 1, 0);
    foor(i,0,m) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    Bellman_Ford(1,n,edges);
    if(negCycle) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
            st_of_cyc = parent[st_of_cyc];
        vector<int> cycle;
        for (int v = st_of_cyc;; v = parent[v]) {
            cycle.push_back(v);
            if (v == st_of_cyc && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto it: cycle)cout << it << " ";
    }
    else{
        cout<<"NO"<<endl;
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