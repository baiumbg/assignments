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
  map<int, vector<int> > graph;

public:
  Graph(Edge* edges, int m) {
    for(int i = 0; i < m; i ++) {
      graph[edges[i].start].push_back(edges[i].end);
    }
  }

  void insertEdge(Edge e) {
    graph[e.start].push_back(e.end);
  }

  void insertNode(int node) {
    graph[node] = vector<int>();
  }

  void removeEdge(Edge e) {
    for(int i = 0; i < graph[e.start].size(); i++) {
      if(graph[e.start].at(i) == e.end)
        graph[e.start].erase(graph[e.start].begin() + i);
    }
  }

  void removeNode(int node) {
    for(map<int, vector<int> >::iterator i = graph.begin(); i != graph.end(); i++) {
      for(int j = 0; j < i -> second.size(); j++) {
        if(i -> second.at(j) == node) i -> second.erase(i -> second.begin() + j);
      }
    }
    map<int, vector<int> >::iterator it = graph.find(node);
    graph.erase(it);
  }

  void print() {
    for(map<int, vector<int> >::iterator i = graph.begin(); i!=graph.end(); i++) {
      cout << i -> first << " -> ";
      for(int j = 0; j < i -> second.size(); j++) {
        cout << i -> second.at(j) << ", ";
      }
      if (i -> second.size() > 0) cout << i -> second.at(i -> second.size() - 1);
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
  test->insertNode(4);
  cout<<"----------------\n";
  test->print();
  return 0;
}
