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

        } else if (!strcmp(parametros, "decodificar")) {

        } else if (!strcmp(parametros, "ruta_mas_corta")) {

        } else if (!strcmp(parametros, "base_remota")) {

        } else if (!strcmp(parametros, "salir")) {

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