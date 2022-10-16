#ifndef __INTERFACE__H__
#define __INTERFACE__H__

#define MAX_TAM_CHAR 256

#include <string>
#include <list>
#include <vector>
#include "Controller.h"

class Interface {
    private:
        Controller controller;

    public:
        Interface( );
        virtual ~Interface( );
        bool checkParams(char*, int);
        bool execute(char*, char*);
        void Start( );
};

#include "Interface.hxx"

#endif 