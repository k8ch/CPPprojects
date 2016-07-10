#include "bike.h"

Bike::Bike(){
	d_owner = "None";
}
Bike::Bike(string iOwner, Color iColor) {
	d_owner = iOwner; 
	d_color = iColor;
}

//Getters and setters section 
void Bike::setNLights(int d_nlight) {

	this->d_nLight = d_nlight; 
}
int Bike::getNLight() {

	return d_nLight; 
}
void Bike::setBell(bool d_bell) {

	this->d_bell = d_bell; 
}
bool Bike::hasBell() {

	return d_bell; 
}
void Bike::setReflector(bool d_reflector) {

	this->d_reflector = d_reflector;
}
bool Bike::hasReflector() {

	return d_reflector;
}
void Bike::setOwner(string d_owner) {

	this->d_owner = d_owner; 
}
string Bike::getOwner() {

	return d_owner; 
}
bool Bike::isLegal() {

	return ((d_nLight >= 1) && (d_reflector >= 1) && (d_bell >= 1));
}

void Bike::print() {
//Bike Owner: Ramon Color (rgb): 0 0.5 0.7 Lights: 2 Bell: yes Reflector: yes
	cout << "Bike owner: " << getOwner() << " Color: " << d_color.red << "," << d_color.blue << "," << d_color.green << " Lights: " << getNLight() << " Bell: " << hasBell() << " Reflector: " << hasReflector() << endl;
}
//