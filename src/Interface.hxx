#ifndef __INTERFACE__HXX__
#define __INTERFACE__HXX__

Interface::Interface( ) {
    
}

Interface::~Interface( ) {

}

bool Interface::checkParams(char* params, int tam) {
    int i = 0;
    char* validation = strtok(params, " ");
    while (validation != NULL) {
        validation = strtok(NULL, " ");
        i++;
    }
    return i == tam;
}

bool Interface::execute(char* command, char* params) {
    if (!strcmp(command, "ayuda")) {
        if (params == NULL) {
            std::cout << " > Lista de comandos disponibles para Componente 1: " << std::endl;
            std::cout << "   $cargar <nombre_archivo>" << std::endl;
            std::cout << "   $conteo" << std::endl;
            std::cout << "   $listar_secuencias" << std::endl;
            std::cout << "   $histograma <descripcion_secuencia>" << std::endl;
            std::cout << "   $es_subsecuencia <subsecuencia>" << std::endl;
            std::cout << "   $enmascarar <secuencia>" << std::endl;
            std::cout << "   $guardar <nombre_archivo>" << std::endl;
            std::cout << "   $salir" << std::endl << std::endl;
                    
            std::cout << " > Lista de comandos disponibles para Componente 2: " << std::endl;
            std::cout << "   $codificar <nombre_archivo.fabin>" << std::endl;
            std::cout << "   $decodificar <nombre_archivo.fabin>" << std::endl << std::endl;
                    
            std::cout << " > Lista de comandos disponibles para Componente 3: " << std::endl;
            std::cout << "   $ruta_mas_corta <descripcion_secuencia> <i> <j> <x> <y>" << std::endl;
            std::cout << "   $base_remota <descripcion_secuencia> <i> <j>" << std::endl << std::endl;

            std::cout << " > $ayuda comando" << std::endl;
            return true;
        }
        if (!strcmp(params, "cargar")) {
            std::cout << " > Comando cargar" << std::endl;
            std::cout << "-- Formato: cargar <nombre_archivo>" << std::endl;
            std::cout << "-- Resultado: [!] Archivo vacio: No contiene ninguna secuencia" << std::endl;
            std::cout << "              [!] Archivo erroneo: No se encuentra o no se puede leer" << std::endl;
            std::cout << "              [-] Una sola secuencia: Solo hay una (1) sola secuencia en el archivo" << std::endl;
            std::cout << "              [-] Varias secuencias: Hay n secuencias cargadas desde el archivo" << std::endl;
            std::cout << "-- Descripcion: Este comando carga en memoria los datos del archivo, utilizando adecuadamente" << std::endl;
            std::cout << "                las estructuras lineales, si ya se habian cargado secuencias antes, este archivo" << std::endl;
            std::cout << "                sobreescribira las existentes" << std::endl;
            
        } else if (!strcmp(params, "conteo")) {
            std::cout << " > Comando conteo" << std::endl;
            std::cout << "-- Formato: conteo" << std::endl;
            std::cout << "-- Resultado: [!] No hay secuencias cargadas: No hay secuencias en memoria" << std::endl;
            std::cout << "              [-] Una sola secuencia: Hay 1 secuencia en memoria" << std::endl;
            std::cout << "              [-] Varias secuencias: Hay 'n' secuencias cargadas en memoria" << std::endl;
            std::cout << "-- Descripcion: Este comando imprime por pantalla la cantidad de secuencias en memoria" << std::endl;

        } else if (!strcmp(params, "listar_secuencias")) {
            std::cout << " > Comando listar_secuencias" << std::endl;
            std::cout << " > Formato: listar_secuencias" << std::endl;
            std::cout << " > Resultado: [!] No hay secuencias cargadas: No contiene ninguna secuencia en memoria" << std::endl;
            std::cout << "              [-] Secuencia completa de archivo no vacio: Se indica la cantidad de bases que tiene" << std::endl;
            std::cout << "                                                          cada secuencia" << std::endl;
            std::cout << "              [-] Secuencia incompleta de archivo no vacio: Se indica la cantidad de bases que al menos tiene" << std::endl;
            std::cout << "> Descripcion: Este comando imprime la informacion basica de cada secuencia" << std::endl;

        } else if (!strcmp(params, "histograma")) {
            std::cout << " > Comando histograma" << std::endl;
            std::cout << "-- Formato: histograma <descripcion_secuencia>" << std::endl;
            std::cout << "-- Resultado: [-] La secuencia no existe: La secuencia indicada es invalida" << std::endl;
            std::cout << "              [-] La secuencia existe: Se imprime por consola cada una de sus frecuencias" << std::endl;
            std::cout << "-- Descripcion: Este comando imprime el histograma de una secuencia. El histograma se define como el conteo" << std::endl;
            std::cout << "                de cada codigo en la secuencia" << std::endl;

        } else if (!strcmp(params, "es_subsecuencia")) {
            std::cout << " > Comando es_subsecuencia" << std::endl;
            std::cout << "-- Formato: es_subsecuencia <secuencia>" << std::endl;
            std::cout << "-- Resultado: [-] No hay secuencias cargadas: No hay secuencias en memoria" << std::endl;
            std::cout << "              [-] La secuencia no existe: La secuencia dada no existe" << std::endl;
            std::cout << "              [-] Varias secuencias: La secuencia indicada se repite n veces" << std::endl;
            std::cout << "-- Descripcion: Este comando deternima si una secuencia dada, existe dentro de las que estan en memoria," << std::endl;
            std::cout << "                si lo esta, tambien defina la cantidad de veces que esta se repite" << std::endl;

        } else if (!strcmp(params, "enmascarar")) {
            std::cout << " > Comando enmascarar" << std::endl;
            std::cout << "-- Formato: enmascarar <secuencia>" << std::endl;
            std::cout << "-- Resultado: [-] No hay secuencias cargadas: No contiene ninguna secuencia en memoria" << std::endl;
            std::cout << "              [-] No se enmascararon subsecuencias: La secuencia no existe y por ende no se enmascaro" << std::endl;
            std::cout << "              [-] Una subsecuencia enmascarada: Solo hay 1 sola secuencia fue enmascarada" << std::endl;
            std::cout << "              [-] Varias secuencias esmascaradas: Hay n secuencias enmascaradas" << std::endl;
            std::cout << "-- Descripcion: Este comando enmascara una secuencia dada por el usuario, los elementos de la subsecuencia" << std::endl;
            std::cout << "                se enmascaran, cambiando cada codigo por 'X'." << std::endl;

        } else if (!strcmp(params, "guardar")) {
            std::cout << " > Comando guardar" << std::endl;
            std::cout << "-- Formato: cargar <nombre_archivo>" << std::endl;
            std::cout << "-- Resultado: [-] No hay secuencias cargadas: No contiene ninguna secuencia en memoria" << std::endl;
            std::cout << "              [-] Escritura exitosa: Indica que las secuencias fueron guardadas en un archivo" << std::endl;
            std::cout << "              [-] Problemas en archivo: Error guardando las secuencias en el archivo" << std::endl;
            std::cout << "-- Descripcion: Este comando guarda en un archivo las secuencias que estan en memoria" << std::endl;

        } else if (!strcmp(params, "codificar")) {
            std::cout << " > Comando codificar" << std::endl;
            std::cout << "-- Formato: codificar <nombre_archivo.fabin>" << std::endl;
            std::cout << "-- Resultado: [-] Mensaje error: Error en guardar las secuencias cargadas en el archivo indicado" << std::endl;
            std::cout << "              [-] Codificacion Exitosa: Secuencias codificadas y almacenadas en el archivo" << std::endl;
            std::cout << "-- Descripcion: Este comando genera el archivo binario con la codificacion Huffman, lo " << std::endl;
            std::cout << "                almacena en disco con el nombre indicado en el parametro del comando" << std::endl;

        } else if (!strcmp(params, "decodificar")) {
            std::cout << " > Comando decodificar" << std::endl;
            std::cout << "-- Formato: decodificar <nombre_archivo.fabin>" << std::endl;
            std::cout << "-- Resultado: [-] Mensaje error: Error en cargar las secuencias en el archivo indicado" << std::endl;
            std::cout << "              [-] Decodificacion Exitosa: Secuencias decodificadas desde el archivo indicado" << std::endl;
            std::cout << "                  y cargadas en memoria" << std::endl;
            std::cout << "-- Descripcion: Este comando carga en memoria las secuencias del archivo, si en la sesion ya" << std::endl;
            std::cout << "                se han cargado secuencias con este comando, la informacion se sobreescribira" << std::endl;
            
        } else if (!strcmp(params, "ruta_mas_corta")) {
            std::cout << " > Comando ruta_mas_corta" << std::endl;
            std::cout << "-- Formato: ruta_mas_corta <descripcion_secuencia <i> <j> <x> <y>" << std::endl;
            std::cout << "-- Resultado: [-] La secuencia no existe: La secuencia cargada en el parametro no existe" << std::endl;
            std::cout << "              [-] Posicion de base origen invalida: La base en la posicion [i ,j ] no existe." << std::endl;
            std::cout << "              [-] Posicion de base destino invalida: La base en la posicion [x ,y ] no existe." << std::endl;
            std::cout << "              [-] La secuencia existe: Se indica la ruta mas corta entre la base origen y destino," << std::endl;
            std::cout << "                  indicando cual es y ademas cual es el costo total de la ruta" << std::endl;
            std::cout << "-- Descripcion: Este comando muestra la secuencia de vertices del grafo que describe la ruta" << std::endl;
            std::cout << "                mas corta entre la base origen y destino, ademas indica cual es el costo total" << std::endl;
            std::cout << "                de la ruta, teniendo en cuenta el peso de las conexiones entre las bases" << std::endl;

        } else if (!strcmp(params, "base_remota")) {
            std::cout << " > Comando base_remota" << std::endl;
            std::cout << "-- Formato: base_remota <descripcion_secuencia> <i> <j>" << std::endl;
            std::cout << "-- Resultado: [-] La secuencia no existe: La secuencia cargada en el parametro no existe" << std::endl;
            std::cout << "              [-] Posicion de base invalida: La base en la posicion [i ,j ] no existe." << std::endl;
            std::cout << "              [-] La base existe: Se indica la ruta entre la base indicada y la base remota " << std::endl;
            std::cout << "                  de la secuencia indicada, ademas indicando el costo total de la ruta" << std::endl;
            std::cout << "-- Descripcion: Este comando busca la ubicacion de la misma base mas lejana dentro de la matriz" << std::endl;
            std::cout << "                para esto, se muestra por pantalla su ubicacion, la secuencia de vertices que" << std::endl;
            std::cout << "                describen la ruta entre esa base origen y base remota, ademas indicando el costo" << std::endl;
            std::cout << "                total de la ruta, teniendo en cuenta el peso de las conexiones entre bases" << std::endl;

        } else if (!strcmp(params, "salir")) {
            std::cout << " > Comando salir" << std::endl;
            std::cout << "-- Formato: salir" << std::endl;
            std::cout << "-- Descripcion: Este comando termina la sesion y sale del programa" << std::endl;          
        } else {
            std::cout << " > Lista de comandos disponibles para Componente 1: " << std::endl;
            std::cout << "   $cargar <nombre_archivo>" << std::endl;
            std::cout << "   $conteo" << std::endl;
            std::cout << "   $listar_secuencias" << std::endl;
            std::cout << "   $histograma <descripcion_secuencia>" << std::endl;
            std::cout << "   $es_subsecuencia <subsecuencia>" << std::endl;
            std::cout << "   $enmascarar <secuencia>" << std::endl;
            std::cout << "   $guardar <nombre_archivo>" << std::endl;
            std::cout << "   $salir" << std::endl << std::endl;
                    
            std::cout << "-> Lista de comandos disponibles para Componente 2: " << std::endl;
            std::cout << "   $codificar <nombre_archivo.fabin>" << std::endl;
            std::cout << "   $decodificar <nombre_archivo.fabin>" << std::endl << std::endl;
                    
            std::cout << "-> Lista de comandos disponibles para Componente 3: " << std::endl;
            std::cout << "   $ruta_mas_corta <descripcion_secuencia> <i> <j> <x> <y>" << std::endl;
            std::cout << "   $base_remota <descripcion_secuencia> <i> <j>" << std::endl << std::endl;

            std::cout << "-> $ayuda comando" << std::endl;
            return false;
        }
        return true;
    }

    if (!strcmp(command, "cargar")) {
        if (!checkParams(params, 1)) return false;
        controller.cargar(params);
        return true;
    }

    if (!strcmp(command, "conteo")) {
        if (!checkParams(params, 0)) return false;
        controller.conteo();
        return true;
    }

    if (!strcmp(command, "listar_secuencias")) {
        if (!checkParams(params, 0)) return false;
        controller.listar_secuencias();
        return true;
    }

    if (!strcmp(command, "histograma")) {
        if (!checkParams(params, 1)) return false;
        vector <string> histograma = controller.histograma(params);
        int base;
        if (histograma.size() > 0) {
            for (base = 0; base < histograma.size(); base += 2) 
                std::cout << histograma[base] << " : " << histograma[base + 1] << std::endl;
        }
        else 
            cerr << "Secuencia inv" << char (160) << "lida." << std::endl;

        return true;
    }

    if (!strcmp(command, "es_subsecuencia")) {
        if (!checkParams(params, 1)) return false;

        int coincidencias = controller.es_subsecuencia(params);

        if (coincidencias > 0)
            std::cout << "La secuencia dada se repite " << coincidencias << " veces." << std::endl;
        else if (coincidencias == -1)
            cerr << "No hay secuencias cargadas en memoria." << std::endl;
        else
            cerr << "La secuencia dada no existe." << std::endl;

        return true;
    }

    if (!strcmp(command, "enmascarar")) {
        if (!checkParams(params, 1)) return false;
        controller.enmascarar(params);
        return true;
    }

    if (!strcmp(command, "guardar")) {
        if (!checkParams(params, 1)) return false;
        controller.guardar(params);
        return true;
    }

    if (!strcmp(command, "salir")) {
        return checkParams(params, 0);
    }

    if (!strcmp(command, "codificar")) {
        if (!checkParams(params, 1)) return false;
        controller.codificar(params);
        return true;
    }

    if (!strcmp(command, "decodificar")) {
        if (!checkParams(params, 1)) return false;
        controller.decodificar(params);
        return true;
    }

    if (!strcmp(command, "ruta_mas_corta")) {
        return checkParams(params, 5);
    }

    if (!strcmp(command, "base_remota")) {
        return checkParams(params, 3);
    }

    return false;
}

void Interface::Start( ) {
    char* line = new char [MAX_TAM_CHAR];
    char* command = new char [MAX_TAM_CHAR];
    char* params = new char [MAX_TAM_CHAR];
    do {
        std::cout << "$";
        cin.getline(line, MAX_TAM_CHAR);
        char* token = strtok(line, " ");
        strcpy(command, token);
        token = strtok(NULL, "\n");
        strcpy(params, token != NULL ? token : "");

        if (!execute(command, params))
            std::cout << "Comando invalido.\nEjecute $ayuda o $ayuda [comando] para conocer mas acerca de los comandos." << std::endl << std::endl;
            
    } while (strcmp(line, "salir"));
}

#endif