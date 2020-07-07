// https://infoarena.ro/job_detail/2611529?action=view-source

#include <bits/stdc++.h>

#define FILE_I "retele.in"
#define FILE_O "retele.out"

using namespace std;

class Task {
  int n, m;
  std::vector< std::vector<int>> adj;
  std::vector< std::vector<int>> adj_t; // transpusa
  std::vector<int> t_out;
  std::vector< std::vector<int>> solutie;
  std::vector<int> vizitat;
  int pas = 1;

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
    vizitat = std::vector<int>(n+1, 0);
    adj.resize(n + 1);
    adj_t.resize(n + 1);
    int x, y;
    for (int i = 0; i < m; ++i) {
      fin >> x >> y;
      adj[x].push_back(y);
      adj_t[y].push_back(x); // transpusa
    }
    fin.close();
  }

  void fa() {
    sortare_timp_iesire(); // in t_out

    parcurge_transpusa();
  }

// DFS ul de sortare
  void sortare_timp_iesire() {
    for (int i = 1; i <= n; ++i) {
      if (vizitat[i] == 0) {
        dfs(i);
      }
    }
  }

  void dfs(int nod) {
    vizitat[nod] = 1;
    for (auto &x : adj[nod]) {
      if (vizitat[x] == 0) {
        dfs(x);
      }
    }
    t_out.push_back(nod);
  }

// parcurgerea mortului aluia
  void parcurge_transpusa() {
    for (auto x = t_out.end() - 1; x >= t_out.begin(); --x) {
      if (vizitat[*x] == 1) {
        std::vector<int> rand_solutie;
        dfs_transpusa(*x, rand_solutie);
        solutie.push_back(rand_solutie);
      }
    }
  }

  void dfs_transpusa(int nod, std::vector<int> &rand_solutie) {
    vizitat[nod] = 0;
    rand_solutie.push_back(nod);
    for (auto &x : adj_t[nod]) {
      if (vizitat[x] == 1) {
        dfs_transpusa(x, rand_solutie);
      }
    }
  }

  void print() {
    ordoneaza_solutia();

    std::ofstream fout (FILE_O);
    fout << solutie.size() << "\n";
    for (auto &x : solutie) {
      fout << x.size() << " ";
      for (auto &y : x) {
        fout << y << " ";
      }
      fout << "\n";
    }
    fout.close();
  }

  void ordoneaza_solutia() {
    for (auto &x : solutie) {
      std::sort(x.begin(), x.end());
    }

    sort(solutie.begin(), solutie.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    });
  }
};

int main() {
  Task *t = new Task();
  t->solve();
  delete t;
  return 0;
}
