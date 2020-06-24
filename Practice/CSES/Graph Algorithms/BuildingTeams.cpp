/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define fore(name)  for(auto it=name.begin();it!=name.end();it++)
#define w  int t;cin>>t;while(t--)
#define pb(x) push_back(x)
#define in(y) insert(y)
#define bitscount 32
#define make(x,y) make_pair(x,y)
#define LOAD_FACTOR_set(name) name.reserve(32768);name.max_load_factor(0.25);
#define LOAD_FACTOR_map(name) name.reserve(1024);name.max_load_factor(0.25);
#define lcm(a,b) ((a*b))/(__gcd(a,b))
#define int long long int
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define endl "\n"
#define all(x) (x).begin(), (x).end()


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
typedef pair<int, int> pi;
#define UNMAP(name) unordered_map<int,int,custom_hash> name
#define MAX 10000000000000
vector<int> graph[200001];
vector<int> color(200001);
vector<int> visited(200001);

bool bfs(int s)
{
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  color[s] = 2;
  while (q.size() != 0)
  {
    int p = q.front();
    q.pop();
    for (auto it : graph[p])
    {
      if (visited[it] == 0 && color[it] == -1)
      {
        visited[it] = 1;
        if (color[p] == 2)
          color[it] = 1;
        else
          color[it] = 2;
        q.push(it);
      }
      else if (visited[it] == 1 && color[it] == color[p])
        return false;
    }
  }
  return true;
}
int32_t main()
{
  REDBULL

  int n, m;
  cin >> n >> m;
  loop(i, 0, m)
  {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }


  fill(all(color), -1);
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      if (!bfs(i))
      {
        cout << "IMPOSSIBLE" << endl;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << color[i] << " ";
  cout << endl;


  return 0;
}