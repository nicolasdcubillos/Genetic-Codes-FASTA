#ifndef __GENOMA__HXX__
#define __GENOMA__HXX__

#include <string>
#include <list>


Genoma::Genoma(){

}
Genoma::~Genoma(){

}

void Genoma::setSecuencias(std::list<Secuencia> secuencias){
    this->secuencias = secuencias;
}

std::list<Secuencia> Genoma::getSecuencias(){
    return this->secuencias;
}





#endif // __GENOMA__HXX__
