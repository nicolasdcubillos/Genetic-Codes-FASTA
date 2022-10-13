#ifndef __GENOMA__HXX__
#define __GENOMA__HXX__

#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

Genoma::Genoma( ) {
    this->huffmanTree = new HuffmanTree( );
}

Genoma::~Genoma( ) {

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
        
    secuencia.setCodigo_genetico(codigo_genetico);
    secuencias.push_back(secuencia);
    this->setSecuencias(secuencias);

    if (secuencias.empty()) {
        cerr << nombre_archivo << " no contiene ninguna secuencia." << endl;
        return;
    }

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
        int cantidad = 0;
        string basesUnicas = ptr->unicos_secuencia(); 
        cantidad = basesUnicas.size();

        if (ptr->getCompleta() == true)
            cout << "Secuencia " << ptr->getDescripcion_secuencia() << " contiene " << cantidad << " bases." << endl;
        else 
            cout << "Secuencia " << ptr->getDescripcion_secuencia() << " contiene al menos " << cantidad - 1 << " bases." << endl;
    }
}

std::vector<string> Genoma::histograma (char* descripcion_secuencia) {
    
    Secuencia secuencia = this->buscarSecuencia(string(descripcion_secuencia));
    
    std::vector <string> respuesta;
    if (secuencia.getDescripcion_secuencia() == "")
        return respuesta;

    int base, posicion = 0;

    string bases_filtradas = secuencia.unicos_secuencia();
    std::vector <int> frecuencias (bases_filtradas.size(), 0);
    
    string codigo_genetico = secuencia.getCodigo_genetico();

    for (int i = 0; i < bases_filtradas.length(); i++) {
        posicion = -1;
        do {
            posicion = codigo_genetico.find(bases_filtradas[i], posicion + 1);
            if (posicion != -1) frecuencias[i]++;
        } while (posicion != -1);
    }

    for (base = 0; base < frecuencias.size(); base++) {
        respuesta.push_back(string(1, bases_filtradas[base]));
        respuesta.push_back(to_string(frecuencias[base]));
    }

    return respuesta;
}

std::vector<string> Genoma::histogramaGeneral () {

    string codigo_genetico = "";

    for (std::list<Secuencia>::iterator ptr = secuencias.begin(); ptr != secuencias.end(); ptr++)
        codigo_genetico += ptr->getCodigo_genetico();
    
    std::vector <string> respuesta;

    int base, posicion = 0;

    string bases_filtradas = unicos_secuencia();
    std::vector <int> frecuencias (bases_filtradas.size(), 0);

    for (int i = 0; i < bases_filtradas.length(); i++) {
        posicion = -1;
        do {
            posicion = codigo_genetico.find(bases_filtradas[i], posicion + 1);
            if (posicion != -1) frecuencias[i]++;
        } while (posicion != -1);
    }

    for (base = 0; base < frecuencias.size(); base++) {
        respuesta.push_back(string(1, bases_filtradas[base]));
        respuesta.push_back(to_string(frecuencias[base]));
    }

    return respuesta;
}

int Genoma::es_subsecuencia (char* secuencia) {

    if (!(this->secuencias.size()))
        return -1;

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

    return coincidencias;
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

    archivo.open(nombreArchivo.c_str(), ios::out);

    if (archivo.fail()) {
        cout << "Error guardando en " << nombreArchivo << endl;
        return;
    }

    for (std::list<Secuencia>::iterator ptr = secuencias.begin(); ptr != secuencias.end(); ptr++) {
        archivo << ">" << ptr->getDescripcion_secuencia();
        string codigoGenetico = ptr->getCodigo_genetico();

        for (int i = 0; i < codigoGenetico.size(); i++) {
            if (!(i % ptr-> getJustificacion()))
                archivo << endl;
            archivo << codigoGenetico[i];
        }
        archivo << endl;
    }

    if (!archivo.fail())
        cout << "Las secuencias han sido guardadas en " << nombreArchivo << endl;
    
    archivo.close();
}

void Genoma::codificar (char* nombre_archivo) {
    ofstream archivo (nombre_archivo, ios::binary);

    if (!archivo) {
        cerr << "No se pueden guardar las secuencias cargadas en " << nombre_archivo << "." << endl;
        return;
    }

    int n = unicos_secuencia().length();
    cout << "n: " << n << endl;

    vector < string > histograma = histogramaGeneral();

    std::priority_queue < HuffmanNode*, vector < HuffmanNode* >, HuffmanNode > priorityQueue;
    
    for (int c = 0; c < histograma.size(); c += 2) {
        HuffmanNode* node = new HuffmanNode(histograma [c][0], stoul(histograma [c + 1], 0, 10));
        priorityQueue.push(node);
    }

    this->huffmanTree = new HuffmanTree(priorityQueue);

    while (!priorityQueue.empty()) {
        cout << *priorityQueue.top() << endl;
        priorityQueue.pop();
    }

    cout << endl;
    
    int ns = secuencias.size();
    cout << "ns: " << ns << endl << endl;

    for (std::list<Secuencia>::iterator ptr = secuencias.begin(); ptr != secuencias.end(); ptr++) {
        int l = ptr->getDescripcion_secuencia().size();
        cout << "l: " << l << endl;
        cout << "s: " << ptr->getDescripcion_secuencia() << endl;
        int w;
        cout << "w: " << ptr->getCodigo_genetico().size() << endl;
        int x = ptr->getJustificacion();
        cout << "x: " << x << endl;
        cout << "binarycode." << endl;
    }

    cout << "Secuencias codificadas y almacenadas en " << nombre_archivo << "." << endl;

    archivo.close();
}

void Genoma::decodificar (char* nombre_archivo) {
    ifstream archivo (nombre_archivo, ios::binary);

    if (!archivo) {
        cerr << "No se pueden cargar las secuencias en " << nombre_archivo << "." << endl;
        return;
    }

    cout << "Secuencias decodificadas desde " << nombre_archivo << " y cargadas en memoria." << endl;

    archivo.close();
}

std::string Genoma::unicos_secuencia() {
    string secuenciaUnicos;
    string secuenciaPrincipal = "";

    for (std::list<Secuencia>::iterator ptr = secuencias.begin(); ptr != secuencias.end(); ptr++)
        secuenciaPrincipal += ptr->getCodigo_genetico();
    

    for (int i = 0; i < secuenciaPrincipal.size(); i++)
        if (secuenciaUnicos.find(secuenciaPrincipal[i]) == std::string::npos)
            secuenciaUnicos.append(std::string(1, secuenciaPrincipal[i]));
    
    return secuenciaUnicos;
}

#endif // __GENOMA__HXX__