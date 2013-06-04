#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include <algorithm> 

using namespace std;
int const infinity = 1000000000;
int const M = 1000; //max ilość wierzchołków
int n, m, dist[M];		// n -wierzchołków, m -krawędzi
queue<int> kolejka;

vector<pair<int,int> > krawedz[M];

void Wczytaj(){
	int c, d, e;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> c >>d >>e; //wierzchołek, sąsiad, odległość
		krawedz[c].push_back(make_pair(e,d));
	}
}

void Wypisz_krawedz(vector<pair<int,int> > x){
	for(int j=0; j<x.size(); j++){
		cout << x[j].first <<" "<<x[j].second<<" \n";
	}
	cout <<"\n";
}
	
void Wypisz(){
	for(int i=1; i<=n; i++){
		cout << "[" << i <<"]\n";
		Wypisz_krawedz(krawedz[i]);
	}
}

void Benio(int s){
	for(int i = 1; i <=n; i++){
		dist[i] = infinity;
	}
	dist[s] = 0;
	
	for(int k = 0; k < n-1; k++){
		for(int v = 1; v <= n; v++){
			for(int i = 0; i < krawedz[v].size(); i++){
				int u = krawedz[v][i].second;
				int dl = krawedz[v][i].first;
				dist[u] = min(dist[u], dist[v]+dl);
			}
		}
	}

	
}

void Wypisz_Benia(){
	cout <<"\n";	
	for(int j=1; j<=n; j++){
		cout << " [" << j << "]" << dist[j];
	}
	cout <<"\n";
}

int main(){
	Wczytaj();
//	Wypisz();
	int s;
	cin >> s;
	Benio(s);
	Wypisz_Benia();
	return 0;
}
