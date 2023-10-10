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


void dfs(ll x,ll y, vector<vector<char>> &mat, vector<vector<bool>> &vis) {
    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size() || mat[nx][ny]=='#')continue;
        if (vis[nx][ny])continue;
        vis[nx][ny] = true;
        dfs(nx, ny, mat, vis);
    }
}

void solve() {

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    ll sum=0;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <m ; ++j) {
            if(!vis[i][j] && mat[i][j]=='.'){
                sum++;
                dfs(i,j,mat,vis);
            }
        }
    }
    cout<<sum<<endl;
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