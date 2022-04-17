#include <iostream>
#include "graph.h"

using namespace std;

int main() {
  cout << "Dijkstra Algorithm"<<endl;

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

  const auto& res = g.dijkstra(start);
  const auto& dist = res.first;
  const auto& pred = res.second;

  cout<<endl;
  cout<<"Distances:"<<endl;
  for (const auto& item:dist) {
    cout << item.first <<":"<<item.second<<",";
  }
  
  cout<<endl;  cout<<endl;
  
  cout<<"Predecessors:"<<endl;
  for (const auto& item:pred) {
      cout << item.first <<":"<<item.second<<",";
  }

  const auto& ret = g.shortestPath(start, end);
  distance = ret.first;
  path = ret.second;
  
  cout<<endl;  cout<<endl;
  
  cout <<"distance: "<<distance;
  
  cout<<endl;  cout<<endl;
  
  cout<<"path: ";
  for (const auto& vertex:path) {
    cout<<vertex<<" ";
  }
  cout<<endl;  cout<<endl;
  
  
  return 0;
}