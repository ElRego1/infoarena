// https://infoarena.ro/job_detail/2611521?action=view-source

#include <bits/stdc++.h>

#define FILE_I "muzeu.in"
#define FILE_O "muzeu.out"
#define PAZNIC 0
#define INACCESIBIL -1
#define INCHIS -2
#define p pair<int, int>

using namespace std;

class Task {
  int n;
  std::vector< std::vector< int>> adj;
  vector<pair<int, int>> paznici;

 public:
  void solve() {
    read();
    fa();
    print();
  }

 private:
  void read() {
    std::ifstream fin(FILE_I);
    fin >> n;
    adj = vector<vector<int>>(n, std::vector<int>(n, INACCESIBIL));
    
    char x;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j){
        fin >> x;
        if (x == '#') {
          adj[i][j] = INCHIS;
        } else if (x == 'P') {
          adj[i][j] = PAZNIC;
          paznici.push_back(p(i,j));
        }
      }
    }
    fin.close();
  }

  void fa() {
    queue< pair<int, int>> q;
    for (auto &x : paznici) {
      q.push(x);
    }

    while (!q.empty()) {
      pair<int, int> celula = q.front();
      q.pop();
      int cost = adj[celula.first][celula.second] + 1;

      vector< pair<int, int>> next = get_next(celula);

      for (auto &x : next) {
        adj[x.first][x.second] = cost;
        q.push(x);
      }
    }
  }

  vector< pair<int, int>> get_next(pair<int, int> &celula) {
    int x = celula.first;
    int y = celula.second;
    int cost = adj[x][y] + 1;
    vector< pair<int, int>> v = {p(x, y + 1), p(x - 1, y), p(x, y - 1), p(x + 1, y)};
    vector< pair<int, int>> filtrat;
    for (auto &e : v) {
      if (e.first >= 0 && e.first < n && e.second >= 0 && e.second < n && (adj[e.first][e.second] == -1 || adj[e.first][e.second] > cost)) {
        filtrat.push_back(e);
      }
    }
    return filtrat;
  }


  void print() {
    std::ofstream fout (FILE_O);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        fout << adj[i][j] << " ";
      }
      fout << "\n";
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