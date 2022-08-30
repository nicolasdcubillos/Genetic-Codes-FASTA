#ifndef __GENOMA__HXX__
#define __GENOMA__HXX__

#include <string>
#include <list>
#include <iterator>

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

Secuencia Genoma::buscarSecuencia (std::string descripcion_secuencia) {
    Secuencia secuencia;

    for (std::list<Secuencia>::iterator ptr = this->secuencias.begin(); ptr != this->secuencias.end(); ptr++) 
        if (ptr->getDescripcion_secuencia() == descripcion_secuencia)
            return *ptr;
        
    return secuencia;
}

#endif // __GENOMA__HXX__