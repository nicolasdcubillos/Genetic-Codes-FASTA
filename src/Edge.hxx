#ifndef __EDGE__HXX__
#define __EDGE__HXX__

#include <list>
#include "Edge.h"

template < class C > Edge < C >::Edge ( ) {
  
} 

template < class C > Edge < C >::Edge ( long connect, C cost ) {
  this->connect = connect;
  this->cost = cost;
} 

template < class C > C Edge < C >::getCost ( ) {
  return this->cost;
}

template < class C > long Edge < C >::getConnect ( ) {
  return this->connect;
}

template < class C > void Edge < C >::setConnect ( long connect ) {
  this->connect = connect;
}

template < class C > void Edge < C >::setCost ( C cost ) {
  this->cost = cost;
}

#endif