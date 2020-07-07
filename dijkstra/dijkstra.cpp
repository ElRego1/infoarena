

#include <bits/stdc++.h>

#define FILE_I "dijkstra.in"
#define FILE_O "dijkstra.out"
#define INF (1 << 30)
#define p pair<int, int>
#define NMAX 50100

using namespace std;

class Task {
  int n, m;
  std::vector<p> adj[NMAX];
  vector<int> distante;
  vector<bool> visited;

 public:
  void solve() {
    read();
    fa();
    print();
  }

 private:
  void read() {
    std::ifstream fin(FILE_I);
    fin >> n >> m;
    distante = vector<int>(n + 1, INF);
    visited = vector<bool>(n + 1, false);

    int x, y, z;
    for (int i = 0; i < m; ++i) {
      fin >> x >> y >> z;
      adj[x].push_back({z, y});
    }
    
    fin.close();
  }

  void fa() {
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({0, 1}); // bagam nodul 1
    distante[1] = 0;

    while (q.empty() == false) {
      int nod = q.top().second;
      q.pop();
      if (visited[nod] == true) continue;
      visited[nod] = true;
      for (auto &elem : adj[nod]) {
        int cost = elem.first;
        int next_node = elem.second;
        if (visited[next_node] == false && distante[nod] + cost < distante[next_node]) {
          distante[next_node] = distante[nod] + cost;
          q.push(p(distante[next_node], next_node));
        }
      }
    }
  }



  void print() {
    std::ofstream fout (FILE_O);
    for (unsigned int i = 2; i < distante.size(); ++i) {
      if (distante[i] == INF) {
        fout << 0 << " ";
      } else {
        fout << distante[i] << " ";
      }

    }
    fout.close();
  }
};

int main() {
  Task *t = new Task();
  t->solve();
  delete t;
  return 0;
}