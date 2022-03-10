#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string.h>
#include <unordered_set>

using namespace std;

vector<vector<int>> matr;
int n, m, s, f;


void DFS(int node, vector<bool>& visited) {
    visited[node] = true;

    for (int i = 0; i < m; i++) {
        if (!visited[matr[node][i]]) {
            DFS(matr[node][i], visited);
        }
    }
}

int main(int argc, char* argv[]) {
    int x;
    vector<int> initState;
    vector<int> finalState;
  

    // read
    cin >> n >> m >> s >> f;

    matr = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }
    for (int i = 0; i < s; i++) {
        cin >> x;
        initState.push_back(x);
    }
    for (int i = 0; i < f; i++) {
        cin >> x;
        finalState.push_back(x);
    }

    string task = string(argv[1]);
    if (task.compare("accessible") == 0) {
        // accessible task
        vector<bool> accessible(n, false);
        for (int i = 0; i < s; i ++) {
            accessible[initState[i]] = true;

            vector<bool> visited(n, false);
            DFS(initState[i], visited);

            for (int j = 0; j < n; j++) {
                if (visited[j]) {
                    accessible[j] = true;
                }
            }
        }

        // output accessible
        for (int i = 0; i < n; i++) {
            if (accessible[i]) {
                cout << i << '\n';
            }
        }
    } else if (task.compare("productive") == 0){
        // productive task
        vector<bool> productive(n, false);
        for (int i = 0; i < n; i ++) {
            vector<bool> visited(n, false);
            DFS(i, visited);

            for (int j = 0; j < f; j++) {
                if (visited[finalState[j]]) {
                    productive[i] = true;
                }
            }
        }

        // output productive
        for (int i = 0; i < n; i++) {
            if (productive[i]) {
                cout << i << '\n';
            }
        }
    } else if (task.compare("useful") == 0) {
        // utils task
        vector<bool> useful(n, false);
        vector<bool> a(n, false);
        vector<bool> p(n, false);

        for (int i = 0; i < s; i ++) {
            a[initState[i]] = true;

            vector<bool> visited(n, false);
            DFS(initState[i], visited);

            for (int j = 0; j < n; j++) {
                if (visited[j]) {
                    a[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i ++) {
            vector<bool> visited(n, false);
            DFS(i, visited);

            for (int j = 0; j < f; j++) {
                if (visited[finalState[j]]) {
                    p[i] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
           if (a[i] && p[i]) {
               cout << i << '\n';
           }
        }
    } 
    return 0;
}