#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
using namespace std;
#define mod 1000000007
#define pb push_back
#define MP make_pair
#define endl "\n";
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
#define rep0(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int dx8[]={1,1,0,-1,-1,-1, 0, 1}; 
int dy8[]={0,1,1, 1, 0,-1,-1,-1};
int dx4[]={1, 0, -1, 0};
int dy4[]={0, 1, 0, -1};
typedef long long ll;
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
 
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
// ===================================== //

/*
    BFE traversal in a matrix along with keeping track of the path
*/
 
const int N=1e3+5;
int sx, sy, ex, ey, n, m;
vector<string> v;
string res="";
int vis[N][N], par[N][N];
char dir[4] = {'D', 'R', 'U', 'L'};
 
void bfs(int x, int y){
    vis[x][y]=1;
    queue<pair<int, int>> q;
    q.push({x,y});
    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = curX+dx4[i];
            int ny = curY+dy4[i];
            if(check(nx, 0, n-1) && check(ny, 0, m-1) && !vis[nx][ny] && v[nx][ny]!='#'){
                q.push({nx, ny});
                vis[nx][ny]=1;
                par[nx][ny]=i;
            }
        }
    }
}
 
void solve(){
    cin >> n >> m;
    v.resize(n);    
    rep0(i, n){
        cin >> v[i];
    }
    rep0(i, n){
        rep0(j, m){
            if(v[i][j]=='A'){
                sx=i, sy=j;
            }
            if(v[i][j]=='B'){
                ex=i, ey=j;
            }
        }
    }
    bfs(sx, sy);
    if(!vis[ex][ey]){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    pii start={sx, sy};
    pii end={ex, ey};
    while(end!=start){
        int idx=par[end.ff][end.ss];
        char ch=dir[idx];
        res+=ch;
        end={end.ff - dx4[idx], end.ss - dy4[idx]};
    }
    reverse(all(res));
    cout << sz(res) << endl;
    cout << res << endl;
}   
 
int main(){
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif 
 
    FAST_IO;
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}
 
 