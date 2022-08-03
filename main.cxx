#include <iostream>
#include <string.h>

#define MAX_TAM_CHAR 256

using namespace std;

bool validar_cantidad_parametros(char* parametros, int cantidad) {
    int i = 0;
    char* validacion = strtok(parametros, " ");
    while (validacion != NULL) {
        validacion = strtok(NULL, " ");
        i++;
    }
    return i == cantidad ? true : false;
}

bool ejecutar_comando(char* comando, char* parametros) {
    if (!strcmp(comando, "ayuda")) {
        if (parametros == NULL) {
            cout << "-> Lista de comandos disponibles para Componente 1: " << endl;
            cout << "   $cargar nombre_archivo" << endl;
            cout << "   $conteo" << endl;
            cout << "   $listar_secuencias" << endl;
            cout << "   $histograma descripcion_secuencia" << endl;
            cout << "   $es_subsecuencia subsecuencia" << endl;
            cout << "   $enmascarar secuencia" << endl;
            cout << "   $guardar nombre_archivo" << endl;
            cout << "   $salir" << endl << endl;
                    
            cout << "-> Lista de comandos disponibles para Componente 2: " << endl;
            cout << "   $codificar nombre_archivo.fabin" << endl;
            cout << "   $decodificar nombre_archivo.fabin" << endl << endl;
                    
            cout << "-> Lista de comandos disponibles para Componente 3: " << endl;
            cout << "   $ruta_mas_corta descripcion_secuencia i j x y" << endl;
            cout << "   $base_remota descripcion_secuencia i j" << endl << endl;

            cout << "-> $ayuda comando" << endl;
            return true;
        }
        if (!strcmp(parametros, "cargar")) {
            
        } else if (!strcmp(parametros, "conteo")) {

        } else if (!strcmp(parametros, "listar_secuencias")) {

        } else if (!strcmp(parametros, "histograma")) {

        } else if (!strcmp(parametros, "es_subsecuencia")) {

        } else if (!strcmp(parametros, "enmascarar")) {

        } else if (!strcmp(parametros, "guardar")) {

        } else if (!strcmp(parametros, "codificar")) {
            cout<<"-> Comando codificar"<<endl;
            cout<<"-- Formato: codificar nombre_archivo.fabin"<<endl;
            cout<<"-- Resultado: -Mensaje error = Error en guardar las secuencias cargadas en el archivo indicado"<<endl;
            cout<<"              -Codificacion Exitosa = Secuencias codificadas y almacenadas en el archivo"<<endl;
            cout<<"-- Descripcion: Este comando genera el archivo binario con la codificacion Huffman, lo "<<endl;
            cout<<"                almacena en disco con el nombre indicado en el parametro del comando"<<endl;

        } else if (!strcmp(parametros, "decodificar")) {
            cout<<"-> Comando decodificar"<<endl;
            cout<<"-- Formato: decodificar nombre_archivo.fabin"<<endl;
            cout<<"-- Resultado: -Mensaje error = Error en cargar las secuencias en el archivo indicado"<<endl;
            cout<<"              -Decodificacion Exitosa = Secuencias decodificadas desde el archivo indicado"<<endl;
            cout<<"               y cargadas en memoria"<<endl;
            cout<<"-- Descripcion: Este comando carga en memoria las secuencias del archivo, si en la sesion ya"<<endl;
            cout<<"                se han cargado secuencias con este comando, la informacion se sobreescribira"<<endl;
            
        } else if (!strcmp(parametros, "ruta_mas_corta")) {
            cout<<"-> Comando ruta_mas_corta"<<endl;
            cout<<"-- Formato: ruta_mas_corta descripcion_secuencia i j x y"<<endl;
            cout<<"-- Resultado: -La secuencia no existe = La secuencia cargada en el parametro no existe"<<endl;
            cout<<"              -Posicion de base origen invalida = La base en la posicion [i ,j ] no existe."<<endl;
            cout<<"              -Posicion de base destino invalida = La base en la posicion [x ,y ] no existe."<<endl;
            cout<<"              -La secuencia existe = Se indica la ruta mas corta entre la base origen y destino,"<<endl;
            cout<<"                indicando cual es y ademas cual es el costo total de la ruta"<<endl;
            cout<<"-- Descripcion: Este comando muestra la secuencia de vertices del grafo que describe la ruta"<<endl;
            cout<<"                mas corta entre la base origen y destino, ademas indica cual es el costo total"<<endl;
            cout<<"                de la ruta, teniendo en cuenta el peso de las conexiones entre las bases"<<endl;

        } else if (!strcmp(parametros, "base_remota")) {
            cout<<"-> Comando base_remota"<<endl;
            cout<<"-- Formato: base_remota descripcion_secuencia i j"<<endl;
            cout<<"-- Resultado: -La secuencia no existe = La secuencia cargada en el parametro no existe"<<endl;
            cout<<"              -Posicion de base invalida = La base en la posicion [i ,j ] no existe."<<endl;
            cout<<"              -La base existe = Se indica la ruta entre la base indicada y la base remota "<<endl;
            cout<<"                de la secuencia indicada, ademas indicando el costo total de la ruta"<<endl;
            cout<<"-- Descripcion: Este comando busca la ubicacion de la misma base mas lejana dentro de la matriz"<<endl;
            cout<<"                para esto, se muestra por pantalla su ubicacion, la secuencia de vertices que"<<endl;
            cout<<"                describen la ruta entre esa base origen y base remota, ademas indicando el costo"<<endl;
            cout<<"                total de la ruta, teniendo en cuenta el peso de las conexiones entre bases"<<endl;

        } else if (!strcmp(parametros, "salir")) {
            cout<<"-> Comando salir"<<endl;
            cout<<"-- Formato: salir"<<endl;
            cout<<"-- Descripcion: Este comando termina la sesion y sale del programa"<<endl;          
        } else {
            cout << "-> Lista de comandos disponibles para Componente 1: " << endl;
            cout << "   $cargar nombre_archivo" << endl;
            cout << "   $conteo" << endl;
            cout << "   $listar_secuencias" << endl;
            cout << "   $histograma descripcion_secuencia" << endl;
            cout << "   $es_subsecuencia subsecuencia" << endl;
            cout << "   $enmascarar secuencia" << endl;
            cout << "   $guardar nombre_archivo" << endl;
            cout << "   $salir" << endl << endl;
                    
            cout << "-> Lista de comandos disponibles para Componente 2: " << endl;
            cout << "   $codificar nombre_archivo.fabin" << endl;
            cout << "   $decodificar nombre_archivo.fabin" << endl << endl;
                    
            cout << "-> Lista de comandos disponibles para Componente 3: " << endl;
            cout << "   $ruta_mas_corta descripcion_secuencia i j x y" << endl;
            cout << "   $base_remota descripcion_secuencia i j" << endl << endl;

            cout << "-> $ayuda comando" << endl;
            return false;
        }
        return true;
    }

    if (!strcmp(comando, "cargar")) {
        return validar_cantidad_parametros(parametros, 1);
    }

    if (!strcmp(comando, "conteo")) {
        return validar_cantidad_parametros(parametros, 0);
    }

    return false;
}

void menu () {
    char* linea = new char [MAX_TAM_CHAR];
    do {
        cin.getline(linea, MAX_TAM_CHAR);
        if (*linea == '$') {
            char* parametros = new char [MAX_TAM_CHAR];
            char* comando = strtok(linea, "$");
            parametros = strtok(comando, " ");
            parametros = strtok(NULL, "\n");
            bool parametros_validos = ejecutar_comando(comando, parametros);

            if (parametros_validos)
                cout << "Comando " << comando << " valido." << endl << endl;
            else 
                cout << "Comando invalido.\nEjecute $ayuda o $ayuda [comando] para conocer mas acerca de los comandos." << endl << endl;
            
        }
    } while (strcmp(linea, "$salir"));
}

int main () {
    menu();
}