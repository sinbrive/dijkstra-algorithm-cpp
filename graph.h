#include <unordered_map>
#include <vector>
#include <algorithm>

typedef std::unordered_map<char, const std::unordered_map<char, float>> umap;


class Graph {
  umap graph;

  public:
    Graph(umap G){
      graph = G;
    }
    umap getGraph(){
      return graph;
    }
    std::pair<float, std::vector<char>> shortestPath(char , char );
    std::pair<  std::unordered_map < char, float >,  std::unordered_map < char, char >>  dijkstra(char);
};