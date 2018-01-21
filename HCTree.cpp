/** Name:Qihan Guan, Muyang Wu
  * Date:Jan 26, 2016
  * Assignment PA2
  * Description: Huffman Tree implementation file.
  */

#include "HCTree.hpp"
#include <fstream>
#include <iostream>
#include <vector>

/** Use the Huffman algorithm to build a Huffman coding trie.
  * PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
  * the frequency of occurrence of byte i in the message.
  * POSTCONDITION:  root points to the root of the trie,
  * and leaves[i] points to the leaf node containing byte i.
  */
void HCTree::build(const vector<int>& freqs){
  int i = 0;
  std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> q;
  while(i < freqs.size()){
    if(freqs[i] > 0){
      leaves[i] = new HCNode(freqs[i], i, 0, 0, 0);
      q.push(leaves[i]);
    }
    i++;
  }
  if(q.empty()){
    root = NULL;
    return;
  }
  while(q.size() > 1){
    HCNode* n0 = q.top();
    q.pop();
    HCNode* n1 = q.top();
    q.pop();
    HCNode* tempParent = new HCNode(0,0,0,0,0);
    tempParent->count = n0->count + n1->count;
    tempParent->symbol = n0->symbol;
    tempParent->c0 = n0;
    tempParent->c1 = n1;
    n0->p = tempParent;
    n1->p = tempParent;
   
    q.push(tempParent);
  }

  if(!q.empty()) root = q.top();
}

/** Write to the given BitOutputStream
  * the sequence of bits coding the given symbol.
  * PRECONDITION: build() has been called, to create the coding
  * tree, and initialize root pointer and leaves vector.
  */
void HCTree::encode(byte symbol, BitOutputStream& out) const{
  HCNode* current;
  std::vector<int> buff;
  
  if(this->leaves[symbol]->symbol == symbol){
    current = this->leaves[symbol]; 
    while(current->p){
      if(current->symbol == (current->p)->c0->symbol) buff.push_back(0);
      else buff.push_back(1);
      current = current->p;
    }
    while(!buff.empty()){
      out.writeBit(buff.back());
      buff.pop_back();
    }
  }
}

/** Return symbol coded in the next sequence of bits from the stream.
  * PRECONDITION: build() has been called, to create the coding
  * tree, and initialize root pointer and leaves vector.
  */
int HCTree::decode(BitInputStream& in) const{
  HCNode* current = root;
  int byte = 0;
  while((current->c0) || (current->c1)){
    byte = in.readBit();
    if(byte == 1) current = current->c1;
    else current = current->c0;
  }
  return current->symbol;
}

/*function for deleting all nodes, take HCNode poiner
 *as parameter.
 */
void HCTree::clearAll(HCNode * node){
  if(node != NULL){
    clearAll(node->c0);
    clearAll(node->c1);
    delete node;
  }
}

/*Destructor, delete all nodes*/
HCTree::~HCTree(){
 if(root) clearAll(root);
}

