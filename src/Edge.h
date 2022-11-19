#ifndef __EDGE__H__
#define __EDGE__H__

template < class C >
class Edge {
  public:
    Edge ( );
    Edge ( long, C );
    C getCost( );
    long getConnect( );
    void setCost ( C );
    void setConnect ( long ); 

  private:
    long connect;
    C cost;
};

#include "Edge.hxx"

#endif