#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

struct Time {
public:
	int d_year, d_month, d_day, d_hour, d_minutes;
};

class Item {
protected: 
	string d_what; 
	Time d_deadline;
	int d_duration; 
	int d_priority; 
public: 
	Item(string _what, Time _deadline, int _duration, int _priority=0); 
	void print(); 
};
