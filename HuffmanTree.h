#ifndef __HUFFMANTREE__H__
#define __HUFFMANTREE__H__

#include <string>
#include <list>
#include <vector>
#include <queue>
#include "huffmanNode.h"

class HuffmanTree {
    private:
        HuffmanNode* root;

    public:
        HuffmanTree();
        HuffmanTree(std::priority_queue < HuffmanNode*, vector < HuffmanNode* >, HuffmanNode >);
        string encode(string);
        string decode(string);
        virtual ~HuffmanTree(); 

};

#include "huffmantree.hxx"
#endif // __GENOMA__H__