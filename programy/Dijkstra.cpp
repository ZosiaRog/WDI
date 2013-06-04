#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int const infinity = 1000000;
int const M = 1000; //ilość wierzchołków
int wierzch, kraw, c, d, e, done[M], dist[M];
queue<int> kolejka;

vector<pair<int,int> > krawedz[M];

void Wczytaj(){
	cin >> wierzch >> kraw;
	for(int i=0; i<kraw; i++){
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
	for(int i=1; i<wierzch+1; i++){
		cout << "[" << i <<"]\n";
		Wypisz_krawedz(krawedz[i]);
	}
}


int main(){
	Wczytaj();
	Wypisz();
	return 0;
}
