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

void solve() {
    ll n;
    cin >> n;
    vi res = {0, 6, 28, 96};
    ll dif = 24;
    while (res.size() < n) {
        ll now = res.size() + 1;
        now = now * now;
        now = (now) * (now - 1) / 2;
        ////// get dif
        ll z = res.size() + 1;
        z -= 4;
        ll ne = 10 + z * 4;
        dif += 2 * ne;
        dif -= 4;
        /////
        res.push_back(now - dif);
    }
    for (int i = 0; i < n; i++)cout << res[i] << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}
