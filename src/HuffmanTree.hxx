#ifndef __HUFFMANTREE__HXX__
#define __HUFFMANTREE__HXX__

using namespace std;

HuffmanTree::HuffmanTree( ) {
    this->root = this->iterator = NULL;
}

HuffmanTree::~HuffmanTree( ) {

}

HuffmanTree::HuffmanTree(std::priority_queue < HuffmanNode*, vector < HuffmanNode* >, HuffmanNode > priorityQueue) {
    HuffmanNode* temp;

    while (priorityQueue.size() > 1) {
        HuffmanNode* first = priorityQueue.top();
        priorityQueue.pop();
        HuffmanNode* second = priorityQueue.top();
        priorityQueue.pop();
        temp = new HuffmanNode (first->getFreq() + second->getFreq(), first, second);
        priorityQueue.push(temp);
    }
    
    this->root = this->iterator = temp;
}

HuffmanNode* HuffmanTree::getRoot( ) {
    return this->root;
} 

string HuffmanTree::encode(string genetic_code) {
    string binaryEncoded;
    
    for (char data : genetic_code)
        binaryEncoded += this->root->encode(data);

    return binaryEncoded;
}

char HuffmanTree::decode(bool bit) {
    if (this->iterator->isLeaf()) this->iterator = this->root;
    this->iterator = bit ? this->iterator->getRight() : this->iterator->getLeft();
    return this->iterator->getData();
}

string HuffmanTree::decode(string bits) {
    string result = "";
    HuffmanNode* ptr = this->root;
    for (char bit : bits) {
        ptr = bit == '1' ? ptr->getRight() : ptr->getLeft();
        if (ptr->isLeaf()) {
            result += ptr->getData();
            ptr = this->root;
        }
    }
    return result;
}

#endif