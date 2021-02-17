#include <iostream>
#include <fstream>
#include <string.h>
#include <tuple> 
#include <stdlib.h>
#include <vector>
using namespace std;

// maybe use this? It could work so we have a bucket
/*struct Bucket {
tuple::tuple <int,void *> [];
int
// if we use this we will want ot have a read and a write bucket funcations.
// read will store information in hte current information.
// write will write the current buckets information
}*/


struct record {
  long long id;
  string name;
  string bio;
  long long manager_id;
};

struct block {
    int numRecords; // counter to keep track of the number of records in the records array.
    int totalSize;
    record records[5]; // I chose 25 as the max nubmer of records because seemed liek a good nubmer it was okayed by professor
    int editBlock(); // this will call readBlock;
    void printBlock(int filelocation,int id); // this will call readBlock 

};

// maybe use this IDK
struct index {
  int hash;
  int id;
  int location;
  int index; // 0-4

};
struct Hmap {
//Variables
    int n; // buckets in use
    int i; // ceil(log2(n))
    int block_size;
    vector<block> blocks; // bucket array
};

    
// prototypes
int hashFuncation( int x);
struct block readBlock(struct block myBlock, int fileLocation);
int writeBlock(struct Block myBlock, int filelocation);
int editBlock(){return 0;} // this will call readBlock;
void printBlock(int filelocation,int id){} // this will call readBlock 
void read();// TODO ad
void write(); // maybe remove
void averageOccupance(int numRecords, int numBuckets);
int hash(int x);
void insert(int key);
void search(int key);

int main(int argc, char const *argv[]) {
  string choice;
  struct block currentBlock;
  int offset = 0;

  if (argc == 1) {
    cout << "ERROR: Choice of mode needed on command line (C or L [ID])" << endl;
    exit(1);
  }

  choice = argv[1];

  if ( choice == "-C") {
    cout << "choice C" << endl;
    read(); // r
  } else if(choice == "-L"){
    cout << "choice L" << endl;
  } else {
    cout << endl << "**Error in the inputted string, please try again**" << endl << endl;
  }

  currentBlock = readBlock(currentBlock,offset);
  //cout << sizeof(currentBlock.records)/sizeof(record) << endl; // REMOVE
  //cout << currentBlock.records[0].name; // REMOVE


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


/* void write() {
  ofstream fout;

  fout.open("EmployeeIndex.txt");
  //code here

  fout.close();
} */

// returns the location in the file that we should write to next time.
//======================================
int writeBlock(struct block myBlock, int filelocation)
  {
    //FILE * outfile;
    ofstream fout;
    //outfile = fopen("EmployeeIndex.txt","w");
    fout.open("EmployeeIndex.txt");
    // cout << "put pointr location" << fout.tellp() << "\n"; // REMOVE
    //code here
    // fwrite(&myBlock, sizeof(struct block),1,outfile);
    fout.seekp(filelocation); // seeks to file location and will start the write after that.
    fout.write((char*) &myBlock,sizeof(struct block));
    //cout << "get pointr location" << fout.tellp() << "\n"; // REMOVE

    //fclose(outfile);
    fout.close();
    return fout.tellp(); // reutrns the current place in the file at the end of the block that was written.
}

//======================================
void read() {
  ifstream fin;
  string line;
  char delimiter = ',';
  int iterator = 0;

  string id;
  string name;
  string bio;
  string manager_id;
  block currentBlock;
  record currentRecord;
  size_t *size_ptr = NULL;
  int i = 0;
  int currentOffset = 0;
  //vector<string> v[50];

  fin.open("Employee.csv");
  if (fin.fail()) {
    cout << "Could not open the file";
  } else {
  while (getline(fin, id, delimiter)) {
    
      getline(fin, name, delimiter); 
      getline(fin, bio, delimiter); 
      getline(fin, manager_id, '\n');

      currentRecord.id = stoll(id,size_ptr,0);
      currentRecord.name = name;
      currentRecord.bio = bio;
      //cout << currentRecord.bio.capacity() << "\n"; // REMOVE
      currentRecord.manager_id = stoll(manager_id,size_ptr,0);
      currentBlock.records[i] = currentRecord;
      currentBlock.totalSize += sizeof(currentRecord);
      currentBlock.numRecords += 1;
      // write currentBlock and save the location
      if (currentBlock.numRecords >= 5){
        writeBlock(currentBlock,currentOffset); 
        currentOffset = writeBlock(currentBlock,currentOffset); 
        i = 0;
      }
    i++;
    }
  }
  fin.close();
  writeBlock(currentBlock,0);
}

// Read block
//========================================================================================
struct block readBlock(struct block myBlock, int fileLocation){
  ifstream fin;
  struct block currentBlock;
  
  fin.open("EmployeeIndex.txt");
  fin.seekg(fileLocation);
  fin.read((char*) &myBlock,sizeof(struct block));
  //infile = fopen ("EmployeeIndex.txt", "r"); 
  if (fin.fail()) 
  { 
    fprintf(stderr, "\nError opening file\n"); 
    exit (1); 
  }  

// close file 
fin.close();
return currentBlock;
}
/*int hashFuncation(int x){
    return(x%bucket);

}*/
//========================================================================================
void averageOccupance(int numRecords, int numBuckets) {
  double threshold = 0.80;
  int maxBlockSize = 5; //max 5 records can be in each block (4096/(8+8+200+500) = ~5.72)
  int n, n_worked;
  
  if (numRecords/(numBuckets*maxBlockSize) > threshold) {
    n = numBuckets++;
    j = ceil(log2((double)n));
    n_worked = n ^(1 << x)

    for (every search key k in bucket n_worked) {
      if ( last j bits of k == n) {
        move search key k into the new bucket n
      }
    }
  }
  increment n and i for hashmap;
}