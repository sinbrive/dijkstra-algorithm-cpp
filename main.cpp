#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unordered_map<char, const unordered_map<char, float>> umap;

class Graph {

  umap graph;
public:
  Graph(umap G){
    graph = G;
  }

//
  pair<float, vector<char>> shortestPath(char start, char end){

    vector < char > path;
    char current = end;
    auto res = dijkstra(start);
    auto dist = res.first;
    auto pred = res.second;
  
    while (current) {
        path.insert(path.begin(), current);
        current = pred[current];
    }
  
    float distance = dist[end];

    return (make_pair(distance, path));

  }
  // vector< const unordered_map < char, float >, const unordered_map < char, char >>
  pair<  unordered_map < char, float >,  unordered_map < char, char >>  dijkstra(char start){
    vector < char > unVisited;

  for (auto & vertex: graph) {
      unVisited.push_back(vertex.first);
  }
  /*
    for (auto& v:unVisited){
      cout << v;
    }
    cout << endl;
  */
  unordered_map < char, float > distances;
  unordered_map < char, char > predecessors;
  float infinity = 999.0;

  for (auto v: unVisited) {
      if (v == start)
          distances[v] = 0;
      else
          distances[v] = infinity;
  }

  /*
for (auto& d:distances) {
  cout << d.first <<" " <<d.second<<endl;
}
*/
  while (!unVisited.empty()) {
      int m = infinity;
      char focusNode = '-';
      for (auto & d: distances) {
          if (!std::count(unVisited.begin(), unVisited.end(), d.first)) continue;
          if (d.second <= m) {
              m = d.second;
              focusNode = d.first;
          }
      }
      // cout << focusNode <<endl;

      unVisited.erase(std::remove(unVisited.begin(), unVisited.end(), focusNode), unVisited.end());
      /*
      for (auto& v:unVisited){
          cout << v;
        }
        cout << endl;
      */
      for (auto & child: graph.at(focusNode)) {
          float w = child.second;
          float new_dist = distances[focusNode] + w;
          if (new_dist < distances[child.first]) {
              distances[child.first] = new_dist;
              predecessors[child.first] = focusNode;
          }

      }

  } // while 

    /*
  for (auto & d: distances) {
      cout << d.first << " " << d.second << endl;
  }

  for (auto & d: predecessors) {
      cout << d.first << ":" << d.second << endl;
  }
*/
//https://www.geeksforgeeks.org/vector-of-unordered-maps-in-c-with-examples/
    //vector< unordered_map< char, float >,  unordered_map< char, char > > ret;
//vector<unordered_map< char, float >, unordered_map< char, float >> vect;
    //ret.push_back(make_pair(distances, predecessors));
    //return {distances, predecessors};
    //return ret;
    return (make_pair(distances, predecessors));
  }
 

};

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

  vector < char > unVisited;

  for (auto & vertex: graph2) {
      unVisited.push_back(vertex.first);
  }
  /*
    for (auto& v:unVisited){
      cout << v;
    }
    cout << endl;
  */
  unordered_map < char, float > distances;
  unordered_map < char, char > predecessors;
  float infinity = 999.0;

  char start = 'a';
  for (auto v: unVisited) {
      if (v == start)
          distances[v] = 0;
      else
          distances[v] = infinity;
  }

  /*
for (auto& d:distances) {
  cout << d.first <<" " <<d.second<<endl;
}
*/
  while (!unVisited.empty()) {
      int m = infinity;
      char focusNode = '-';
      for (auto & d: distances) {
          if (!std::count(unVisited.begin(), unVisited.end(), d.first)) continue;
          if (d.second <= m) {
              m = d.second;
              focusNode = d.first;
          }
      }
      // cout << focusNode <<endl;

      unVisited.erase(std::remove(unVisited.begin(), unVisited.end(), focusNode), unVisited.end());
      /*
      for (auto& v:unVisited){
          cout << v;
        }
        cout << endl;
      */
      for (auto & child: graph2.at(focusNode)) {
          float w = child.second;
          float new_dist = distances[focusNode] + w;
          if (new_dist < distances[child.first]) {
              distances[child.first] = new_dist;
              predecessors[child.first] = focusNode;
          }

      }

  } // while 
/*
  for (auto & d: distances) {
      cout << d.first << " " << d.second << endl;
  }

  for (auto & d: predecessors) {
      cout << d.first << ":" << d.second << endl;
  }
*/
  // shortest path
  char end = 'j';
  vector < char > path;

  char current = end;

  while (current) {
      path.insert(path.begin(), current);
      current = predecessors[current];
  }

  float distance = distances[end];

  cout << "distance: "<<distance << endl;
  cout << "Path: ";
  for (auto & vertex: path) {
      cout << vertex << " ";
  }
  cout << endl;
 cout <<"ret class"<<endl;

  Graph g = Graph(graph2);

  pair<  unordered_map < char, float >,  unordered_map < char, char >> res;
  res = g.dijkstra(start);
  auto& dist = res.first;
  auto& pred = res.second;
  
  cout<<"Distances:"<<endl;
  for (auto& item:dist) {
    cout << item.first <<":"<<item.second<<endl;
  }
  cout<<"Predecessors:"<<endl;
  for (auto& item:pred) {
      cout << item.first <<":"<<item.second<<endl;
    }

  auto ret = g.shortestPath(start, end);
  distance = ret.first;
  path = ret.second;

  cout << "distance: "<<distance<<endl;
  cout<<"Path: ";
  for (auto& vertex:path) {
    cout<<vertex<<" ";
  }
  cout<<endl;
  
  
  return 0;
}