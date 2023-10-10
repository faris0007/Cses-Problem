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
const int N = 301;
const int M = 300*300+1;


void solve() {

    string x;
    cin >> x;
    vi a(x.size());
    iota(all(a), 0);
    set<string> s;
    do {
        string y = "";
        for (int i = 0; i < a.size(); ++i) {
            y += x[a[i]];
        }
        s.insert(y);
    } while (next_permutation(all(a)));
    cout<<s.size()<<endl;
    for (auto it: s)cout << it << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    ll t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}