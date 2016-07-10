#pragma once
#include "meeting.h"
class Room {
	string d_name; 
	int d_nMeetings=0; 
	Meeting** d_schedule; 
public:
	Room(string _name); 
	Room(Room& room); 
	~Room();
	void setName(string name); 
	string getName(); 
	bool add(Meeting* room);
	void print();
};