#ifndef __HUFFMANNODE__H__
#define __HUFFMANNODE__H__

#include <string>
#include <list>
#include <vector>

class HuffmanNode {
    private:
        char data;
        unsigned long long freq;
        HuffmanNode* left;
        HuffmanNode* right;

    public:
        HuffmanNode( );
        HuffmanNode(unsigned long, HuffmanNode*, HuffmanNode*);
        HuffmanNode(char, unsigned long long);
        virtual ~HuffmanNode( );
        bool isLeaf( );
        unsigned long long getFreq( );
        HuffmanNode* getLeft( );
        HuffmanNode* getRight( );
        std::string encode(char);
        char getData( );

    friend std::ostream& operator << (std::ostream &o, const HuffmanNode &p)
    {
        o << p.data << ", " << p.freq;
        return o;
    }

    bool operator < (const HuffmanNode &node) const {  
        return node.freq < this->freq;
    }

    bool operator > (const HuffmanNode &node) const {  
        return node.freq > this->freq;
    }

    bool operator == (const HuffmanNode &node) const {  
        return node.freq == this->freq;
    }

    int operator() (const HuffmanNode* p1, const HuffmanNode* p2) const {
        return (p1->freq > p2->freq);
    }

};

#include "HuffmanNode.hxx"

#endif // __GENOMA__H__