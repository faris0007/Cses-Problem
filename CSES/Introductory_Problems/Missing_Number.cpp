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
    vi a(n+1);
    mapi mp;
    for (int i = 0; i < n-1; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 1; i <=n ; ++i) {
        if(!mp[i]){
            cout<<i<<" ";
        }
    }
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
