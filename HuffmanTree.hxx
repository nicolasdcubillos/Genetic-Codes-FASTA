#ifndef __HUFFMANTREE__HXX__
#define __HUFFMANTREE__HXX__

using namespace std;

HuffmanTree::HuffmanTree( ) {
    this->root = NULL;
}

HuffmanTree::~HuffmanTree( ) {

}

HuffmanTree::HuffmanTree(std::priority_queue < HuffmanNode*, vector < HuffmanNode* >, HuffmanNode > priorityQueue) {
    HuffmanNode* result;

    while (priorityQueue.size() > 1) {
        HuffmanNode* first = priorityQueue.top();
        priorityQueue.pop();
        HuffmanNode* second = priorityQueue.top();
        priorityQueue.pop();
        result = new HuffmanNode (first->getFreq() + second->getFreq(), first, second);
        priorityQueue.push(result);
    }

    this->root = result;
}

#endif