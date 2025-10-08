#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
private:
    int n, m; 
    vector<vector<pair<int, int>>> adj;
    vector<int> d;      
    vector<int> truoc;   
    vector<int> chuaxet; 
    int s;               

public:
    void input();     
    void dijkstra(); 
    void output();   
};


void Graph::input() {
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    adj.assign(n + 1, vector<pair<int, int>>());
    cout << "Nhap cac canh (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); 
    }

    cout << "Nhap dinh bat dau: ";
    cin >> s;
}

void Graph::dijkstra() {
    d.assign(n + 1, INT_MAX);
    truoc.assign(n + 1, -1);
    chuaxet.assign(n + 1, 1);

    d[s] = 0;
    truoc[s] = 0;
    chuaxet[s] = 0;

    for (int i = 1; i < n; i++) {
        int u = 0, minVal = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (chuaxet[v] && d[v] < minVal) {
                u = v;
                minVal = d[v];
            }
        }

        if (u == 0) return; 
        chuaxet[u] = 0;

        for (size_t j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            int w = adj[u][j].second;
            if (chuaxet[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                truoc[v] = u;
            }
        }
    }
}

void Graph::output() {
    cout << "\nDuong di ngan nhat tu dinh " << s << " den cac dinh:\n";
    for (int v = 1; v <= n; v++) {
        if (d[v] == INT_MAX) {
            cout << "Khong co duong di den dinh " << v << "\n";
        } else {
            cout << "D[" << v << "] = " << d[v] << "; duong di: ";
            vector<int> path;
            int u = v;
            while (u != 0) {
                path.push_back(u);
                u = truoc[u];
            }
            reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    }
}


int main() {
    Graph g;
    g.input();
    g.dijkstra();
    g.output();
    return 0;
}
