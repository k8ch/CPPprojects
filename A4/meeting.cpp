#include "meeting.h" 
Meeting::Meeting(bool _coffee, vector<string> _participants, string _what, Time _deadline, int _duration, int _priority) 
	: Item(_what, _deadline, _duration, _priority) {
	
	d_coffee = _coffee;
	d_participants = _participants; 
	
}
void Meeting::print() {

	Item::print();
}

