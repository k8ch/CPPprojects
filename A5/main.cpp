#include <iostream>

#include "time.h"
#include "workweek.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>


// #define TO_FILE

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::ofstream;
using std::ostringstream;
using std::string; 


// Code for testing
int main( int argn, char* args[]) {

#ifdef TO_FILE
  ofstream of;
  if (argn > 1 ) {
    of.open( args[1], std::ofstream::out | std::ofstream::app );
  } else {
    of.open( "mark.csv", std::ofstream::out | std::ofstream::app );
  }
  of << "\"";
#else
  ostream& of = cerr;
#endif

  float total = 0.0f;
  // a) Define the default constructor for Time [0.5 points]
  Time tA;
  unsigned char hour, minutes;
  tA.get( hour, minutes );
  if ( hour == 0 && minutes == 0 ) {
    of << "1a,0.5" <<",";
    total += 0.5f;
  } else {
    of << "1a,0" <<",";
  }
  // b) Define the (all argument) constructor with two arguments. [0.5 points]
  hour = 13; minutes = 35; // overflow not defined
  Time tB( hour, minutes );
  tB.get( hour, minutes );
  if ( hour == 13 && minutes == 35 ) {
    of << "1b,0.5" <<",";
    total += 0.5f;
  } else {
    of << "1b,0" <<",";
  }
  // c) Define the getter (returning hours and minutes through references. [0.5 points]
  // Already needed above
  tA.get( hour, minutes );
  if ( hour == 0 && minutes == 0 ) {
    of << "1c,0.5" <<",";
    total += 0.5f;
  } else {
    of << "1c,0" <<",";
  }
  // d) Define the setter for hours and minutes. [1 points]
  tA.set( 2, 128 );
  tA.get( hour, minutes );
  if ( hour == 4 && minutes == 8 ) {
    of << "1d,1.0" <<",";
    total += 1.0f;
  } else {
    of << "1d,0" <<",";
  }
  // WorkWeek
  ostringstream os;
  auto bak = cout.rdbuf();
  cout.rdbuf(os.rdbuf()); //redirect std::cout to out
	
  // a) Define a constructor that dynamically allocates the Time arrays d_start 
  // and d_end. [1 point]
  WorkWeek* wA = new WorkWeek(3);
  wA->print();
  if ( os.str().length() == 0 ) { 
    of << "2a,1.0" <<",";
    total += 1.0f;
  }  else {
    of << "2a,0" <<",";
  }
  os.str(string(""));
  os.clear();

  // b) Define a copy constructor implementing a deep copy strategy [1 point]
  // c) Define the destructor for WorkWeek [0.5 point].
  wA->addShift(8,30,20);
  wA->print();
  // Double check if it worked
  string s = os.str();
  if ( s.find("8") != std::string::npos &&  
       s.find("30") != std::string::npos &&  
       s.find("50") != std::string::npos) {
    // Looks good
    os.str("");
    os.clear();
    // CCtor
    WorkWeek wB( *wA );
    delete wA;
    wB.print();
    string s = os.str();
    if ( s.find("8") != std::string::npos &&  
	 s.find("30") != std::string::npos &&  
	 s.find("50") != std::string::npos) {
      of << "2b,1.0" <<",";
      of << "2c,0.5" <<",";
      total += 1.5f;
    } else {
      of << "2b,0" <<",";
      of << "2c,0" <<",";
    }
  } else {
    of << "2b,0" <<",";
    of << "2c,0" <<",";
  }
 
  // Define the print function for WorkWeek [0.5 point]
  WorkWeek wC(1);
  wC.addShift( 8, 10, 40 );
  wC.print();
  s = os.str();
  if (s.find("8:10 to 8:50") != std::string::npos) {
    of << "2d,0.5" <<",";
    total += 0.5f;
  } else {
    of << "2d,0" <<",";
  }
	
  // Define the function getTotalHours [0.5 point]
  WorkWeek wD(3);
  wD.addShift( 8, 10, 40 );
  wD.addShift( 8, 10, 110 );
  wD.addShift( 8, 10, 200 );
  Time tT = wD.getTotalHours(); 
  tT.get( hour, minutes );
  if ( hour == 5 && minutes == 50 ) {
    of << "2e,0.5" <<",";
    total += 0.5f;
  } else {
    of << "2e,0" <<",";
  }
	
  // Define the function addShift for WorkWeek [1.0 point]
  wD.addShift( 8, 10, 40 );
  wD.addShift( 8, 10, 110 );
  wD.addShift( 8, 10, 200 );
  wD.addShift( 8, 10, 40 );
  wD.addShift( 8, 10, 110 );
  wD.addShift( 8, 10, 200 );
  tT = wD.getTotalHours(); 
  tT.get( hour, minutes );
  if ( hour == 17 && minutes == 30 ) {
    of << "2f,1.0" <<",";
    total += 1.0f;
  } else {
    of << "2f,0" <<",";
    // cerr << static_cast<int>(hour) << " " << static_cast<int>(minutes) << ",";
  }
  of << "Sum," << std::setw(3) << total;
#ifdef TO_FILE
  of << "\"" << endl;
  of.close();
#else
  of << endl;
#endif
  cout.rdbuf(bak); //undo redirection std::cout to out
  return 0;
}
