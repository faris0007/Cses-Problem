#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e16+5
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
const int M = 25;

void kmp(string &x, vi &fail) {
    for (int i = 1; i < x.size(); ++i) {
        ll j = fail[i - 1];
        while (j > 0 && x[j] != x[i])
            j = fail[j - 1];
        if (x[i] == x[j])
            fail[i] = j + 1;
        else
            fail[i] = 0;
    }
}
void solve() {

    string x;
    cin >> x;
    vi res;
    vi fail(x.size() + 1);
    kmp(x, fail);
    ll ans = 0;
    ll z = fail[x.size() - 1];
    while (z > 0) {
        res.push_back(z);
        z = fail[z - 1];
    }
    sort(all(res));
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
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