#ifndef __CONTROLLER__HXX__
#define __CONTROLLER__HXX__

#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <queue>
#include <cstdlib>
#include <math.h>

Controller::Controller( ) {
    this->huffmanTree = new HuffmanTree( );
}

Controller::~Controller( ) {

}

void Controller::setSequences( std::list<Sequence> sequences ) {
    this->sequences = sequences;
}

std::list<Sequence> Controller::getSequences( ){
    return this->sequences;
}

Sequence Controller::findSequence( std::string description ) {
    Sequence sequence;

    for (std::list<Sequence>::iterator ptr = this->sequences.begin(); ptr != this->sequences.end(); ptr++) 
        if (ptr->getDescription() == description)
            return *ptr;
        
    return sequence;
}

void Controller::cargar( char* fileName ) {
    ifstream file; 
    file.open(fileName);
    string line, genetic_code;
    std::list < Sequence > sequences;

    if (!file) { 
        std::cerr << fileName << " no se encuentra o no se puede leerse." << std::endl;
        return;
    }

    if (!sizeof(file)) {
        std::cerr << fileName << " no contiene ninguna secuencia." << std::endl;
        return;
    }

    Sequence sequence;
    int indice = 0, row = 0;
    unsigned short justification;
    Graph < char, float > * graph;

    while (getline(file, line)) {
        if (line[0] == '>') {
            if (indice++)  { 
                sequence.setGraph(graph);
                sequence.setGenetic_code(genetic_code);
                sequences.push_back(sequence);
            }
            graph = new Graph < char, float > ( );
            sequence = Sequence ( );
            sequence.setDescription(line.substr(1, line.size()));
            genetic_code = "";
            row = 0;
        } else {
            if (genetic_code == "") {
                sequence.setJustification(line.size( ));
                justification = line.size( );
            }

            genetic_code.append(line);

            for (int i = 0; i < line.size( ); i++) {
                graph->AddVertex(line[i]);
                
                if (row) graph->AddEdge(( row * justification ) + i, ( ( row - 1 ) * justification ) + i, 
                        1 / ( 1 + ( float ) graph->GetVertex(( ( row - 1 ) * justification ) + i) ));
                
                if (i) graph->AddEdge(( row * justification ) + i, ( ( row * justification ) + i ) - 1,
                        1 / ( 1 + ( float ) graph->GetVertex(( ( row * justification ) + i ) - 1) ));
            }

            if (line.find("-") != std::string::npos)
                sequence.setComplete(false);
            row++;
        }
    }

    sequence.setGraph(graph);
    sequence.setGenetic_code(genetic_code);
    sequences.push_back(sequence);
    this->setSequences(sequences);

    if (sequences.empty()) {
        std::cerr << fileName << " no contiene ninguna secuencia." << std::endl;
        return;
    }

    sequences.size() == 1 ? std::cout << "1 sequence cargada" : std::cout << sequences.size() << " secuencias cargadas";
        
    std::cout <<" correctamente desde el archivo " << fileName << std::endl;
        
    file.close();
}

void Controller::conteo( ) {
    if (this->sequences.size() == 1)
        std::cout << "1 sequence";
    else if (this->sequences.size() > 1)
        std::cout << this->sequences.size() << " secuencias";
    else
        std::cout << "No hay secuencias cargadas";

    std::cout << " en memoria." << std::endl;
}

void Controller::listar_secuencias( ) {
    if(!sequences.size())
        std::cout << "No hay secuencias cargadas en memoria." << std::endl;

    for (std::list<Sequence>::iterator ptr = this->sequences.begin(); ptr != this->sequences.end(); ptr++) {
        string differentBases = ptr->differentBases(); 

        std::cout << "Secuencia " << ptr->getDescription() << " contiene ";

        ptr->getComplete() == true ? std::cout << differentBases.size() << " bases." << std::endl : std::cout << "al menos " << (differentBases.size() - 1) << " bases." << std::endl;
    }
}

std::vector< string > Controller::histograma( char* description ) {
    
    Sequence sequence = this->findSequence(string(description));
    
    std::vector < string > response;
    if (sequence.getDescription() == "")
        return response;

    int base, pos = 0;

    string filtered_bases = sequence.differentBases();
    std::vector <int> freqs (filtered_bases.size(), 0);
    
    string genetic_code = sequence.getGenetic_code();

    for (int i = 0; i < filtered_bases.length(); i++) {
        pos = -1;
        do {
            pos = genetic_code.find(filtered_bases[i], pos + 1);
            if (pos != -1) freqs[i]++;
        } while (pos != -1);
    }

    for (base = 0; base < freqs.size(); base++) {
        response.push_back(string(1, filtered_bases[base]));
        response.push_back(to_string(freqs[base]));
    }

    return response;
}

std::vector<string> Controller::histogramaGeneral( ) {

    string genetic_code = "";

    for (std::list<Sequence>::iterator ptr = sequences.begin(); ptr != sequences.end(); ptr++)
        genetic_code += ptr->getGenetic_code();
    
    std::vector <string> response;

    int base, pos = 0;

    string filtered_bases = differentBases();
    std::vector <int> freqs (filtered_bases.size(), 0);

    for (int i = 0; i < filtered_bases.length(); i++) {
        pos = -1;
        do {
            pos = genetic_code.find(filtered_bases[i], pos + 1);
            if (pos != -1) freqs[i]++;
        } while (pos != -1);
    }

    for (base = 0; base < freqs.size(); base++) {
        response.push_back(string(1, filtered_bases[base]));
        response.push_back(to_string(freqs[base]));
    }

    return response;
}

int Controller::es_subsecuencia( char* sequence ) {

    if (!(this->sequences.size()))
        return -1;

    string search_seq = string (sequence);
    string genetic_code;
    int base, found = 0, pos = search_seq.length() * -1;

    for (std::list<Sequence>::iterator ptr = sequences.begin(); ptr != sequences.end(); ptr++) {
        genetic_code = ptr->getGenetic_code();
        do {
            pos = genetic_code.find(search_seq, pos + search_seq.length());
            if (pos != -1) found++;
        } while (pos != -1);
    }

    return found;
}

void Controller::enmascarar( char* sequence ) {
    
    if (!(this->sequences.size())) {
        std::cerr << "No hay secuencias cargadas en memoria." << std::endl;
        return;
    }

    string search_seq = string (sequence);
    string genetic_code;
    int base, found = 0, pos = search_seq.length() * -1;

    for (std::list<Sequence>::iterator ptr = sequences.begin(); ptr != sequences.end(); ptr++) {
        genetic_code = ptr->getGenetic_code();
        do {
            pos = genetic_code.find(search_seq, pos + search_seq.length());
            if (pos != -1) {
                genetic_code.replace(pos, search_seq.length(), string(search_seq.length(), 'X'));
                found++;
            }
        } while (pos != -1);
        ptr->setGenetic_code(genetic_code);
    }
            
    if (found == 1)
        std::cout << "1 secuencia ha sido enmascarada." << std::endl;
    else if (found > 1)
        std::cout << found << " secuencias han sido enmascaradas." << std::endl;
    else 
        std::cout << "La secuencia dada no existe, por tanto no se enmascara nada." << std::endl;
}

void Controller::guardar( char* fileName ) {
    
    ofstream file;

    file.open(fileName, ios::out);

    if (file.fail()) {
        std::cout << "Error guardando en " << fileName << std::endl;
        return;
    }

    for (std::list<Sequence>::iterator ptr = sequences.begin(); ptr != sequences.end(); ptr++) {
        file << ">" << ptr->getDescription();
        string genetic_code_buff = ptr->getGenetic_code();

        for (int i = 0; i < genetic_code_buff.size(); i++) {
            if (!(i % ptr-> getJustification()))
                file << std::endl;
            file << genetic_code_buff[i];
        }
        file << std::endl;
    }

    if (!file.fail())
        std::cout << "Las secuencias han sido guardadas en " << fileName << std::endl;
    
    file.close();
}

void Controller::codificar( char* fileName ) {
    ofstream file (fileName, ios::binary);

    if (!file || !this->sequences.size()) {
        std::cerr << "No se pueden guardar las secuencias cargadas en " << fileName << "." << std::endl;
        return;
    }

    short n = differentBases().length();
    file.write((char *) & n, sizeof ( n ));

    vector < string > histogram = histogramaGeneral();

    std::priority_queue < HuffmanNode*, vector < HuffmanNode* >, HuffmanNode > priorityQueue;
    
    for (int c = 0; c < histogram.size(); c += 2) {
        char data = histogram [c][0];
        unsigned long long freq = stoull(histogram [c + 1], 0, 10);
        HuffmanNode* node = new HuffmanNode(data, freq);
        file.write((char *) & data, sizeof ( data ));
        file.write((char *) & freq, sizeof ( freq ));        
        priorityQueue.push(node);
    }

    this->huffmanTree = new HuffmanTree(priorityQueue);
    
    int ns = sequences.size();
    file.write((char *) & ns, sizeof ( ns ));

    for (std::list<Sequence>::iterator ptr = sequences.begin(); ptr != sequences.end(); ptr++) {
        short l = ptr->getDescription().size();
        file.write((char *) & l, sizeof ( l ));

        string description = ptr->getDescription();
        char buffer [ description.size() + 1 ];
        strcpy (buffer, description.c_str());
        file.write((char *) & buffer, description.size());

        unsigned long long w = ptr->getGenetic_code().size();
        file.write((char *) & w, sizeof ( w ));

        short x = ptr->getJustification();
        string binaryCode = huffmanTree->encode(ptr->getGenetic_code());
        file.write((char *) & x, sizeof ( x ));

        unsigned char byte = 0;

        for (int i = 0; i < binaryCode.size(); i++) {
            if (!(i % 8) && i > 0) {
                file.write((char *) & byte, sizeof ( byte ));
                byte = 0;
            }
            byte += binaryCode[i] == 49 ? pow (2, 7 - (i % 8)) : 0;
        }
        
        file.write((char *) & byte, sizeof ( byte ));
    }

    std::cout << "Secuencias codificadas y almacenadas en " << fileName << "." << std::endl;

    file.close();
}

void Controller::decodificar( char* fileName ) {
    ifstream file (fileName, ios::binary);
    std::list < Sequence > sequences;

    if (!file) {
        std::cerr << "No se pueden cargar las secuencias en " << fileName << "." << std::endl;
        return;
    }

    short n;
    file.read((char *) & n, sizeof ( n ));

    vector < std::string > histogram = histogramaGeneral();

    std::priority_queue < HuffmanNode*, vector < HuffmanNode* >, HuffmanNode > priorityQueue;
    
    for (int c = 0; c < n; c ++) {
        char data;
        unsigned long long freq;
        file.read((char *) & data, sizeof ( data ));
        file.read((char *) & freq, sizeof ( freq ));        
        HuffmanNode* node = new HuffmanNode(data, freq);
        priorityQueue.push(node);
    }

    this->huffmanTree = new HuffmanTree(priorityQueue);
    
    int ns;
    file.read((char *) & ns, sizeof ( ns ));

    
    for (int i = 0; i < ns; i++) {
        Sequence sequence;
        
        short l;
        file.read((char *) & l, sizeof ( l ));
        
        char description [l + 1];
        memset(description, 0, l + 1);
        file.read((char *) & description, l);
        sequence.setDescription(description);

        unsigned long long w;
        file.read((char *) & w, sizeof ( w ));
   
        short x;
        file.read((char *) & x, sizeof ( x ));
        sequence.setJustification(x);

        string binaryDecoded = "";
        unsigned char byte = 0;
        HuffmanNode* ptr = huffmanTree->getRoot();
        
        while (binaryDecoded.size() < w) {
            file.read((char *) & byte, sizeof ( byte ));

            // Rotación de byte

            unsigned char r = 0;
            unsigned byte_len = 8;

            while (byte_len--) {
                r = (r << 1) | (byte & 1);
                byte >>= 1;
            }

            byte = r;

            for (int i = 0; (i < 8) && (binaryDecoded.size() < w); i++) {
                char result = huffmanTree->decode((byte >> i) & 1);
                if (result) binaryDecoded += result;
                if (result == '-') sequence.setComplete(false);
            }
        }

        sequence.setGenetic_code(binaryDecoded);
        sequences.push_back(sequence);
    }

    this->setSequences(sequences);

    std::cout << "Secuencias decodificadas desde " << fileName << " y cargadas en memoria." << std::endl;

    file.close();
}

std::string Controller::differentBases( ) {
    std::string different;
    std::string buffer = "";

    for (std::list<Sequence>::iterator ptr = sequences.begin(); ptr != sequences.end(); ptr++)
        buffer += ptr->getGenetic_code();
    
    for (char data : buffer)
        if (different.find(data) == std::string::npos)
            different.append(std::string(1, data));
    
    return different;
}


void Controller::ruta_mas_corta( char * params ) {
    long start, end, i, j, x, y;
    char* token = strtok (params, " ");
    Sequence sequence = this->findSequence(string (token));
    
    if (sequence.getDescription() == "") {
        std::cerr << "La secuencia " << token << " no existe." << std::endl;
        return;
    }

    token = strtok(NULL, " ");
    i = atoi(token);
    
    token = strtok(NULL, " ");
    j = atoi(token);
    
    token = strtok(NULL, " ");
    x = atoi(token);
    
    token = strtok(NULL, " ");
    y = atoi(token);
    
    start = (i * sequence.getJustification()) + j;
    end = (x * sequence.getJustification()) + y;

    if (start >= sequence.getGraph( )->getVertices( ).size( )) {
        std::cerr << "La base en la posici" << char(162) << "n [" << i << ", " << j << "] no existe." << std::endl;
         return;
    }

    if (end >= sequence.getGraph( )->getVertices( ).size( )) {
        std::cerr << "La base en la posici" << char(162) << "n [" << x << ", " << y << "] no existe." << std::endl;
         return;
    }

    std::pair < float, std::vector < long > > result = sequence.getGraph()->Dijkstra( start, end );
    std::cout << "\nPara la secuencia " << params << ", la ruta m" << char(160) << "s corta entre la base en [" << i << "," << j 
              << "] y la base en [" << x << "," << y << "] es: ";

    for (int i = 0; i < result.second.size( ); i++) {
        std::cout << sequence.getGraph( )->GetVertex(result.second[i]);
    }
    std::cout << "\nEl costo total de la ruta es: " << result.first << std::endl;
}

void Controller::base_remota( char * ){
    std::cout << "Base remota";
}

#endif