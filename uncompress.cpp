/** Name:Qihan Guan, Muyang Wu
 ** Date:Jan 29, 2016
 ** Assignment PA2
 ** Description: Uncompression cpp file.
 **/


#include <iostream>
#include <fstream>  
#include "HCTree.hpp"

using namespace std;

int main(int argc, char*argv[]){
  
  if (argc != 3) {
    cout << "Invalid number of arguments" << endl;
    return -1;
  }
  
  ofstream output;
  ifstream input;
  int size = 0;
  int b = 0;
  vector<int> freq(256, 0);

  //1. Open the input file for reading.
  input.open(argv[1], ios::binary);

  
  //2. Read the file header at the beginning of the input file, and reconstruct the Huffman coding tree.
  for (int i = 0; i < freq.size(); i++){
    input.read(((char*)(&freq[i])), sizeof(int));
    size += freq[i];
  }
	
  HCTree tree;
  tree.build(freq);
  
  //3. Open the output file for writing.
  output.open(argv[2], ios::binary);
  BitInputStream bin(input);

  //find the begining of the file past the header
  input.seekg(ios::beg + (256*sizeof(int)));

  //4. Using the Huffman coding tree, decode the bits from the input file into the appropriate sequence of bytes, writing them to the output file.
  for (int x = 0; x < size; x++){ 
    b = tree.decode(bin);
    output.write((char*)&b, 1);
  }

  //5. Close the input and output files.
  output.close();
  input.close();

  return 0;
}
