/** Name:Qihan Guan, Muyang Wu
  * Date:Jan 25, 2016
  * Assignment PA2
  * Description: BitInputStream implementation file.
  */

#include "BitInputStream.hpp"

/** Read the next bit from the bit buffer.
  * Fill the buffer from the input stream first if needed.
  * Return 1 if the bit read is 1;
  * return 0 if the bit read is 0.
  */
int BitInputStream::readBit(){
    
    if (nbits == 8) fill();
    if (in.eof()) return -1;
    int i = (buf >> (7 - nbits)) &1;
    nbits ++;
    return i;
    
}

/**Fill the buffer from the input*/
void BitInputStream::fill(){
    buf = in.get();
    nbits = 0;
}
