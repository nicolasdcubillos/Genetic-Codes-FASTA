#ifndef __SEQUENCE__H__
#define __SEQUENCE__H__

#include <string>

class Sequence {
    private:
        std::string description;
        bool complete;
        unsigned short justification;
        std::string genetic_code;

    public:
        Sequence();
        virtual ~Sequence(); 
        
        std::string getDescription();
        void setDescription(std::string);

        bool getComplete( );
        void setComplete(bool);

        unsigned short getJustification( );
        void setJustification(unsigned short);

        std::string getGenetic_code( );
        void setGenetic_code(std::string);

        std::string differentBases( );
};

#include "Sequence.hxx"
#endif // __SECUENCIA__H__