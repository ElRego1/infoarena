// https://infoarena.ro/job_detail/2611549?action=view-source

#include <bits/stdc++.h>

#define FILE_I "darb.in"
#define FILE_O "darb.out"
#define ROOT 1

using namespace std;

class Task {
  int n;
  std::vector< std::vector< int>> adj;
  std::vector<int> t_out;
  int solutie = 0;

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
    adj.resize(n + 1);

    int x, y;
    for (int i = 0; i < n - 1; ++i) {
      fin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    fin.close();
  }

  void fa() {
    std::vector<int> vizitat(n + 1, 0);

    int i = ROOT;
    vizitat[i] = 0;
    for (auto &x : adj[i]) {
      vizitat[x] = vizitat[i] + 1;
      dfs(x, vizitat);
    }

    // ne gasim frunza de unde sa mai bagam un bfs
    int frunza = 0;
    for (unsigned int i = 1; i < vizitat.size(); ++i) {
      if (vizitat[i] > vizitat[frunza]) {
        frunza = i;
      }
    }    

    vizitat = vector<int>(n + 1, 0);
    i = frunza;
    vizitat[i] = 0;
    for (auto &x : adj[i]) {
      vizitat[x] = vizitat[i] + 1;
      dfs(x, vizitat);
    }

    compute_solution(vizitat);
  }

  void dfs(int nod, vector<int> &vizitat) {
    for (auto &x : adj[nod]) {
      if (vizitat[x] == 0) {
        vizitat[x] = vizitat[nod] + 1;
        dfs(x, vizitat);
      }
    }
  }

  void compute_solution(vector<int> &vizitat) {
    int x = 0;
    for (unsigned int i = 1; i < vizitat.size(); ++i) {
      if (vizitat[i] > x) {
        x = vizitat[i];
      }
    }
    solutie = x + 1;
  }

  void print() {
    std::ofstream fout (FILE_O);
    fout << solutie;
    fout.close();
  }
};

int main() {
  Task *t = new Task();
  t->solve();
  delete t;
  return 0;
}
