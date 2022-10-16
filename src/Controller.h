#ifndef __CONTROLLER__H__
#define __CONTROLLER__H__

#include <string>
#include <list>
#include <vector>
#include "Sequence.h"
#include "HuffmanTree.h"

class Controller {
    private:
        std::list < Sequence > sequences;
        HuffmanTree* huffmanTree;

    public:
        Controller();
        virtual ~Controller(); 

        void setSequences(std::list<Sequence>);
        std::list<Sequence> getSequences();

        // Commands 
        
        void cargar(char*);
        void conteo( );
        void listar_secuencias ();
        std::vector<string> histograma(char*);
        std::vector<string> histogramaGeneral ();
        int es_subsecuencia(char*);
        void enmascarar(char*);
        void guardar(char*);
        void codificar(char*);
        void decodificar(char*);

        Sequence findSequence(std::string);
        std::string differentBases();
};

#include "Controller.hxx"

#endif 