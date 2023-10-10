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

void solve(int a, int b, int c, int n) {
    if (n == 0)
        return;
    solve(a, c, b, n-1);
    cout<<a<<' '<<c<<endl;
    solve(b, a, c, n-1);
}

void solve() {
    ll n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    solve(1, 2, 3, n);
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
