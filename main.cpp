#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;
/* *********************************
Write function to create employeeindex file that we will use for lookup mode
********************************* */
void write() {
  ofstream fout;

  fout.open("EmployeeIndex.csv");
  //code here
  fout.close();
}
/* *********************************
read function for reading Employees.csv
********************************* */
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
/* *********************************
main function
********************************* */
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

  return 0;
}
