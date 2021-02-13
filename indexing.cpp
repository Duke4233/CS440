#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
using namespace std;


structure Bucket {
tuple <int,void *> [];

}


void read(){

    ifstream fin;
    string line;
    fin.open("Employee.csv");
    while (!fin.eof()){
        fin>>line;
        cout<<line<<" ";
    }
}]

struct block {
    int numRecords;
    int totalSize;
    

}
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
    read();
    // read the line take
    // bucket array <hkey,bucketid stored on disk, index structure can be read from disk to main memory
    // index file

    // hash file

    //


    return 0;
}

/*int hashFuncation(int x){
    return(x%bucket);

}*/
