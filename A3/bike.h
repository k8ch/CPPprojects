#include <string>
#include <iostream>
#pragma once
using namespace std; 

struct Color {
	float red, green, blue;
};

class Bike {

private:
	int d_nLight;
	std::string d_owner;
	Color d_color;
	bool d_bell;
	bool d_reflector;
public:
	Bike();
	Bike(string, Color);
	void setNLights(int d_nlight);
	int getNLight(); 
	void setBell(bool d_bell); 
	bool hasBell(); 
	void setReflector(bool d_reflector); 
	bool hasReflector(); 
	void setOwner(string d_owner); 
	string getOwner(); 
	bool isLegal();
	void print(); 
};
