#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int const M = 1000;
int wierzch, kraw, c, d, visited[M];
vector<int> krawedz[M], lista;
queue<int> kolejka;

void visited_clear(){
	for(int i=0; i<M; i++){
		visited[i]=0;
	}
}

void Wczytaj(){
	cin >> wierzch >> kraw;
	for(int i=0; i<kraw; i++){
		cin >> c >>d;
		krawedz[c].push_back(d);
	}
}

void Wypisz_krawedz(vector<int> x){
	for(int j=0; j<x.size(); j++){
		cout << x[j] <<" ";
	}
	cout <<"\n";
}
	
void Wypisz(int a){
	for(int i=1; i<a+1; i++){
		cout << "[" << i <<"] ";
		Wypisz_krawedz(krawedz[i]);
	}
}

void BFS(int a){
	kolejka.push(a);
	while(!kolejka.empty()){
		c = kolejka.front();
		lista.push_back(c);
		kolejka.pop();
		visited[c]=1;
		for(int j=0; j<krawedz[c].size(); j++){
			if(visited[krawedz[c][j]]==0){
			kolejka.push(krawedz[c][j]);
			}			
		}
	}	
}

void sortuj(int a){
	visited_clear();	
	BFS(a);
	Wypisz_krawedz(lista);
}
			
int main(){
	Wczytaj();
	Wypisz(wierzch);
	cin >> d;
	sortuj(d);
	return 0;
}
