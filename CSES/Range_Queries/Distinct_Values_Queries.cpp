#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;

typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =LLONG_MAX, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD=998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة


#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int NN=2e5+5,MM=1e6+5;
int arr[NN], frq[MM], sz=800;
int tot;

struct query {
    int l, r, idx;
};

bool cmp(query &a, query &b) {
    if (a.l / sz != b.l / sz)
        return a.l / sz < b.l / sz;
    return a.r < b.r;
}

void add(int x){
    frq[arr[x]]++;
    if(frq[arr[x]]==1){
        tot++;
    }
}

void remove(int x){
    if(frq[arr[x]]==1){
        tot--;
    }
    frq[arr[x]]--;
}


void solve(int inde) {
    int n, q;
    cin >> n >> q;
//    sz = (int) sqrt(n) ;
    map<int,int> coordinateCompress;
    int compressed_Num = 1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if(coordinateCompress.find(arr[i]) != coordinateCompress.end()){
            arr[i] = coordinateCompress[arr[i]];
        }
        else{
            coordinateCompress[arr[i]] = compressed_Num;
            arr[i] = compressed_Num++;
        }
    }

    vector<query> v(q);
    for (int i = 0; i < q; ++i) {
        cin >> v[i].l >> v[i].r;
        v[i].l--, v[i].r--;
        v[i].idx = i;
    }
    sort(all(v), cmp);
    vector<ll> ans(q);
    int l = v[0].l, r = v[0].l;
    frq[arr[v[0].l]]++;
    tot=1;
    for (auto x: v) {

        // add and remove orders may change
        while (l > x.l)add(--l);
        while (r < x.r)add(++r);
        while (l < x.l)remove(l++);
        while (r > x.r)remove(r--);
        ans[x.idx] = tot;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }

}
int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    ll index=1;
    while (t--){
        solve(index++);
    }
    return 0;
}