#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
using namespace std;
typedef long long ll;
typedef long double lld;
#define inf 1e18
#define endl "\n";
#define mod 1000000007
#define pb push_back
#define MP make_pair
#define dbg(x) cout << #x << ": " << x << endl
#define check(k, i, j) ((k>=i) && (k<=j))
#define ff first
#define ss second
#define PI acos(-1)
#define sz(x) (int)((x).size())
#define pii pair<int,int>
#define pll pair<long long, long long>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define all(x)  (x).begin(),(x).end()
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,a,b) for(ll i=a;i<=b;i++)
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#pragma GCC diagnostic ignored "-Wunused-variable" 
int dx8[]={1,1,0,-1,-1,-1, 0, 1}; 
int dy8[]={0,1,1, 1, 0,-1,-1,-1};
int dx4[]={1, 0, -1, 0};
int dy4[]={0, 1, 0, -1};
template<class T>using ordered_set=tree<T, null_type, 
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T>using ordered_multiset=tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, 
less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args){
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> 
using u_map = unordered_map<T1, T2, custom_hash>;

mt19937_64 rng((ll)chrono::steady_clock::now().time_since_epoch().count());
template<typename T>void _print(vector<vector<T>> &v)
{for(int i=0; i<sz(v); i++){for(int j=0; j<sz(v[i]); j++){cout << v[i][j] << " ";}cout << endl;}}
void gg(int val) {cout << "Case #" << val << ": ";}
template<typename T>void _print(vector<T> &v, int l, int r){rep1(i, l, r){cout << v[i] << " ";}cout << endl;}
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, 
typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) 
{ os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// ===================================== //

ll n, m;
vector<ll> v;
vector<vector<ll>> dp;

ll solve(ll idx, int nxt){
    if(idx==0){
        if(!v[idx]){
            ll res=0;
            rep1(val, nxt-1, nxt+1){
                res+=(check(val, 1, m));
            }
            return res;
        }
        return abs(nxt-v[idx])<=1;
    }
    if(dp[idx][nxt]!=-1)return dp[idx][nxt];
    if(v[idx]){
        if(abs(v[idx]-nxt)<=1)return dp[idx][nxt] = solve(idx-1, v[idx]);
        return dp[idx][nxt] = 0;
    }
    ll res=0;
    rep1(val, nxt-1, nxt+1){
        if(check(val, 1, m)){
            res=(res%mod + solve(idx-1, val)%mod)%mod;
            res%=mod;
        }
    }
    return dp[idx][nxt] = res;
}

void solve(){   
    cin >> n >> m;
    v.resize(n);
    cin >> v;
    if(n==1){
        if(v[0]){
            cout << 1 << endl;
            return;
        }
        cout << m << endl;
        return;
    }
    dp=vector<vector<ll>>(n, vector<ll>(m+1, -1));
    ll res=0;
    if(v.back()){
        res=solve(n-2, v[n-1]);
    }else{
        rep1(val, 1, m){
            res=(res%mod + solve(n-2, val)%mod)%mod;
        }
    }
    res%=mod;
    cout << res << endl;
}   

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif 

    FAST_IO;
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}