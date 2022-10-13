#ifndef __HUFFMANNODE__HXX__
#define __HUFFMANNODE__HXX__

HuffmanNode::HuffmanNode( ) {
    this->freq = 0;
    this->data = 0;
    this->left = NULL;
    this->right = NULL;
}

HuffmanNode::HuffmanNode(unsigned long freq, HuffmanNode* left, HuffmanNode* right) {
    this->freq = freq;
    this->data = 0;
    this->left = left;
    this->right = right;
}

HuffmanNode::HuffmanNode(char data, unsigned long freq) {
    this->data = data;
    this->freq = freq;
    this->left = NULL;
    this->right = NULL;
}

HuffmanNode::~HuffmanNode( ) {

}

unsigned long HuffmanNode::getFreq( ) {
    return this->freq;
}

bool HuffmanNode::esHoja( ) {
    return this->left == NULL && this->right == NULL;
}

#endif