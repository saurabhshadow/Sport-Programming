
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
// Question link:https://codeforces.com/problemset/problem/1020/B

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define fore(name)  for(auto it=name.begin();it!=name.end();it++)
#define w()  int t;cin>>t;while(t--)
#define pb(x) push_back(x)
#define in(y) insert(y)
#define MAX 100000
#define bitscount 32
#define make(x,y) make_pair(x,y)
#define LOAD_FACTOR_set(name) name.reserve(32768);name.max_load_factor(0.25);
#define LOAD_FACTOR_map(name) name.reserve(1024);name.max_load_factor(0.25);
#define lcm(a,b) ((a*b))/(__gcd(a,b))
#define int long long int
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define endl "\n"

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ordered_justset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct HASH {
    size_t operator()(const pair<int, int>&x)const {
        return ((int)x.first) ^ (((int)x.second) << 32);
    }
};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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
vector<int> v1[200001];
int visited[200001];
vector<int> subtree[200001];
int color[200001];
int vis[200001];
int given_color[200001];
int sizesubtree[200001];
int parent[200001];
int ans = 0;
void dfs(int u) {

    visited[u] = 1;

    if (color[u] != color[parent[u]])
        ans++;

    for (int child : v1[u]) {
        if (visited[child] == 1)
            continue;

        dfs(child);
    }

}


int32_t main()
{

    REDBULL

    int n;
    cin >> n;


    loop(i, 2, n + 1) {
        int in;
        cin >> in;
        parent[i] = in;
        v1[in].pb(i);
        v1[i].pb(in);
    }
    parent[1] = 0;


    loop(i, 1, n + 1) {
        cin >> color[i];
    }
    color[0] = 0;
    dfs(1);
    cout << ans << endl;


    return 0;

}