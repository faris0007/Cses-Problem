#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e18+5
#define MOD ll(1e9+7)
//#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=2e5+10;


void solve( ll h) {
    ll n;
    cin >> n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if (n ==3 || n== 2 ) {
        cout << "NO SOLUTION";
    } else {
        vi f, e;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0)f.push_back(i);
            else e.push_back(i);
        }
        sort(rall(e));
        for (int i = 0; i < f.size(); ++i) {
            cout << f[i] << " ";
        }
        if(n!=4)
        swap(e[0], e[2]);
        else
            swap(e[0], e[1]);
        for (int i = 0; i < e.size(); ++i) {
            cout << e[i] << " ";
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
//    cin >> t;
    cout << fixed << setprecision(9);
    ll h = 1;
    while (t--) {
        solve(h++);
    }
}