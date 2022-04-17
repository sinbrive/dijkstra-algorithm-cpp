#include <iostream>
#include "graph.h"

using namespace std;

pair<  unordered_map < char, float >,  unordered_map < char, char >>  Graph::dijkstra(char start){
    vector < char > unVisited;

  for (auto & vertex:Graph::getGraph()) {
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
    return (make_pair(distances, predecessors));
  }
 

pair<float, vector<char>> Graph::shortestPath(char start, char end){

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
 
