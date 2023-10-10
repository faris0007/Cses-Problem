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
    string x;
    cin >> x;
    ll maxo = 1;
    ll cnt = 1;
    for (int i = 1; i < x.size(); ++i) {
        if (x[i] == x[i - 1]) {
            cnt++;
        } else {
            maxo = max(maxo, cnt);
            cnt = 1;
        }
    }
    maxo = max(maxo, cnt);
    cout << maxo << endl;
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
