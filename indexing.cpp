#include <iostream>
#include <fstream>
#include <string>
#include <tuple> 
using namespace std;

// maybe use this? It could work so we have a bucket
structure Bucket {
tuple <int,void *> [];
// if we use this we will want ot have a read and a write bucket funcations.
// read will store information in hte current information.
// write will write the current buckets information
}


void read(){
// this reads all the contents of the file
// probally can be called within our readBlock and just assign contents to a block.
// not sure on that tho

    ifstream fin;
    string line;
    fin.open("Employee.csv");
    while (!fin.eof()){
        fin>>line;
        cout<<line<<" ";
    }
}]

struct block {
    int numRecords; // counter to keep track of the number of records in the records array.
    int totalSize;


    string records[25][4]; // I chose 25 as the max nubmer of records because seemed liek a good nubmer it was okayed by professor

    
    int writeBlock(int filelocation);
    void readBlock(int filelocation,struct::block *block_ptr);
    int editBlock() // this will call readBlock;
    void printBlock(int filelocation,int id); // this will call readBlock 




}


    struct::block int writeBlock(int filelocation);
    void readBlock(int filelocation,struct::block *block_ptr);
    int editBlock() // this will call readBlock;
    void printBlock(int filelocation,int id); // this will call readBlock 
// prototypes
int hashFuncation( int x);


int main()
{
    // c input creation of index
    // L <id> Look up index
    // block size = 4096
    int blockSize = 4096;
    float capacity = 0.8;

    // increment N if avg number of records per block is greater than 0.8 %
    read(); // this was just just funcation,
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
