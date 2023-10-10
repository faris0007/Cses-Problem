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
stack<ll> st;
bool done= false;
vi res;
void dfs(ll node,ll par,vii &adj, vi &vis,vi &inSt) {
    for (auto ch: adj[node]) {
        if (vis[ch] && inSt[ch] && par != ch) {
            res.push_back(ch);
            while (st.size()) {

                res.push_back(st.top());
                if (st.top() == ch)break;
                st.pop();
            }
            cout<<res.size()<<endl;
            for (int i = 0; i < res.size(); ++i) {
                cout<<res[i]<<" ";
            }
            done= true;
            return;
        }
        if(vis[ch])continue;
        vis[ch]=1;
        inSt[ch] = 1;
        st.push(ch);
        dfs(ch, node, adj, vis, inSt);
        if(done)return;
        inSt[ch] = 0;
        st.pop();
    }
}



void solve() {

    ll n, m;
    cin >> n >> m;
    vii adj(n + 1);
    vi vis(n + 1, 0);
    vi inSt(n + 1, 0);
    ll x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if(vis[i] || done)continue;
        dfs(i, 0, adj, vis, inSt);
    }
    if(!done){
        cout<<"IMPOSSIBLE"<<endl;
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