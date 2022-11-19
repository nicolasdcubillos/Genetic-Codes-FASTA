#ifndef __VERTEX__HXX__
#define __VERTEX__HXX__

#include <list>
#include "Vertex.h"
#include "Edge.h"

template < class V, class C > Vertex < V, C >::Vertex ( ) {
  
}

template < class V, class C > std::vector < Edge < C >* >& Vertex < V, C >::getConnections () {
  return this->connections;
}

template < class V, class C > V Vertex < V, C >::getPoint () {
  return this->point;
}

template < class V, class C > void Vertex < V, C >::setPoint (V point) {
  this->point = point;
}

template < class V, class C > void Vertex < V, C >::setConnections(std::vector < Edge < C >* > connections) {
  this->connections = connections;
}

#endif