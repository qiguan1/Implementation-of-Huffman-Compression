/** Name:Qihan Guan, Muyang Wu
  * Date:Jan 26, 2016
  * Assignment PA2
  * Description: HCNode implementation file.
  */

#include "HCNode.hpp"

/** Less-than comparison, so HCNodes will work in std::priority_queue
  * We want small counts to have high priority.
  * And we want to break ties deterministically.
  */
bool HCNode::operator < (const HCNode& other){
  if(count != other.count)  return count > other.count;
  return symbol <  other.symbol;
}

bool comp(HCNode* one, HCNode* other){
  return *one < *other;
}
