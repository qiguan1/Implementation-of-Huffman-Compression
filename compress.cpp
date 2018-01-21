/** Name:Qihan Guan, Muyang Wu
  * Date:Jan 29, 2016
  * Assignment PA2
  * Description: compression cpp file
  */

#include <iostream>
#include <fstream>
#include "HCTree.hpp"

int main(int argc, char*argv[]){
  
  if (argc != 3){
    cout << "Invalid number of arguments." << endl;
    return -1;
  }
  
  ifstream input;
  ofstream output;
  byte b;
  
  vector<int> freq(256, 0);
  
  //1. Open the input file for reading.
  input.open(argv[1], ios::binary);
  
  //2.Read bytes from the file, counting the number of occurrences of each byte value; then close the file.
  int size = 0;
  while(!input.eof()){
    b = input.get();
    if(input.eof()) break;
    freq[b]++;
    size++;
  }

  //3.Use these byte counts to construct a Huffman coding tree. Each unique byte with a non-zero count will be a leaf node in the Huffman tree.
  HCTree tree;		
  tree.build(freq);
	
  //4. Open the output file for writing.
  output.open(argv[2],ios::binary);
  BitOutputStream bout(output);

  //5.Write enough information (a "file header") to the output file to enable the coding tree to be reconstructed when the file is read by your uncompress program. (refer to the design notes about constructing the header)
  for (int i = 0; i < freq.size(); i++) {
    output.write(((char *) &freq[i]), sizeof(int));
  }

  //6. Open the input file for reading, again.
  input.clear();
  input.seekg(0, ios::beg);

  //7. Using the Huffman coding tree, translate each byte from the input file into its code, and append these codes as a sequence of bits to the output file, after the header.
  for (int j = 0; j < size; j++){
    b = input.get();
    tree.encode(b, bout);
  } 

  bout.flush();
  // 8. Close the input and output files.
  output.close();
  input.close();


  return 0;
}
