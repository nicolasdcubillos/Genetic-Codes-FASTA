#ifndef __SECUENCIA__H__
#define __SECUENCIA__H__

#include <string>

class Secuencia {
    private:
        std::string descripcion_secuencia;
        bool completa;
        unsigned short justificacion;
        std::string codigo_genetico;

    public:
        Secuencia();
        virtual ~Secuencia(); 
        
        void setDescripcion_secuencia(std::string);
        std::string getDescripcion_secuencia();
        void setCompleta(bool);
        bool getCompleta();
        void setJustificacion(unsigned short);
        unsigned short getJustificacion();
        void setCodigo_genetico(std::string);
        std::string getCodigo_genetico();

        std::string unicos_secuencia ();
};

#include "secuencia.hxx"
#endif // __SECUENCIA__H__