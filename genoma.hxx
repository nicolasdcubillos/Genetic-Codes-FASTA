#ifndef __GENOMA__HXX__
#define __GENOMA__HXX__

#include <string>
#include <list>
#include <iterator>
#include <vector>

using namespace std;

Genoma::Genoma( ){

}

Genoma::~Genoma( ){

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

void Genoma::cargar (char* nombre_archivo) {
    ifstream lectura; 
    lectura.open(nombre_archivo);
    string line, codigo_genetico;
    std::list <Secuencia> secuencias;

    if (!lectura) { 
        cerr << nombre_archivo << " no se encuentra o no se puede leerse." << endl;
        return;
    }

    if (!sizeof(lectura)) {
        cerr << nombre_archivo << " no contiene ninguna secuencia." << endl;
        return;
    }

    Secuencia secuencia;
    int indice = 0;

    while (getline(lectura, line)) {
        if (line[0] == '>') {
            if (indice++)  { 
                secuencia.setCodigo_genetico(codigo_genetico);
                secuencias.push_back(secuencia);
            }
            secuencia = Secuencia ( );
            secuencia.setDescripcion_secuencia(line.substr(1, line.size()));
            secuencia.setCompleta(true);
            codigo_genetico = "";
        } else {
            if (codigo_genetico == "")
                secuencia.setJustificacion(line.size());

            codigo_genetico.append(line);

            if (line.find("-") != std::string::npos)
                secuencia.setCompleta(false);
        }
    }

    if (!indice || secuencias.empty()) {
        cerr << nombre_archivo << " no contiene ninguna secuencia." << endl;
        return;
    }
        
    secuencia.setCodigo_genetico(codigo_genetico);
    secuencias.push_back(secuencia);
    this->setSecuencias(secuencias);

    if (secuencias.size() == 1)
        cout << "1 secuencia cargada";
    else 
        cout << secuencias.size() << " secuencias cargadas";
        
    cout <<" correctamente desde el archivo " << nombre_archivo << endl;
        
    lectura.close();
}

void Genoma::conteo () {
    if (this->secuencias.size() == 1)
        cout << "1 secuencia";
    else if (this->secuencias.size() > 1)
        cout << this->secuencias.size() << " secuencias";
    else
        cout << "No hay secuencias cargadas";

    cout << " en memoria." << endl;
}

void Genoma::listar_secuencias () {
    if(!secuencias.size())
        cout << "No hay secuencias cargadas en memoria." << endl;

    for (std::list<Secuencia>::iterator ptr = this->secuencias.begin(); ptr != this->secuencias.end(); ptr++) {
        int cantBases = 0;
        string basesUnicas = ptr->unicos_secuencia(); 
        cantBases = basesUnicas.size();

        if (ptr->getCompleta() == true)
            cout << "Secuencia "<< ptr->getDescripcion_secuencia() << " contiene " << cantBases<< " bases." << endl;
        else 
            cout << "Secuencia "<< ptr->getDescripcion_secuencia()<<" contiene al menos "<< cantBases-1 << " bases." << endl;
    }
}

void Genoma::histograma (char* descripcion_secuencia) {
    
    Secuencia secuencia = this->buscarSecuencia(string(descripcion_secuencia));
        
    if (secuencia.getDescripcion_secuencia() == "") {
        cerr << "Secuencia inv" << char (160) << "lida." << endl;
        return;
    }

    int base_filtrada, frecuencia, base;

    string bases_filtradas = secuencia.unicos_secuencia();
    std::vector <int> frecuencias (bases_filtradas.size(), 0);
    
    for (base = 0; base < secuencia.getCodigo_genetico().size(); base++)
        frecuencias[bases_filtradas.find(secuencia.getCodigo_genetico()[base])]++;

    for (base = 0; base < frecuencias.size(); base++)
        cout << bases_filtradas[base] << " : " << frecuencias[base] << endl;
}

void Genoma::es_subsecuencia (char* secuencia) {

    if (!(this->secuencias.size())) {
        cerr << "No hay secuencias cargadas en memoria." << endl;
        return;
    }

    string secuencia_buscar = string (secuencia);
    string codigo_genetico;
    int base, coincidencias = 0, posicion = secuencia_buscar.length() * -1;

    for (std::list<Secuencia>::iterator ptr = secuencias.begin(); ptr != secuencias.end(); ptr++) {
        codigo_genetico = ptr->getCodigo_genetico();
        do {
            posicion = codigo_genetico.find(secuencia_buscar, posicion + secuencia_buscar.length());
            if (posicion != -1) coincidencias++;
        } while (posicion != -1);
    }

    if (coincidencias)
        cout << "La secuencia dada se repite " << coincidencias << " veces." << endl;
    else
        cout << "La secuencia dada no existe." << endl;
}

void Genoma::enmascarar (char* secuencia) {
    
    if (!(this->secuencias.size())) {
        cerr << "No hay secuencias cargadas en memoria." << endl;
        return;
    }

    string secuencia_buscar = string (secuencia);
    string codigo_genetico;
    int base, coincidencias = 0, posicion = secuencia_buscar.length() * -1;

    for (std::list<Secuencia>::iterator ptr = secuencias.begin(); ptr != secuencias.end(); ptr++) {
        codigo_genetico = ptr->getCodigo_genetico();
        do {
            posicion = codigo_genetico.find(secuencia_buscar, posicion + secuencia_buscar.length());
            if (posicion != -1) {
                codigo_genetico.replace(posicion, secuencia_buscar.length(), string(secuencia_buscar.length(), 'X'));
                coincidencias++;
            }
        } while (posicion != -1);
        ptr->setCodigo_genetico(codigo_genetico);
    }
            
    if (coincidencias == 1)
        cout << "1 secuencia ha sido enmascarada." << endl;
    else if (coincidencias > 1)
        cout << coincidencias << " secuencias han sido enmascaradas." << endl;
    else 
        cout << "La secuencia dada no existe, por tanto no se enmascara nada." << endl;
}

void Genoma::guardar (char* nombre_archivo) {
    
    ofstream archivo;
    string nombreArchivo = string (nombre_archivo);

    archivo.open(nombreArchivo.c_str(),ios::out);

    if (archivo.fail()){
        cout << "Error guardando en " << nombreArchivo << endl;
    }

    for (std::list<Secuencia>::iterator ptr = secuencias.begin(); ptr != secuencias.end(); ptr++) {
        archivo << ">" << ptr->getDescripcion_secuencia();
        string codigoGenetico = ptr->getCodigo_genetico();

        for(int i = 0; i < codigoGenetico.size(); i++){
            if(!(i % ptr-> getJustificacion()))
                archivo << endl;
            archivo << codigoGenetico[i];
        }
        archivo << endl;
    }

    if(!archivo.fail())
        cout << "Las secuencias han sido guardadas en " << nombreArchivo << endl;
    
    archivo.close();
}

#endif // __GENOMA__HXX__