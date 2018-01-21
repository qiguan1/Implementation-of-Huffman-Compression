/** Name:Qihan Guan, Muyang Wu
  * Date:Jan 24, 2016
  * Assignment PA2
  * Description: BitOutputStream definition file.
  */  
#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP
#include <iostream>

class BitOutputStream{
  private:
    char buf;          //one byte buffer of bits   
    int nbits;         //how many bits have been written to buf
    std::ostream & out;//reference to the output stream to use    

  public:
    /** Initialize a BitOutputStream that will use
      * the given ostream for output.
      */
    BitOutputStream(std::ostream & os) : out(os), nbits(0), buf(0) {}
    
    /** Write the least significant bit of the argument to
      *
      * * the bit buffer, and increment the bit buffer index.
      *
      * * But flush the buffer first, if it is full.
      *
      */ 
    void writeBit(int i);
    
    /** Send the buffer to the output, and clear  it*/    
    void flush();

};

#endif 
