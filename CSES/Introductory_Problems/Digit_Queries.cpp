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
vi vec,a;
void build() {
    ll sum = 0;
    vec.push_back(0);
    for (int i = 0; i < 17; ++i) {
        sum = pow(10ll, i) * 9;
        vec.push_back(sum * (i + 1));
    }
    a = vec;
    for (int i = 1; i < vec.size(); ++i) {
        vec[i] += vec[i - 1];
    }
}
char rkm(ll n,ll x) {
    string z = to_string(n);
    if(!x)return z.back();
    for (int i = 0; i < z.size(); ++i) {
        if (i == x - 1)
            return z[i];
    }
}

void solve() {

    ll n;
    cin >> n;
    ll inx = upper_bound(all(vec), n) - vec.begin();
    ll len = inx;
    ll has = n - vec[inx - 1];
    ll st = pow(10, len - 1);
    ll skip = has / len;
    cout << rkm(skip + st - (has % len == 0), has % len) << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    build();
     cin >> t;
    while (t--) {
        solve();
    }
}
