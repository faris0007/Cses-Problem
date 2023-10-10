#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
typedef int ll;

map<string,vector<string>> adj;
vector<string>path;
map<string,ll> out1;
map<string,ll> in;

void euler(string node) {
    while (!adj[node].empty()) {
        string nod = adj[node].back();
        adj[node].pop_back();
        euler(nod);
    }
    path.push_back(node);
}
void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "01";
        return;
    }
    string st;
    for (int i = 0; i < (1 << n); ++i) {
        string z = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j))z += '1';
            else z += '0';
        }
        string fir = z.substr(0, n - 1);
        string sec = z.substr(1, n - 1);
        adj[fir].push_back(sec);
        out1[fir]++;
        in[sec]++;
        st = fir;
    }
    euler(st);
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i][0];
    }
    for (int i = 1; i < min(n - 1, ll(path[i].size())); ++i) {
        cout << path[0][i];
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}