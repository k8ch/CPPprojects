#pragma once
#include <vector>
#include "item.h"

class Meeting : public Item {
protected:
	bool d_coffee;
	vector< string > d_participants;
public:
	Meeting(bool _coffee, vector<string> _participants, string _what, Time _deadline, int _duration, int _priority=0);
	void print();
};

