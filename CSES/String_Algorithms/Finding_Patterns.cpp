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
void radix_sort(vector<pair<pair<int,int>,int>>&a){
    ll n=a.size();
    {
        vector<int>cnt(n);
        for(auto item:a){
            cnt[item.first.second]++;
        }
        vector<pair<pair<int,int>,int>>a_new(n);
        vector<int>pos(n);
        pos[0]=0;
        for (int i = 1; i < n; ++i) {
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(auto x:a){
            int i=x.first.second;
            a_new[pos[i]]=x;
            pos[i]++;
        }
        a=a_new;
    }
    {
        vector<int>cnt(n);
        for(auto item:a){
            cnt[item.first.first]++;
        }
        vector<pair<pair<int,int>,int>>a_new(n);
        vector<int>pos(n);
        pos[0]=0;
        for (int i = 1; i < n; ++i) {
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(auto x:a){
            int i=x.first.first;
            a_new[pos[i]]=x;
            pos[i]++;
        }
        a=a_new;
    }
}
vector<ll> suffarray(string &x) {
    x += "$";
    ll n = x.size();
    vector<pair<char, ll>> a(n);
    vector<ll> st(n);
    vector<ll> clas(n);
    for (int i = 0; i < n; ++i) { a[i] = {x[i], i}; }
    sort(all(a));
    for (int i = 0; i < n; ++i) { st[i] = a[i].second; }
    clas[st[0]] = 0;
    for (int i = 1; i < n; ++i) {
        clas[st[i]] = clas[st[i - 1]];
        if (a[i].first != a[i-1].first)clas[st[i]]++;
    }
    ll k = 0;
    while ((1 << k) < n) {
        vector<pair<pi, ll>> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = {{clas[i], clas[(i + (1 << k)) % n]}, i};
        }
        radix_sort(b);
        for (int i = 0; i < n; ++i) { st[i] = b[i].second; }
        clas[st[0]] = 0;
        for (int i = 1; i < n; ++i) {
            clas[st[i]] = clas[st[i - 1]];
            if (b[i].first != b[i - 1].first)clas[st[i]]++;
        }
        k++;
    }
    return st;
}
ll fun(ll inx,string &z,string &x) {
    ll sz = z.size();
    ll f = 0;
    for (int i = inx; sz > 0; ++i, sz--, f++) {
        if (x[i] < z[f])return 0;
        else if (x[i] > z[f])return 1;
    }
    return 2;
}
void solve() {
    string x;
    cin >> x;
    vi suf = suffarray(x);
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string z;
        cin >> z;
        ll st = 0;
        ll en = suf.size()-1;
        while (st < en) {
            ll mid = st + (en - st) / 2;
            if (fun(suf[mid], z, x)) { /// 1 if >=  else 0
                en = mid;
            } else {
                st = mid + 1;
            }
        }
        if (fun(suf[en], z, x) == 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
}