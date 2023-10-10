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
signed main() {
     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, q;
    cin >> n>>q;
   ll suc[N][32];
    for (int i = 1; i <= n; ++i) cin >> suc[i][0];
    for (int j = 1; j < 32; ++j)
        for (int i = 1; i <= n; ++i)
            suc[i][j] = suc[suc[i][j - 1]][j - 1];
    for (int i = 0; i < q; ++i) {
        ll u, k;
        cin >> u >> k;
        int z = 0;
        while (k)
        {
            if (k&1) u = suc[u][z];
            k >>= 1;
            ++z;
        }
        cout << u << '\n';
    }
}