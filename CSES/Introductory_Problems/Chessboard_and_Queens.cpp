#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=5*1e5;
ll column[9]={0};
ll diag1[20]={0};
ll diag2[20]={0};
ll cnt=0;

void search(int y,vector<string> &mat) {
    if (y == 8) {
        cnt++;
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (column[x] || diag1[x + y] || diag2[x - y + 8 - 1] || mat[x][y] == '*') continue;
        column[x] = diag1[x + y] = diag2[x - y + 8 - 1] = 1;
        search(y + 1, mat);
        column[x] = diag1[x + y] = diag2[x - y + 8 - 1] = 0;
    }
}

void solve() {
    vector<string> mat(8);
    for (int i = 0; i < 8; ++i) {
            cin >> mat[i];
    }
    search(0, mat);
    cout << cnt << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}
