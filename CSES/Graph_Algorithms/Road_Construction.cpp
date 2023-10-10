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

unordered_map<ll,ll> parent;
unordered_map<ll,ll> siz;
void intiz(ll n){
    for (int i = 1; i <=n ; ++i){
        parent[i]=i;
        siz[i]=1;
    }
}
ll findParent(ll s){
    if(parent[s]==s){
        return s;
    }
    return parent[s]= findParent(parent[s]);
}
void connect(ll u,ll v){
    u= findParent(u);
    v= findParent(v);
    if(u==v){
        return; // cycle neglect  and detect
    }
    if(siz[u]>siz[v]){
        parent[v]=parent[u];
        siz[u]+=siz[v];
    }
    else{
        parent[u]=parent[v];
        siz[v]+=siz[u];
    }
}
bool is_con(ll u,ll v){
    return findParent(u)== findParent(v);
}



void solve() {
    ll n, m;
    cin >> n >> m;
    intiz(n);
    ll maxo=1;
    ll comp=n;
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        if (is_con(x, y)) {
            cout << comp << " " << maxo << endl;
            continue;
        }
        ll fir = siz[findParent(x)];
        ll sec = siz[findParent(y)];
        connect(x,y);
        comp--;
        maxo = max(maxo, fir + sec);
        cout << comp << " " << maxo << endl;
    }

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