/** Name:Qihan Guan, Muyang Wu
  * Date:Jan 25, 2016
  * Assignment PA2
  * Description: BitInputStream definition file.
  */

#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP

#include <iostream>

class BitInputStream {
    
private:
  char buf; // one byte buffer of bits
  int nbits; // how many bits have been read from buf
  std::istream & in; // the input stream to use

public:
    /** Initialize a BitInputStream that will use
      * the given istream for input.
      */ 
    BitInputStream(std::istream& is): in(is) {
      buf = 0;
      nbits = 8;
    }
    
    /** Fill the buffer from the input */
    void fill();
    
    /** Read the next bit from the bit buffer.
      * Fill the buffer from the input stream first if needed.
      * Return 1 if the bit read is 1;
      * return 0 if the bit read is 0.*/
    int readBit();
    
};
#endif 
