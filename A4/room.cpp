#include "room.h"
Room::Room(string _name) {
	d_name = _name; 
}
Room::Room(Room& room) {

	d_name = room.getName();
}
Room::~Room() {
	//delete[] d_schedule;
}
void Room::setName(string name) {
	d_name = name; 
}
string Room::getName() {

	return d_name; 
}
//add an additional meeting room. The function should always return true. There are no fixed number of meetings. 
//Should grow the array at d_schedule by one with every call to add. 
bool Room::add(Meeting* r) {
	d_nMeetings++;
	Meeting **newSchedule = new Meeting*[d_nMeetings];
	for (int i = 0; i < d_nMeetings - 1; i++) {
		newSchedule[i] = d_schedule[i];
	}
	newSchedule[d_nMeetings-1] = r; 
	//delete[] d_schedule;
	d_schedule = newSchedule; 
	return true; 
}
void Room::print() {
	for (int i = 0; i < d_nMeetings ; i++) {
	
		d_schedule[i]->print();
	}

}