#ifndef __VERTEX__H__
#define __VERTEX__H__

#include <list>
#include <vector>
#include "Edge.h"

template < class V, class C >
class Vertex {
  public:
    Vertex ( );
    std::vector < Edge < C >* >& getConnections ();
    void setConnections ( std::vector < Edge < C >* > );
    V getPoint ( );
    void setPoint ( V );

  private:
    V point;
    std::vector < Edge < C >* > connections;
};

#include "Vertex.hxx"

#endif