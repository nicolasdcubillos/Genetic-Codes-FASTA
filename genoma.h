#ifndef __GENOMA__H__
#define __GENOMA__H__

#include <string>
#include <list>
#include "secuencia.h"

class Genoma {
    private:
        std::list<Secuencia> secuencias;

    public:
        Genoma();
        virtual ~Genoma(); 

        void setSecuencias(std::list<Secuencia>);
        std::list<Secuencia> getSecuencias();

        Secuencia buscarSecuencia(std::string);
        void cargar (char*);
        void conteo ();
        void listar_secuencias ();
        void histograma(char*);
        void es_subsecuencia(char*);
        void enmascarar(char*);
        void guardar(char*);
};

#include "genoma.hxx"
#endif // __GENOMA__H__