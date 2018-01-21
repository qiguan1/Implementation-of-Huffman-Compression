/** Name:Qihan Guan, Muyang Wu
  * Date:Jan 24, 2016
  * Assignment PA2
  * Description: BitOutputStream implementation file.
  */
#include "BitOutputStream.hpp"


/** Write the least significant bit of the argument to
  * the bit buffer, and increment the bit buffer index.
  * But flush the buffer first, if it is full.
  */ 
void BitOutputStream::writeBit(int i){
  
  if(nbits >  7) flush();
  i = ((i&1) << (7 - nbits));
  buf |= i;
  nbits++;
  
}

/** Send the buffer to the output, and clear  it */
void BitOutputStream::flush(){
    out.put(buf);
    out.flush();
    buf = nbits = 0;
}
