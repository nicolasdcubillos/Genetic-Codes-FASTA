#ifndef __SECUENCIA__HXX__
#define __SECUENCIA__HXX__

#include <string>

using namespace std;

Secuencia::Secuencia () {
    this->descripcion_secuencia = "";
    this->codigo_genetico = "";
    this->completa = false;
    this->justificacion = 0;
}

Secuencia::~Secuencia () {

}

void Secuencia::setDescripcion_secuencia (std::string descripcion_secuencia) {
    this->descripcion_secuencia = descripcion_secuencia;
}

void Secuencia::setCompleta (bool completa) {
    this->completa = completa;
}

void Secuencia::setJustificacion (unsigned short justificacion) {
    this->justificacion = justificacion;
}

void Secuencia::setCodigo_genetico(std::string codigo_genetico){
    this->codigo_genetico = codigo_genetico;
}

std::string Secuencia::getDescripcion_secuencia(){
    return this->descripcion_secuencia;
}

bool Secuencia::getCompleta(){
    return this->completa;
}

unsigned short Secuencia::getJustificacion(){
    return this->justificacion;
}

std::string Secuencia::getCodigo_genetico(){
    return this->codigo_genetico;
}

std::string Secuencia::unicos_secuencia(){
    string secuenciaUnicos;
    string secuenciaPrincipal = this->codigo_genetico;

    for(int i = 0; i < secuenciaPrincipal.size(); i++)
        if (secuenciaUnicos.find(secuenciaPrincipal[i]) == std::string::npos)
            secuenciaUnicos.append(std::string(1, secuenciaPrincipal[i]));
        
    return secuenciaUnicos;
}

#endif // __SECUENCIA__HXX__
