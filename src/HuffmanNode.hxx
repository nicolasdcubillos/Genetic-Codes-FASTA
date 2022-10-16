#ifndef __HUFFMANNODE__HXX__
#define __HUFFMANNODE__HXX__

#include <string>

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

HuffmanNode::HuffmanNode(char data, unsigned long long freq) {
    this->data = data;
    this->freq = freq;
    this->left = NULL;
    this->right = NULL;
}

HuffmanNode::~HuffmanNode( ) {

}

unsigned long long HuffmanNode::getFreq( ) {
    return this->freq;
}

char HuffmanNode::getData( ) {
    return this->data;
}

HuffmanNode* HuffmanNode::getRight( ) {
    return this->right;
}

HuffmanNode* HuffmanNode::getLeft( ) {
    return this->left;
}

bool HuffmanNode::isLeaf( ) {
    return this->left == NULL && this->right == NULL;
}

std::string HuffmanNode::encode( char data ) {
  
  std::string binaryEncoded = "";
  if( this->data != data )
  {
    if ( this->left != NULL )
      binaryEncoded = this->left->encode( data );
    if ( binaryEncoded == "" ) {
      if ( this->right != NULL )
        binaryEncoded = this->right->encode( data );
      if ( binaryEncoded != "" )
        binaryEncoded = "1" + binaryEncoded;
    }
    else
      binaryEncoded = "0" + binaryEncoded;

    if ( binaryEncoded != "" ) {
      if ( binaryEncoded[ binaryEncoded.size( ) - 1 ] == 'X' )
        binaryEncoded = binaryEncoded.substr( 0, binaryEncoded.size( ) - 1 );
    }
  }
  else
    binaryEncoded = "X";

  return( binaryEncoded );
}


#endif