#include<bits/stdc++.h>
using namespace std;

class Graph {
	private:
		int n,m;
		vector<vector<int>> adj;
		vector<vector<int>> inc;
		vector<pair<int,int>> edges;
		vector<vector<int>> weight;
	public:
		Graph(int vertices, int edges);
		void addEdge(int u, int v,int idx, int w);
		void printAdj();
		void printInc();
		void printWeight();
		bool isConnected();
		bool isEuler();
		bool isHamilton();
	private: 
		void dfs(int u, vector<bool>& visited);
		bool hamiltonUtil(int u, vector<bool>&visited, int count,int start);
};

Graph::Graph(int vertices, int edges) {
	n = vertices;
	m = edges;
	adj.assign(n, vector<int>(n,0));
	weight.assign(n, vector<int>(n,0));
	inc.assign(n,vector<int>(m,0));
	
}

void Graph::addEdge(int u, int v,int idx, int w) {
	adj[u][v] = adj[v][u] = 1;
	
	edges.push_back({u,v});
	inc[u][idx] = inc[v][idx] = 1;
	
	weight[u][v] = weight[v][u] = w;
}

void Graph::printAdj(){
	cout<<"Ma tran ke: "<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<adj[i][j] << " ";
		}
		cout<<endl;
	}
}

void Graph::printInc() {
	cout<<"Ma tran lien thuoc: "<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout<<inc[i][j] <<" ";
		}
		cout<<endl;
	}
}

void Graph::printWeight() {
	cout<<"Ma tran trong so: "<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<weight[i][j] <<" ";
		}
		cout<<endl;
	}
}

void Graph::dfs(int u, vector<bool>& visited){
	visited[u] = true;
	for(int v=0;v<n;v++) {
		if(adj[u][v] && !visited[v]) {
			dfs(v,visited);
		}
	}
}
bool Graph::isConnected() {
	vector<bool> visited(n,false);
	dfs(0, visited);
	for(bool x: visited) if(!x) return false;
	return true;
}

bool Graph::isEuler() {
	if(!isConnected()) return false;
	int odd = 0;
	for(int i=0;i<n;i++) {
		int deg = 0;
		for(int j=0;j<n;j++) {
			deg+= adj[i][j];	
		}
		if(deg % 2 != 0) odd++;
	}
	return (odd == 0 || odd == 2);
}
			
bool Graph::hamiltonUtil(int u, vector<bool>& visited, int count, int start) {
    if(count == n) {
        return adj[u][start]; 
    }
    for(int v=0; v<n; v++) {
        if(adj[u][v] && !visited[v]) {
            visited[v] = true;
            if(hamiltonUtil(v, visited, count+1, start)) return true;
            visited[v] = false;
        }
    }
    return false;
}

bool Graph::isHamilton() {
    for(int start=0; start<n; start++) {
        vector<bool> visited(n,false);
        visited[start] = true;
        if(hamiltonUtil(start, visited, 1, start)) return true;
    }
    return false;
}

bool Graph::isHamilton();

int main() {
	int n,m,w;
	cout<<"Nhap so dinh: ";
	cin>>n;
	cout<<"Nhap so canh: ";
	cin>>m;
	
	Graph g(n,m);
	
	cout<<"Nhap cac canh: "<<endl;
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v>>w;
		g.addEdge(u,v,i,w);
	}
	g.printAdj();
	g.printInc();
	g.printWeight();
	
	cout << "Do thi " << (g.isConnected() ? "lien thong\n" : "khong lien thong\n");
    cout << "Do thi " << (g.isEuler() ? "la Euler\n" : "khong la Euler\n");
    cout << "Do thi " << (g.isHamilton() ? "la Hamilton\n" : "khong la Hamilton\n");
	return 0;
}