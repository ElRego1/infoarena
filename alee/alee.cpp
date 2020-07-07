// https://infoarena.ro/job_detail/2611014?action=view-source

#include <bits/stdc++.h>

#define FILE_I "alee.in"
#define FILE_O "alee.out"

#define p pair<int, int>

using namespace std;

class Task {
  int n, m;
  std::vector< std::vector< int>> adj;
  pair<int, int> intrare, iesire;

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
    adj.resize(n + 1, std::vector<int>(n+1, 0));
    
    int x, y;
    for (int i = 0; i < m; ++i) {
      fin >> x >> y;
      adj[x][y] = -1;
    }

    fin >> x >> y;
    intrare = pair<int, int>(x, y);

    fin >> x >> y;
    iesire = pair<int, int>(x, y);

    fin.close();
  }

  void fa() {
    queue< pair<int, int>> q;
    q.push(intrare);

    adj[intrare.first][intrare.second] = 1;

    while (!q.empty()) {
      pair<int, int> celula = q.front();
      q.pop();
      int cost = adj[celula.first][celula.second] + 1;

      vector< pair<int, int>> next = get_next(celula);

      for (auto &x : next) {
        adj[x.first][x.second] = cost;
        if (x == iesire) {
          return;
        }
        q.push(x);
      }
    }
  }

  vector< pair<int, int>> get_next(pair<int, int> &celula) {
    int x = celula.first;
    int y = celula.second;
    vector< pair<int, int>> v = {p(x, y + 1), p(x - 1, y), p(x, y - 1), p(x + 1, y)};
    vector< pair<int, int>> filtrat;
    for (auto &x : v) {
      if (x.first >= 1 && x.first <=n && x.second >= 1 && x.second <= n && adj[x.first][x.second] == 0) {
        filtrat.push_back(x);
      }
    }
    return filtrat;
  }


  void print() {
    std::ofstream fout (FILE_O);
    fout << adj[iesire.first][iesire.second];
    fout.close();
  }
};

int main() {
  Task *t = new Task();
  t->solve();
  delete t;
  return 0;
}