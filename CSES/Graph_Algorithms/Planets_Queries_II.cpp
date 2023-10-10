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
ll suc[N][32],vis[N],lvl[N];
void dfs(ll x) {
    vis[x] = 1;
    ll v = suc[x][0];
    if (!vis[v])dfs(v);
    lvl[x] = lvl[v] + 1;
}
ll getKth(ll x,ll k) {
    if(k<0)return 0;
    for (int j = 31; j >= 0; --j) {
        if ((1 << j) & k)x = suc[x][j];
    }return x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> suc[i][0];
    for (int j = 1; j < 32; ++j)
        for (int i = 1; i <= n; ++i)
            suc[i][j] = suc[suc[i][j - 1]][j - 1];
    for (int i = 1; i <= n; ++i)
        if (!vis[i])dfs(i);
    for (int i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        int z = getKth(x, lvl[x]);  ///// lvl [z] === cyc size first node in cyc
        if (getKth(x, lvl[x] - lvl[y]) == y)cout << lvl[x] - lvl[y] << '\n';
        else if (getKth(z, lvl[z] - lvl[y]) == y) cout << (lvl[x] + lvl[z] - lvl[y]) << '\n';
        else cout << -1 << endl;
    }
}