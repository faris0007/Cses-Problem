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

    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2 == 0) {
        cout<<"YES"<<endl;
        ll a = 0, b = 0;
        vi r1, r2;
        for (int i = n; i >= 1; --i) {
            if (a <= b) {
                r1.push_back(i);
                a += i;
            } else {
                r2.push_back(i);
                b += i;
            }
        }
        cout<<r1.size()<<endl;
        for (int i = 0; i <r1.size() ; ++i) {
            cout << r1[i] << " ";
        }
        cout<<endl;
        cout<<r2.size()<<endl;
        for (int i = 0; i <r2.size() ; ++i) {
            cout << r2[i] << " ";
        }
        cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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