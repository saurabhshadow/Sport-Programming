/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>

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
#define MAX 200000
int tree[5 * MAX + 10];
int arr[MAX];


void build(int node, int s, int e)
{
  if (s == e)
  {
    tree[node] = arr[s];
    return ;
  }
  build(2 * node, s, (s + e) / 2);
  build(2 * node + 1, 1 + (s + e) / 2, e);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int s, int e, int index, int value)
{
  if (s == e)
  {
    tree[node] += value;
    return;
  }
  if (index <= (s + e) / 2)
    update(2 * node, s, (s + e) / 2, index, value);
  else
    update(2 * node + 1, 1 + (s + e) / 2, e, index, value);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int s, int e, int l, int r)
{
  if (s > r || e < l)
    return 0;
  if (s >= l && e <= r)
    return tree[node];

  return (query(2 * node, s, (s + e) / 2, l, r) + query(2 * node + 1, 1 + (s + e) / 2, e, l, r));
}


void solve()
{
  string s, b;
  int k;
  cin >> s;
  int m;
  cin >> m;
  int a[m];
  int fre[26] = {};
  loop(i, 0, m)
  {
    cin >> a[i];
    b += '0';
  }
  loop(i, 0, s.size())
  {
    fre[s[i] - 'a']++;
  }
  int r = 25, l = 0;
  int vis[m] ;
  memset(vis, 0, sizeof(vis));
  while (true)
  {
    vector<int> v;
    loop(i, 0, m)
    {
      if (!vis[i] && a[i] == 0)
        v.pb(i), vis[i] = 1, l++;
    }
    int size = v.size();
    while (fre[r] < size)
      r--;
    loop(i, 0, size)
    {
      char c1 = r + 'a';
      // cout << r << endl;
      b[v[i]] = c1;
      // cout << c1 << endl;
      loop(j, 0, m)
      {
        if (!vis[j])
        {
          a[j] -= abs(j - v[i]);
        }
      }
    }
    r--;
    if (l == m)
      break;

  }
  cout << b << endl;

}
int32_t main()
{
  REDBULL
  w
  solve();
  return 0;
}