#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e18+5
#define MOD ll(10e18+7)
//#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define foor(i,a,b) for (ll i = a; i < b; i++)
#define num_ocur_insort(vec,x) equal_range(all(vec), x) /* return pair upper lower   auto r=num_ocur_insort(a,6);*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
struct bebo {ll fir;ll sec;ll thi;ll fot;};
typedef vector<vip> viip;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=5*1e5;
ll seg[N<<2];

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void update(ll node,ll l ,ll r,ll idx,ll val) {
    if (l == r) {
        seg[node] = max(seg[node], val);
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx, val);
    else update(node * 2 + 1, mid + 1, r, idx, val);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
ll query(ll node,ll l ,ll r,ll st, ll en) {
    ll mid = (l + r) / 2;
    if (st > r || en < l)return 0;
    if (l >= st && r <= en)return seg[node];
    return max(query(node * 2, l, mid, st, en), query(node * 2 + 1, mid + 1, r, st, en));
}
void solve() {

    ll n;
    cin >> n;
    vector<pair<pi, ll>> a(n);
    set<ll> s;
    unordered_map<int,int,custom_hash>  mp;
    for (int i = 0; i < n; ++i) {
        ll x, y, w;
        cin >> x >> y >> w;
        a[i] = {{y, x}, w};
        s.insert(x);
        s.insert(y);
    }
    ll ff = 1;
    for (auto it: s) {
        mp[it] = ff++;
    }
    sort(all(a));
    ll maxo = 0;
    for (int i = 0; i < n; ++i) {
        ll st = mp[a[i].first.second];
        ll en = mp[a[i].first.first];
        ll zz = query(1, 0, ff + 1, 1, st - 1) + a[i].second;
        maxo = max(maxo, zz);
        update(1, 0, ff + 1, en, zz);
    }
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
