#include <iostream>
#include "Bike.h"
#pragma once
class Bike_shed {
	//an array of bikes
	Bike bikesArray[10];
public: 
	Bike_shed(); 
	bool park(const Bike& bike); 
	Bike remove(const string& bike);
	bool checkLegal(); 
	void print(); 
};