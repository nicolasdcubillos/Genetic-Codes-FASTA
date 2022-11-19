#ifndef __SEQUENCE__HXX__
#define __SEQUENCE__HXX__

#include <string>

Sequence::Sequence( ) {
    this->description = "";
    this->genetic_code = "";
    this->complete = true;
    this->justification = 0;
    this->graph = new Graph < char, float > ( );
}

Sequence::~Sequence( ) {

}

void Sequence::setDescription (std::string description) {
    this->description = description;
}

void Sequence::setComplete (bool complete) {
    this->complete = complete;
}

void Sequence::setJustification (unsigned short justification) {
    this->justification = justification;
}

void Sequence::setGenetic_code(std::string genetic_code){
    this->genetic_code = genetic_code;
}

void Sequence::setGraph(Graph < char, float > * graph){
    this->graph = graph;
}

std::string Sequence::getDescription( ){
    return this->description;
}

bool Sequence::getComplete( ){
    return this->complete;
}

unsigned short Sequence::getJustification( ){
    return this->justification;
}

std::string Sequence::getGenetic_code( ){
    return this->genetic_code;
}

Graph < char, float >* Sequence::getGraph( ){
    return this->graph;
}

std::string Sequence::differentBases(){
    std::string different;
    std::string buffer = this->genetic_code;

    for (char data : buffer)
        if (different.find(data) == std::string::npos)
            different.append(std::string(1, data));
        
    return different;
}

#endif
