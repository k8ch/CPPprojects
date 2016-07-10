#include "item.h"
Item::Item(string _what, Time _deadline, int _duration, int _priority) {
	d_what = _what; 
	d_deadline = _deadline; 
	d_duration = _duration;
	d_priority = _priority; 
}
void Item::print() {
	cout << "What: "<< d_what << " Deadline day: " <<d_deadline.d_day <<" Deadline hour: "<< d_deadline.d_hour << " Duration: " <<  d_duration << " Priority: " << d_priority<< endl;
}