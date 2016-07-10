#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

#include "time.h"
#include "workweek.h"

// a) Define a constructor that dynamically allocates the Time arrays d_start 
// and d_end. [1 point]
WorkWeek::WorkWeek( int _arrayLength ) : d_arrayLength(_arrayLength) {   
  assert( _arrayLength > 0 );
  d_start = new Time[d_arrayLength];
  d_end = new Time[d_arrayLength];
}


// b) Define a copy constructor implementing a deep copy strategy [1 point]
WorkWeek::WorkWeek(const WorkWeek& _w ) : d_arrayLength(_w.d_arrayLength), d_index(_w.d_index) {
  d_start = new Time[d_arrayLength];
  d_end = new Time[d_arrayLength];
  for (int i=0; i<d_index; ++i ) {
    d_start[i] = _w.d_start[i]; 
    d_end[i] = _w.d_end[i]; 
  }
}


// c) Define the destructor for WorkWeek [0.5 point].
WorkWeek::~WorkWeek() {
  if (d_arrayLength>0) {
    delete[] d_start;
    delete[] d_end;
  }
}


// Define the print function for WorkWeek [0.5 point]
void WorkWeek::print() const {
  for (int i=0; i<d_index; ++i ) {
    d_start[i].print(); 
    cout << " to "; 
    d_end[i].print(); 
    cout << endl;
  }
}

// e) Define the function getTotalHours [0.5 point]
Time WorkWeek::getTotalHours() const {
  // do the calculation in minutes
  int minutes{0};
  for (int i=0; i<d_index; ++i ) {
    unsigned char startHrs, startMin, endHrs, endMin;
    d_start[i].get( startHrs, startMin ); 
    d_end[i].get( endHrs, endMin );
    // rely on integral promotion
    minutes += endHrs*60 + endMin - startHrs*60 - startMin;   
  }
  // Convert minutes in hours + minutes
  return Time( minutes/60, minutes%60 );
}



// f)  Define the function addShift for WorkWeek [1.0 point]
void WorkWeek::addShift(unsigned char _hour, unsigned char _minutes, 
			unsigned int _duration ) {
  if (++d_index == d_arrayLength ) {
    assert(d_arrayLength > 0);
    // grow 2x
    d_arrayLength *= 2;
    Time *start = new Time[d_arrayLength];
    Time *end = new Time[d_arrayLength];
    // copy
    for (int i=0; i<d_index; ++i ) {
      start[i] = d_start[i]; 
      end[i] = d_end[i]; 
    }	
    // swap
    delete[] d_start;
    delete[] d_end;
    d_start = start;
    d_end = end;
  }
  d_start[d_index-1] = Time( _hour, _minutes );
  int minutes = (_minutes + _duration)%60;
  int hour = _hour + (_minutes + _duration)/60;
  d_end[d_index-1] = Time( hour, minutes );
  return;
}


