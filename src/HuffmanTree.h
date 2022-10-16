#ifndef __HUFFMANTREE__H__
#define __HUFFMANTREE__H__

#include <string>
#include <list>
#include <vector>
#include <queue>
#include "HuffmanNode.h"

class HuffmanTree {
    private:
        HuffmanNode* root;
        HuffmanNode* iterator;

    public:
        HuffmanTree();
        HuffmanTree(std::priority_queue < HuffmanNode*, std::vector < HuffmanNode* >, HuffmanNode >);
        std::string encode(std::string);
        char decode(bool);
        std::string decode(std::string);
        HuffmanNode* getRoot();
        virtual ~HuffmanTree(); 

};

#include "HuffmanTree.hxx"

#endif 