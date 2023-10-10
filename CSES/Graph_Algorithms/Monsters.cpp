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
queue<pi> q;
vector<char> path;
pi foun;
pi a;
void bfs(vector<vector<char>> &mat, vector<vector<ll>> &dis) {
    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    vector<char> dc = {'D', 'U', 'R', 'L'};
    while (q.size()) {
        auto z = q.front();
        q.pop();
        ll x = z.first;
        ll y = z.second;
        for (int i = 0; i < 4; ++i) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size() || mat[nx][ny] == '#')continue;
            if (dis[nx][ny] > dis[x][y] + 1) {
                q.push({nx, ny});
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
}
void dfs(ll x,ll y, vector<vector<char>> &mat,vector<vector<ll>> &dis) {
    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    if(x==a.first && y==a.second) {
        return;
    }
    vector<char> dc = {'U', 'D', 'L', 'R'};
    for (int i = 0; i < 4; ++i) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size() || mat[nx][ny] == '#')continue;
        if (dis[nx][ny] == dis[x][y] - 1) {
            path.push_back(dc[i]);
            dfs(nx, ny, mat, dis);
            return;
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<ll>> dis(n, vector<ll>(m, 1e10));
    vector<vector<ll>> dis2(n, vector<ll>(m, 1e10));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'M') {
                dis[i][j] = 0;
                q.push({i, j});
            }
            if (mat[i][j] == 'A') {
                a = {i, j};
            }
        }
    }
    bfs(mat, dis);
    while (q.size())q.pop();
    q.push(a);
    dis2[a.first][a.second]=0;
    bfs(mat, dis2);
    ll flag = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0 || j == m - 1 || i == n - 1 && mat[i][j]=='.') {
                if (dis[i][j] > dis2[i][j]) {
                    foun = {i, j};
                    flag++;
                }
            }
        }
    }
    if (flag) {
        cout << "YES" << endl;
        dfs(foun.first,foun.second,mat,dis2);
        cout<<path.size()<<endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i];
        }
    } else {
        cout << "NO" << endl;
    }
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