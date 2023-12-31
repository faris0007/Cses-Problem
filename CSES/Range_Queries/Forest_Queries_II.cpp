#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
#define MOD ll(998244353)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=1005;

int t[N<<2][N<<2],a[N][N];
int n,m;

void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry)
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
    else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}
void build_x (int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m - 1);
}


int sum_y (int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry)
        return 0;
    if (ly == tly && try_ == ry) {
        return t[vx][vy];
    }
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
           + sum_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
}
int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx) {
        return sum_y(vx, 1, 0, m - 1, ly, ry);
    }
    int tmx = (tlx + trx) / 2;
    return sum_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
           + sum_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
}


void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = 1^t[vx][vy];
        else
            t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
    }
}

void update_x (int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx * 2, lx, mx, x, y, new_val);
        else
            update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
}



void solve() {
    ll q;
    cin >> n >> q;
    m = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char xx;
            cin >> xx;
            if (xx == '*')
                a[i][j] = 1;
        }
    }
    build_x(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll p1, p2;
            cin >> p1 >> p2;
            p1--, p2--;
            update_x(1, 0, n - 1, p1, p2, 0);
        } else {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            cout << sum_x(1, 0, n - 1, x1, x2, y1, y2) << endl;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    ll tt = 1;
    // cin >> t;
    while (tt--) {
        solve();
    }

}