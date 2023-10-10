#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
const int N=2e5+10;
///// Agamista
ll suc[N][32],vis[N],ans[N];
void dfs(ll x) {
    vis[x] = 1;
    ll v = suc[x][0];
    if (!vis[v])dfs(v);
    ans[x] = ans[v] + 1;
}
void getcyc(ll x) {
    vi v;
    ll a = suc[x][18], b;
    vis[a] = 1;
    b = suc[a][0];
    ll len = 1;
    v.push_back(a);
    v.push_back(b);
    while (a != b) {
        len++;
        vis[b] = 1;
        b = suc[b][0];
        v.push_back(b);
    }
    ans[x] = len;
    for (auto it: v) { ans[it] = len; }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> suc[i][0];
    for (int j = 1; j < 32; ++j)
        for (int i = 1; i <= n; ++i)
            suc[i][j] = suc[suc[i][j - 1]][j - 1];
    for (int i = 1; i <= n; ++i) if (!vis[suc[i][18]])getcyc(i); ///// HERE WE CHECK IN CYCLE NOT ME BECAUSE I DFS2 MARK ONLY CYCLE
    for (int i = 1; i <= n; ++i)
        if (!vis[i])dfs(i);
    for (int i = 1; i <= n; ++i)cout << ans[i] << " ";
    cout << endl;
}