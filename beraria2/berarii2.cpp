// https://infoarena.ro/job_detail/2611013?action=view-source

#include <bits/stdc++.h>

#define FILE_I "berarii2.in"
#define FILE_O "berarii2.out"

class Task {
  int n, m, b;
  int no_int;
  std::vector<int> vizitat;
  std::vector< std::vector< int>> adj;
  std::vector<int> berarii;

 public:
  void solve() {
    read();
    fa();
    print();
  }

 private:
  void read() {
    std::ifstream fin(FILE_I);
    fin >> n >> m >> b;

    no_int = n;
    adj.resize(n + 1);
    vizitat = std::vector<int>(n + 1, 0);
    
    int x, y;
    for (int i = 0; i < m; ++i) {
      fin >> x >> y;
      adj[y].push_back(x); // le salvam direct transpuse
    }

    for (int i = 0; i < b; ++i) {
      fin >> x;
      berarii.push_back(x);
    }

    fin.close();
  }

  void fa() {
    for (auto &x : berarii) {
      if (vizitat[x] == 0) {
        dfs(x);
        // std::cout << std::endl;
      }
    }
  }

  void dfs(int nod) {
    // std::cout << nod << " ";
    vizitat[nod] = 1;
    --no_int;
    for (auto &x : adj[nod]) {
      if (vizitat[x] == 0) {
        dfs(x);
      }
    }
  }

  void print() {
    std::ofstream fout (FILE_O);
    fout << no_int << "\n";

    for (int i = 1; i <= n; ++i) {
      if(vizitat[i] == 0) {
        fout << i << "\n";
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
