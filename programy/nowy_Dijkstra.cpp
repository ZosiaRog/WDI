#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
int const infinity = 1000000000;
int const M = 1000000; //max ilość wierzchołków
int n, m, done[M], dist[M]; //n-wierzchołków, m-krawędzi
priority_queue<PII, vector<PII>, greater<PII> > kolejka;

vector<PII> krawedz[M];

void Wczytaj(){
	int c, d, e;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> c >>d >>e; //wierzchołek, sąsiad, odległość
		krawedz[c].push_back(make_pair(e,d));
	}
}

void Wypisz_krawedz(vector<PII> x){
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

int najmniejszy(){
	int min_value = infinity;
	int min_vertex = 0;
	for(int j = 1; j <= n; j++){
		if(!done[j] && min_value > dist[j]){
			min_value = dist[j];
			min_vertex = j;
		}
	}
	return min_vertex;
}

void Diksio(int s){
	for(int i = 1; i <=n; i++){
		dist[i] = infinity;
		done[i] = 0;
	}
	dist[s] = 0;
	kolejka.push(make_pair(dist[s], s));
	int v;
	while(!kolejka.empty()){ 
		v = kolejka.top().second;
		kolejka.pop();
//		cout << " " << v << " ";
		if(!done[v]){
			done[v] = 1;
			for(int j = 0; j < krawedz[v].size(); j++){
				int u = krawedz[v][j].second;
				int dl = krawedz[v][j].first;
				if(dist[u] > dist[v]+dl){
					dist[u] = dist[v]+dl;
					kolejka.push(make_pair(dist[u], u));
				}	
			}
		}
	}
}

void Wypisz_Diksia(){
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
	Diksio(s);
	Wypisz_Diksia();
	return 0;
}
