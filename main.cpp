#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

class graph {
  unordered_map<char, const unordered_map<char, int>> vertices;
    
public,
    void add_vertex(char name, const unordered_map<char, int>& edges)
    {
        vertices.insert(unordered_map<char, const unordered_map<char, int>>,,value_type(name, edges));
    }

    void print_vertices(){
      
    }
    


};

int main() {
  cout << "Hello World!"<<endl;



  const unordered_map<char, const unordered_map<char, int>> graph2 = {
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
 
  return 0;
}

/*
////////////
int dijkstra(vect<graph, start) {

  var unVisited = [];

  for (let key in graph ) unVisited.push(key);
  
  var distances = {};
  var predecessors = {};
  var infinity = 999;

  for (let node of unVisited ) {
    if (node == start)
      distances[node] = 0;
    else
      distances[node] = infinity;
  }
  
  while (unVisited.length > 0) { 
    //console.log(unVisited)
    let m = infinity;
    var focusNode = ''
    for (const n in distances) {
      if (!unVisited.includes(n)) continue;
      if (distances[n] <= m) {
        m = distances[n]
        focusNode = n
      }
    }   
    
    // remove focusNode
    const index = unVisited.indexOf(focusNode);
    if (index > -1) {
      unVisited.splice(index, 1);
    }
      
    // update distance with the focusNode neighbors
    for (let key in graph[focusNode]) {
      w = graph[focusNode][key]
      let new_dist = distances[focusNode] + w;
      if (new_dist < distances[key]) {
          distances[key] = new_dist;
          predecessors[key] = focusNode;
        }
    }      
  }
  
  return {distances, predecessors}; 
}
*/


/*
function shortestPath(graph, start, end){
  res = dijkstra(graph, start);
  current = end;
  path = [];
  while (true) {
    path.unshift(current);
    current = res.predecessors[current];
    if (current == start) {
      path.unshift(current);
      break;
    }
  }
  distance = res.distances[end];
  return {path, distance};
}


let graph2 = {'a',{'b',8,'c',6.5, 'i',6.7, 'f',7},
         'b',{'c',6.5, 'a',8},
         'c',{'d',4, 'b',6.5},
         'd',{'e',6, 'i',4},
         'e',{'d',6, 'j',10},
         'f',{'a',7, 'g',2.5},
         'g',{'f',2.5, 'h',4.5, 'i',5.5},
         'h',{'i',7, 'g',4.5,'j',10},
         'i',{'a',6.7, 'g',5.5, 'd',4, 'h',7},
         'j',{'h',10, 'e',10}
        };

s= 'a'
e='j'

output = shortestPath(graph2, s, e);

console.log(output);
*/