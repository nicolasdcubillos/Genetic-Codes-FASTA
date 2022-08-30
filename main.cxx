#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include "secuencia.h"
#include "genoma.h"

#define MAX_TAM_CHAR 256

/*
    PONTIFICIA UNIVERSIDAD JAVERIANA
         ESTRUCTURAS DE DATOS
         PROYECTO - ENTREGA 1
         30 DE AGOSTO DE 2022

    INTEGRANTES:    NICOLÁS DAVID CUBILLOS CUBILLOS
                    ANGELLO MATEO JAIMES RINCÓN
                    ESTEBAN ALBERTO ROJAS MOLINA
*/

using namespace std;

Genoma genoma;

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
            cout << " > Lista de comandos disponibles para Componente 1: " << endl;
            cout << "   $cargar <nombre_archivo>" << endl;
            cout << "   $conteo" << endl;
            cout << "   $listar_secuencias" << endl;
            cout << "   $histograma <descripcion_secuencia>" << endl;
            cout << "   $es_subsecuencia <subsecuencia>" << endl;
            cout << "   $enmascarar <secuencia>" << endl;
            cout << "   $guardar <nombre_archivo>" << endl;
            cout << "   $salir" << endl << endl;
                    
            cout << " > Lista de comandos disponibles para Componente 2: " << endl;
            cout << "   $codificar <nombre_archivo.fabin>" << endl;
            cout << "   $decodificar <nombre_archivo.fabin>" << endl << endl;
                    
            cout << " > Lista de comandos disponibles para Componente 3: " << endl;
            cout << "   $ruta_mas_corta <descripcion_secuencia> <i> <j> <x> <y>" << endl;
            cout << "   $base_remota <descripcion_secuencia> <i> <j>" << endl << endl;

            cout << " > $ayuda comando" << endl;
            return true;
        }
        if (!strcmp(parametros, "cargar")) {
            cout << " > Comando cargar" << endl;
            cout << "-- Formato: cargar <nombre_archivo>" << endl;
            cout << "-- Resultado: [!] Archivo vacio: No contiene ninguna secuencia" << endl;
            cout << "              [!] Archivo erroneo: No se encuentra o no se puede leer" << endl;
            cout << "              [-] Una sola secuencia: Solo hay una (1) sola secuencia en el archivo" << endl;
            cout << "              [-] Varias secuencias: Hay n secuencias cargadas desde el archivo" << endl;
            cout << "-- Descripcion: Este comando carga en memoria los datos del archivo, utilizando adecuadamente" << endl;
            cout << "                las estructuras lineales, si ya se habian cargado secuencias antes, este archivo" << endl;
            cout << "                sobreescribira las existentes" << endl;
            
        } else if (!strcmp(parametros, "conteo")) {
            cout << " > Comando conteo" << endl;
            cout << "-- Formato: conteo" << endl;
            cout << "-- Resultado: [!] No hay secuencias cargadas: No hay secuencias en memoria" << endl;
            cout << "              [-] Una sola secuencia: Hay 1 secuencia en memoria" << endl;
            cout << "              [-] Varias secuencias: Hay 'n' secuencias cargadas en memoria" << endl;
            cout << "-- Descripcion: Este comando imprime por pantalla la cantidad de secuencias en memoria" << endl;

        } else if (!strcmp(parametros, "listar_secuencias")) {
            cout << " > Comando listar_secuencias" << endl;
            cout << " > Formato: listar_secuencias" << endl;
            cout << " > Resultado: [!] No hay secuencias cargadas: No contiene ninguna secuencia en memoria" << endl;
            cout << "              [-] Secuencia completa de archivo no vacio: Se indica la cantidad de bases que tiene" << endl;
            cout << "                                                          cada secuencia" << endl;
            cout << "              [-] Secuencia incompleta de archivo no vacio: Se indica la cantidad de bases que al menos tiene" << endl;
            cout << "> Descripcion: Este comando imprime la informacion basica de cada secuencia" << endl;

        } else if (!strcmp(parametros, "histograma")) {
            cout << " > Comando histograma" << endl;
            cout << "-- Formato: histograma <descripcion_secuencia>" << endl;
            cout << "-- Resultado: [-] La secuencia no existe: La secuencia indicada es invalida" << endl;
            cout << "              [-] La secuencia existe: Se imprime por consola cada una de sus frecuencias" << endl;
            cout << "-- Descripcion: Este comando imprime el histograma de una secuencia. El histograma se define como el conteo" << endl;
            cout << "                de cada codigo en la secuencia" << endl;

        } else if (!strcmp(parametros, "es_subsecuencia")) {
            cout << " > Comando es_subsecuencia" << endl;
            cout << "-- Formato: es_subsecuencia <secuencia>" << endl;
            cout << "-- Resultado: [-] No hay secuencias cargadas: No hay secuencias en memoria" << endl;
            cout << "              [-] La secuencia no existe: La secuencia dada no existe" << endl;
            cout << "              [-] Varias secuencias: La secuencia indicada se repite n veces" << endl;
            cout << "-- Descripcion: Este comando deternima si una secuencia dada, existe dentro de las que estan en memoria," << endl;
            cout << "                si lo esta, tambien defina la cantidad de veces que esta se repite" << endl;

        } else if (!strcmp(parametros, "enmascarar")) {
            cout << " > Comando enmascarar" << endl;
            cout << "-- Formato: enmascarar <secuencia>" << endl;
            cout << "-- Resultado: [-] No hay secuencias cargadas: No contiene ninguna secuencia en memoria" << endl;
            cout << "              [-] No se enmascararon subsecuencias: La secuencia no existe y por ende no se enmascaro" << endl;
            cout << "              [-] Una subsecuencia enmascarada: Solo hay 1 sola secuencia fue enmascarada" << endl;
            cout << "              [-] Varias secuencias esmascaradas: Hay n secuencias enmascaradas" << endl;
            cout << "-- Descripcion: Este comando enmascara una secuencia dada por el usuario, los elementos de la subsecuencia" << endl;
            cout << "                se enmascaran, cambiando cada codigo por 'X'." << endl;

        } else if (!strcmp(parametros, "guardar")) {
            cout << " > Comando guardar" << endl;
            cout << "-- Formato: cargar <nombre_archivo>" << endl;
            cout << "-- Resultado: [-] No hay secuencias cargadas: No contiene ninguna secuencia en memoria" << endl;
            cout << "              [-] Escritura exitosa: Indica que las secuencias fueron guardadas en un archivo" << endl;
            cout << "              [-] Problemas en archivo: Error guardando las secuencias en el archivo" << endl;
            cout << "-- Descripcion: Este comando guarda en un archivo las secuencias que estan en memoria" << endl;

        } else if (!strcmp(parametros, "codificar")) {
            cout << " > Comando codificar" << endl;
            cout << "-- Formato: codificar <nombre_archivo.fabin>" << endl;
            cout << "-- Resultado: [-] Mensaje error: Error en guardar las secuencias cargadas en el archivo indicado" << endl;
            cout << "              [-] Codificacion Exitosa: Secuencias codificadas y almacenadas en el archivo" << endl;
            cout << "-- Descripcion: Este comando genera el archivo binario con la codificacion Huffman, lo " << endl;
            cout << "                almacena en disco con el nombre indicado en el parametro del comando" << endl;

        } else if (!strcmp(parametros, "decodificar")) {
            cout << " > Comando decodificar" << endl;
            cout << "-- Formato: decodificar <nombre_archivo.fabin>" << endl;
            cout << "-- Resultado: [-] Mensaje error: Error en cargar las secuencias en el archivo indicado" << endl;
            cout << "              [-] Decodificacion Exitosa: Secuencias decodificadas desde el archivo indicado" << endl;
            cout << "                  y cargadas en memoria" << endl;
            cout << "-- Descripcion: Este comando carga en memoria las secuencias del archivo, si en la sesion ya" << endl;
            cout << "                se han cargado secuencias con este comando, la informacion se sobreescribira" << endl;
            
        } else if (!strcmp(parametros, "ruta_mas_corta")) {
            cout << " > Comando ruta_mas_corta" << endl;
            cout << "-- Formato: ruta_mas_corta <descripcion_secuencia <i> <j> <x> <y>" << endl;
            cout << "-- Resultado: [-] La secuencia no existe: La secuencia cargada en el parametro no existe" << endl;
            cout << "              [-] Posicion de base origen invalida: La base en la posicion [i ,j ] no existe." << endl;
            cout << "              [-] Posicion de base destino invalida: La base en la posicion [x ,y ] no existe." << endl;
            cout << "              [-] La secuencia existe: Se indica la ruta mas corta entre la base origen y destino," << endl;
            cout << "                  indicando cual es y ademas cual es el costo total de la ruta" << endl;
            cout << "-- Descripcion: Este comando muestra la secuencia de vertices del grafo que describe la ruta" << endl;
            cout << "                mas corta entre la base origen y destino, ademas indica cual es el costo total" << endl;
            cout << "                de la ruta, teniendo en cuenta el peso de las conexiones entre las bases" << endl;

        } else if (!strcmp(parametros, "base_remota")) {
            cout << " > Comando base_remota" << endl;
            cout << "-- Formato: base_remota <descripcion_secuencia> <i> <j>" << endl;
            cout << "-- Resultado: [-] La secuencia no existe: La secuencia cargada en el parametro no existe" << endl;
            cout << "              [-] Posicion de base invalida: La base en la posicion [i ,j ] no existe." << endl;
            cout << "              [-] La base existe: Se indica la ruta entre la base indicada y la base remota " << endl;
            cout << "                  de la secuencia indicada, ademas indicando el costo total de la ruta" << endl;
            cout << "-- Descripcion: Este comando busca la ubicacion de la misma base mas lejana dentro de la matriz" << endl;
            cout << "                para esto, se muestra por pantalla su ubicacion, la secuencia de vertices que" << endl;
            cout << "                describen la ruta entre esa base origen y base remota, ademas indicando el costo" << endl;
            cout << "                total de la ruta, teniendo en cuenta el peso de las conexiones entre bases" << endl;

        } else if (!strcmp(parametros, "salir")) {
            cout << " > Comando salir" << endl;
            cout << "-- Formato: salir" << endl;
            cout << "-- Descripcion: Este comando termina la sesion y sale del programa" << endl;          
        } else {
            cout << " > Lista de comandos disponibles para Componente 1: " << endl;
            cout << "   $cargar <nombre_archivo>" << endl;
            cout << "   $conteo" << endl;
            cout << "   $listar_secuencias" << endl;
            cout << "   $histograma <descripcion_secuencia>" << endl;
            cout << "   $es_subsecuencia <subsecuencia>" << endl;
            cout << "   $enmascarar <secuencia>" << endl;
            cout << "   $guardar <nombre_archivo>" << endl;
            cout << "   $salir" << endl << endl;
                    
            cout << "-> Lista de comandos disponibles para Componente 2: " << endl;
            cout << "   $codificar <nombre_archivo.fabin>" << endl;
            cout << "   $decodificar <nombre_archivo.fabin>" << endl << endl;
                    
            cout << "-> Lista de comandos disponibles para Componente 3: " << endl;
            cout << "   $ruta_mas_corta <descripcion_secuencia> <i> <j> <x> <y>" << endl;
            cout << "   $base_remota <descripcion_secuencia> <i> <j>" << endl << endl;

            cout << "-> $ayuda comando" << endl;
            return false;
        }
        return true;
    }

    if (!strcmp(comando, "cargar")) {
        if (!validar_cantidad_parametros(parametros, 1)) return false;
        genoma.cargar(parametros);
        return true;
    }

    if (!strcmp(comando, "conteo")) {
        if (!validar_cantidad_parametros(parametros, 0)) return false;
        genoma.conteo();
        return true;
    }

    if (!strcmp(comando, "listar_secuencias")) {
        if (!validar_cantidad_parametros(parametros, 0)) return false;
        genoma.listar_secuencias();
        return true;
    }

    if (!strcmp(comando, "histograma")) {
        if (!validar_cantidad_parametros(parametros, 1)) return false;
        genoma.histograma(parametros);
        return true;
    }

    if (!strcmp(comando, "es_subsecuencia")) {
        if (!validar_cantidad_parametros(parametros, 1)) return false;
        genoma.es_subsecuencia(parametros);
        return true;
    }

    if (!strcmp(comando, "enmascarar")) {
        if (!validar_cantidad_parametros(parametros, 1)) return false;
        genoma.enmascarar(parametros);
        return true;
    }

    if (!strcmp(comando, "guardar")) {
        if (!validar_cantidad_parametros(parametros, 1)) return false;
        genoma.guardar(parametros);
        return true;
    }

    if (!strcmp(comando, "salir")) {
        return validar_cantidad_parametros(parametros, 0);
    }

    if (!strcmp(comando, "codificar")) {
        return validar_cantidad_parametros(parametros, 1);
    }

    if (!strcmp(comando, "decodificar")) {
        return validar_cantidad_parametros(parametros, 1);
    }

    if (!strcmp(comando, "ruta_mas_corta")) {
        return validar_cantidad_parametros(parametros, 5);
    }

    if (!strcmp(comando, "base_remota")) {
        return validar_cantidad_parametros(parametros, 3);
    }

    return false;
}

void menu () {
    char* linea = new char [MAX_TAM_CHAR];
    char* comando = new char [MAX_TAM_CHAR];
    char* parametros = new char [MAX_TAM_CHAR];
    do {
        cout << "$";
        cin.getline(linea, MAX_TAM_CHAR);
        char* token = strtok(linea, " ");
        strcpy(comando, token);
        token = strtok(NULL, "\n");
        strcpy(parametros, token != NULL ? token : "");
        bool parametros_validos = ejecutar_comando(comando, parametros);

        if (!parametros_validos)
            cout << "Comando invalido.\nEjecute $ayuda o $ayuda [comando] para conocer mas acerca de los comandos." << endl << endl;
            
    } while (strcmp(linea, "salir"));
}

int main () {
    menu();
}

