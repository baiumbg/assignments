#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Edge {
  int start;
  int end;
  Edge() {}
  Edge(int first, int second) {
    start = first;
    end = second;
  }
};

class Graph {
private:
  map<int, vector<int> > vertices;
public:
  Graph(Edge* edges, int m) {
    for(int i = 0; i < m; i ++) {
      vertices[edges[i].start].push_back(edges[i].end);
    }
  }
  void insertEdge(Edge e) {
    vertices[e.start].push_back(e.end);
  }
  void insertNode(int node) {
    vertices[node] = vector<int>();
  }
  void removeEdge(Edge e) {
    for(int i = 0; i < vertices[e.start].size(); i++) {
      if(vertices[e.start].at(i) == e.end)
        vertices[e.start].erase(vertices[e.start].begin() + i);
    }
  }
  void removeNode(int node) {
    for(map<int, vector<int> >::iterator i = vertices.begin(); i != vertices.end(); i++) {
      for(int j = 0; j < i->second.size(); j++) {
        if(i -> second.at(j) == node) i -> second.erase(i -> second.begin() + j);
      }
    }
    map<int, vector<int> >::iterator it = vertices.find(node);
    vertices.erase(it);
  }
  void print() {
    for(map<int, vector<int> >::iterator i = vertices.begin();i!=vertices.end();i++) {
      cout << i -> first << " -> ";
      for(int j = 0; j < i -> second.size(); j++) {
        cout << i -> second.at(j) << ", ";
      }
      cout << endl;
    }
  }
};

int main() {
  Edge* edges = new Edge[5];
  edges[0] = Edge(1, 2);
  edges[1] = Edge(1, 3);
  edges[2] = Edge(2, 4);
  edges[3] = Edge(2, 3);
  edges[4] = Edge(3, 4);
  Graph* test = new Graph(edges, 5);
  Edge e(1, 4);
  test->print();
  return 0;
}
