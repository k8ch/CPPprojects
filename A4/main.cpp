#include "meeting.h"
#include "room.h"
#include "item.h"
#include <vector>
#include <string>

int main() {

	Room* B111 = new Room("B111");
	Time atime;
	atime.d_year = 2015;
	atime.d_month = 9; 
	atime.d_day = 14;
	atime.d_hour = 4; 
	atime.d_minutes = 10;
	const char *names[] = { "Rodger", "Kate", "Willie", "Ben", "Brian" };
	vector<string> name1(names, end(names));
	vector<string> name2(names, end(names));
	vector<string> name3(names, end(names));
	vector<string> name4(names, end(names));
	vector<string> name5(names, end(names));
 	B111->add(new Meeting(true, name1, "Assignment1", atime, 56, 5));
	B111->print();
	B111->add(new Meeting(true, name2, "Midtern" , atime, 66, 0));
	B111->print();
	B111->add(new Meeting(true, name3, "FinalExam ", atime, 67, 7));
	B111->print();
	B111->add(new Meeting(true, name4, "Faculty Meeting", atime, 69, 3));
	B111->print();
	B111->add(new Meeting(true, name5, "TA Meeting ", atime, 70, 0));
	B111->print();
	Room* A111 = new Room("A111");
	B111 = new Room(*A111);
	B111->setName("B111");
	Meeting* getTogether = new Meeting(true, name2, "Assigment2", atime, 34, 0); 
	B111->add(getTogether); 
	B111->print(); 
	A111->print();
	delete A111; 
	B111->print();
	delete B111; 

	system("pause");
}