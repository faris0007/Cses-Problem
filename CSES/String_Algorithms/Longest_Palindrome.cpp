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
struct manacher {
    vector<int> p;
    void run_manacher(string s) {
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        int maxIdx = 1, maxLen = 1;
        for (int i = 1; i < n; i++) {
            p[i] = max(0ll, min(r - i, p[l + r - i]));
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) {
                p[i] += 1;
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }

            if (p[i] > maxLen) {
                maxLen = p[i];
                maxIdx = i;
            }
        }
    ///// to print longest string
        for (int i = maxIdx - (maxLen - 1); i < (maxIdx + maxLen); i++) {
            if (s[i] != '#')
                cout << s[i];
        }
    }
    void build(string s) {
        string t;
        for (auto v: s) {
            t += string("#") + v;
        }
        run_manacher(t + "#");
    }
    int getLongest(int cen, bool odd) {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }
    bool checkPalin(int l, int r) {
        if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)) {
            return 1;
        }
        return 0;
    }
}man;
string fun(string &temp1) {
    ll nn = temp1.size();
    if (!nn)return "";
    man.build(temp1);
    for (int i = nn - 1; i >= 0; --i) {
        if (man.checkPalin(0, i)) {
            return temp1.substr(0, i + 1);
        }
    }

}

void solve() {
    string x;
    cin >> x;
    man.build(x);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
   // cin >> tc;
    while (tc--) {
        solve();
    }
}