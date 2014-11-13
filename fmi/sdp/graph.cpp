#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
struct Edge {
  T start;
  T end;
  Edge() {}
  Edge(T first, T second) {
    start = first;
    end = second;
  }
};

template <typename T>
class Graph {

private:
  map<T, vector<T> > graph;

public:
  Graph(Edge<T>* edges, int m) {
    for(int i = 0; i < m; i ++) {
      graph[edges[i].start].push_back(edges[i].end);
    }
  }

  void insertEdge(Edge<T> e) {
    graph[e.start].push_back(e.end);
  }

  void insertNode(T node) {
    graph[node] = vector<T>();
  }

  void removeEdge(Edge<T> e) {
    for(int i = 0; i < graph[e.start].size(); i++) {
      if(graph[e.start].at(i) == e.end)
        graph[e.start].erase(graph[e.start].begin() + i);
    }
  }

  void removeNode(T node) {
    for(typename map<T, vector<T> >::iterator i = graph.begin(); i != graph.end(); i++) {
      for(int j = 0; j < i -> second.size(); j++) {
        if(i -> second.at(j) == node) i -> second.erase(i -> second.begin() + j);
      }
    }
    typename map<T, vector<T> >::iterator it = graph.find(node);
    graph.erase(it);
  }

  void print() {
    cout<<"graph G {\n";
    for(typename map<T, vector<T> >::iterator i = graph.begin(); i != graph.end(); i++) {
      if(i->second.size() > 0) {
        for(typename vector<T>::iterator j = i -> second.begin(); j != i -> second.end(); j++) {
          cout << '\t' << i -> first << " -- " << *j << endl;
        }
      }
      else {
        cout << '\t' << i->first << endl;
      }
    }
    cout<<"}";
  }

  void bfs(T start) {
    queue<T> Q;
    Q.push(start);
    while(!Q.empty()) {
      T x = Q.front();
      Q.pop();
      for(typename vector<T>::iterator i = graph[x].begin(); i!=graph[x].end(); i++) {
        Q.push(*i);
      }
      cout << x;
    }
  }
};

int main() {
  Edge<char>* edges = new Edge<char>[5];
  edges[0] = Edge<char>('A', 'B');
  edges[1] = Edge<char>('A', 'C');
  edges[2] = Edge<char>('B', 'D');
  edges[3] = Edge<char>('B', 'C');
  edges[4] = Edge<char>('C', 'D');
  Graph<char>* test = new Graph<char>(edges, 5);
  test->insertNode('E');
  test->print();
  return 0;
}
