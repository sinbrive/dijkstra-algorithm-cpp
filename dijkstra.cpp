#include <iostream>
#include "graph.h"

using namespace std;

int main() {
  cout << "Dijkstra Algo"<<endl;

  umap graph2 = {
         {'a',{{'b',8},{'c',6.5}, {'i',6.7}, {'f',7}}},
         {'b',{{'c',6.5}, {'a',8}}},
         {'c',{{'d',4}, {'b',6.5}}},
         {'d',{{'e',6}, {'i',4}}},
         {'e',{{'d',6}, {'j',10}}},
         {'f',{{'a',7}, {'g',2.5}}},
         {'g',{{'f',2.5}, {'h',4.5}, {'i',5.5}}},
         {'h',{{'i',7}, {'g',4.5},{'j',10}}},
         {'i',{{'a',6.7}, {'g',5.5}, {'d',4,},{'h',7}}},
         {'j',{{'h',10}, {'e',10}}}
        };
  
  char start = 'a';
  char end='j';
  vector<char> path;
  float distance;
  
  Graph g = Graph(graph2);

  pair<unordered_map < char, float >,  unordered_map < char, char >> res;
  res = g.dijkstra(start);
  auto& dist = res.first;
  auto& pred = res.second;
  
  cout<<"Distances:"<<endl;
  for (auto& item:dist) {
    cout << item.first <<":"<<item.second<<",";
  }
  
  cout<<endl<<"Predecessors:"<<endl;
  for (auto& item:pred) {
      cout << item.first <<":"<<item.second<<",";
  }

  auto ret = g.shortestPath(start, end);
  distance = ret.first;
  path = ret.second;

  cout << endl<<"distance: "<<distance<<endl;
  
  cout<<"path: ";
  for (auto& vertex:path) {
    cout<<vertex<<" ";
  }
  cout<<endl;
  
  
  return 0;
}