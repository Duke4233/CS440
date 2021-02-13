#include <iostream>
#include <fstream>
#include <string>
#include <tuple> 
#include <stdlib.h>
#include <vector>
using namespace std;

// maybe use this? It could work so we have a bucket
structure Bucket {
tuple <int,void *> [];
int
// if we use this we will want ot have a read and a write bucket funcations.
// read will store information in hte current information.
// write will write the current buckets information
}


void write() {
  ofstream fout;

  fout.open("EmployeeIndex.csv");
  //code here
  fout.close();
}

void read() {
  ifstream fin;
  string line;
  char delimiter = ',';
  int iterator = 0;
  string id;
  string name;
  string bio;
  string manager_id;
  //vector<string> v[50];

  fin.open("Employees.csv");
  if (fin.fail()) {
    cout << "Could not open the file";
  } else {
  while (getline(fin, id, delimiter)) {
      getline(fin, name, delimiter);
      getline(fin, bio, delimiter);
      getline(fin, manager_id, '\n');

      // cout << "ID: " << id << '\n';
      // cout << "name: " << name << '\n';
      // cout << "bio: " << bio << '\n';
      // cout << "manager-id: " << manager_id << '\n';
      // cout << endl << endl;
    }
  }
  fin.close();
}

struct block {
    int numRecords; // counter to keep track of the number of records in the records array.
    int totalSize;


    string records[25][4]; // I chose 25 as the max nubmer of records because seemed liek a good nubmer it was okayed by professor

    
    int writeBlock(int filelocation);
    void readBlock(int filelocation,struct::block *block_ptr);
    int editBlock() // this will call readBlock;
    void printBlock(int filelocation,int id); // this will call readBlock 

}
    int block::writeBlock(int filelocation);
    void block::readBlock(int filelocation,struct::block *block_ptr);
    int block::editBlock() // this will call readBlock;
    void block::printBlock(int filelocation,int id); // this will call readBlock 
// prototypes
int hashFuncation( int x);

int main(int argc, char const *argv[]) {
  string choice;

  if (argc == 1) {
    cout << "ERROR: Choice of mode needed on command line (C or L [ID])" << endl;
    exit(1);
  }

  choice = argv[1];

  if ( choice == "-C") {
    cout << "choice C" << endl;
  } else if(choice == "-L"){
    cout << "choice L" << endl;
  } else {
    cout << endl << "**Error in the inputted string, please try again**" << endl << endl;
  }

  //read();


  // c input creation of index
    // L <id> Look up index
    // block size = 4096
    int blockSize = 4096;
    float capacity = 0.8;

    // increment N if avg number of records per block is greater than 0.8 %
    // read the line take
    // bucket array <hkey,bucketid stored on disk, index structure can be read from disk to main memory
    // index file we want to save our buckets into a file so when we call program with L option we have the bucket arrays.

    // hash file EmployeeIndex- must be named that

    //

  return 0;
}

/int hashFuncation(int x){
    return(x%bucket);

}*/

