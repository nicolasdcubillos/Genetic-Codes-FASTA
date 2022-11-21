#ifndef __GRAPH__HXX__
#define __GRAPH__HXX__

#include "Graph.h"
#include "Edge.h"
#include <map>
#include <numeric>
#include <queue>
#include <algorithm>

template < class V, class C >
Graph<V, C>::Graph( ) {
  
}

template < class V, class C >
Graph<V, C>::Graph( int vertex_size ) {
  this->adj = new std::vector< long > [ vertex_size ];
}

template < class V, class C > void
Graph<V, C>::AddVertex( V point ) {
  Vertex < V, C > vertex;
  vertex.setPoint( point );
  this->vertices.push_back( vertex );
}

template < class V, class C > V
Graph<V, C>::GetVertex( long index ) {
  return this->vertices[index].getPoint( );
}

template < class V, class C > void
Graph<V, C>::AddEdge( long start, long end, C cost ) {
  this->vertices[start].getConnections().push_back(new Edge < C > ( end, cost ));
  this->vertices[end].getConnections().push_back(new Edge < C > ( start, cost ));
}

template < class V, class C > std::vector < Vertex < V, C > >
Graph<V, C>::getVertices() {
    return this->vertices;
}

template < class V, class C > std::pair < C, std::vector < long > >
Graph<V, C>::Dijkstra( long start, long end ) {
  
  std::vector < long > path ( this->vertices.size( ), -1);
  
  std::vector < long > shortestPath (0);

  typedef std::pair < C, long > pair;

  std::vector < bool > visited ( this->vertices.size( ), false );

  std::vector < C > costs ( this->vertices.size( ), 0);

  std::priority_queue < pair > Q; 

  if (start == end) return {0, shortestPath};

  Q.push({ 0, start });
  
  while ( !Q.empty() ) {
    pair arc = Q.top( ); 
    
    Q.pop( ); 

    C cost = arc.first; 
    long v = arc.second; 

    if (v == end) {
      shortestPath.push_back( end );
      while (path[v] != start) {
          shortestPath.push_back( path[v] );
          v = path[v];
      }
      shortestPath.push_back( start );
      std::reverse(shortestPath.begin( ), shortestPath.end( ));
      return {-cost, shortestPath};
    }

    if (!visited[v]) {
      visited[v] = true;
      for (int i = 0; i < this->vertices[v].getConnections( ).size( ); i++) {
        long connected = this->vertices[v].getConnections( )[i]->getConnect( );
        Q.push({cost - this->vertices[v].getConnections( )[i]->getCost( ), this->vertices[v].getConnections( )[i]->getConnect( )});
        if (costs[connected] == 0 
          || costs[connected] < cost - this->vertices[v].getConnections( )[i]->getCost( )) {
          costs[connected] = cost - this->vertices[v].getConnections( )[i]->getCost( );
          path[connected] = v;
        }
      }
    }
  }
}

#endif