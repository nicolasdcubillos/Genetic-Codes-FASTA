#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include <string>
#include "Graph.h"

class Sequence {
    private:
        std::string description;
        bool complete;
        unsigned short justification;
        std::string genetic_code;
        Graph < char, float > * graph;

    public:
        Sequence( );
        virtual ~Sequence( ); 
        
        std::string getDescription( );
        void setDescription( std::string );

        bool getComplete( );
        void setComplete( bool );

        unsigned short getJustification( );
        void setJustification( unsigned short );

        std::string getGenetic_code( );
        void setGenetic_code( std::string );

        Graph < char, float > * getGraph( );
        void setGraph( Graph < char, float > * );

        std::string differentBases( );
};

#include "Sequence.hxx"
#endif // __SECUENCIA__H__