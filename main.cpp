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

struct Record {
  long long id;
  string name;
  string bio;
  long long manager_id;
};

struct Block {
    //int numRecords; // counter to keep track of the number of records in the records array.
    int totalSize;
    //Record records[60]; // I chose 25 as the max nubmer of records because seemed liek a good nubmer it was okayed by professor
    vector<Record> records;
    Block* overflow;


    int editBlock(); // this will call readBlock;
    void printBlock(int filelocation,int id); // this will call readBlock
    struct Block readBlock();

};

struct Hmap {
    int n_index;
    int num_bits;
    vector<Block> v;
};

void write() {
  ofstream fout;

  fout.open("EmployeeIndex.txt");
  //code here


  fout.close();
}

 int writeBlock(struct Block myBlock, int filelocation)
    {
      FILE * outfile;
      //ofstream fout;
      outfile = fopen("EmployeeIndex.txt","w");
      //code here
      fwrite(&myBlock, sizeof(struct Block),1,outfile);
      fclose(outfile);
      return 0;
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

  Block currentBlock;
  Record currentRecord;
  size_t *size_ptr = NULL;
  int i = 0;

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
    currentRecord.manager_id = stoll(manager_id,size_ptr,0);
    currentBlock.records[i] = currentRecord;
    i++;

     //  cout << "ID: " << currentRecord.id << '\n';
      // cout << "name: " << currentRecord.name << '\n';
      // cout << "bio: " << currentRecord.bio << '\n';
       //cout << "manager-id: " << currentRecord.manager_id << '\n';
       //cout << endl << endl;
    }
  }
  fin.close();
  writeBlock(currentBlock,0);
}



    struct Block readBlock(){
      FILE *infile;
      struct Block currentBlock;
      //struct Block readBlock;


      infile = fopen ("EmployeeIndex.txt", "r");
      if (infile == NULL)
      {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
      }

      // read file contents till end of file
      while(fread(&currentBlock, sizeof(struct Block), 1, infile))


    // close file
    fclose (infile);
    return currentBlock;

    }
    int Block::editBlock(){return 0;} // this will call readBlock;
    void Block::printBlock(int filelocation,int id){} // this will call readBlock

// prototypes
int hash(int x);

int main(int argc, char const *argv[]) {
  string choice;
  struct Block currentBlock;

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

  read();
  currentBlock = readBlock();
  cout << sizeof(currentBlock.records)/sizeof(Record) << endl;
  cout << currentBlock.records[0].name;


  // c input creation of index
    // L <id> Look up index
    // Block size = 4096
    int blockSize = 4096;
    float capacity = 0.8;

    // increment N if avg number of records per Block is greater than 0.8 %
    // read the line take
    // bucket array <hkey,bucketid stored on disk, index structure can be read from disk to main memory
    // index file we want to save our buckets into a file so when we call program with L option we have the bucket arrays.

    // hash file EmployeeIndex- must be named that

    //

  return 0;
}

/*int hashFuncation(int x){
    return(x%bucket);

}*/
