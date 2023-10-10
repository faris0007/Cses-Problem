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
typedef pair<ll,pi> pii;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;
const int M = 30;

///// by help from this one github


vii  adj,adj2;
ll n;
vector<int> center(int n, vii &adj) {
    int deg[n + 1] = {0};
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1)
            v.push_back(i), deg[i]--;
    }
    int m = v.size();
    while (m < n) {
        vector<int> vv;
        for (auto i: v) {
            for (auto j: adj[i]) {
                deg[j]--;
                if (deg[j] == 1)
                    vv.push_back(j);
            }
        }
        m += vv.size();
        v = vv;
    }
    return v;
}

map<vector<int>, int> mp;
int idx = 0;
int dfs(int s, int p, vii &adj) {
    vector<int> v;
    for (auto i: adj[s]) {
        if (i != p)
            v.push_back(dfs(i, s, adj));
    }
    sort(v.begin(), v.end());
    if (!mp.count(v)) mp[v] = idx++;
    return mp[v];
}


void solve() {
    cin >> n;
    mp.clear();
    adj.clear(), adj2.clear();
    adj.resize(n + 1), adj2.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj2[x].push_back(y);
        adj2[y].push_back(x);
    }
    vector<int> v1 = center(n, adj), v2 = center(n, adj2);
    int s1 = dfs(v1[0], -1, adj);
    int f = 0;
    for (auto s: v2) {
        int s2 = dfs(s, -1, adj2);
        if (s1 == s2)
            f = 1;
    }
    if (f) cout << "YES";
    else cout << "NO";
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}