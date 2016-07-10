#include "bike_shed.h"
#include "bike.h"
Bike_shed::Bike_shed(){
}
//adds a bike to an available spot and returns true. If the BikeShed is full, the function returns false.
bool Bike_shed::park(const Bike& bikeOwner) {

	for (int i = 0; i < 10; i++) {
		if (!(bikesArray[i].getOwner().compare("None"))) {
			bikesArray[i] = bikeOwner; 
			return true;
		}
	}
	return false;
}
// removes and returns the first bike with an owner of the given name. If such a bike is not found, the function returns a bike "None"
Bike Bike_shed::remove(const string& bike) {
	for (int i = 0; i < 10; i++) {
	
		if (bikesArray[i].getOwner() == bike) {
			Bike removedBike = bikesArray[i];
			bikesArray[i] = Bike(); 
			return removedBike;
		}
	}
}

//return true if all bikes owned by other than "None" are legal. If a bike is found illegal print a message printing the bike.
bool Bike_shed::checkLegal() {
	for (int i = 0; i < 10; i++) {
	
		if (!(bikesArray[i].isLegal())) {
			bikesArray[i].print();
			return false;
		}
	}
	return true; 
}

//prints all the bikes with owners other than "None".
void Bike_shed::print() {
	for (int i = 0; i < 10; i++) {

		if (bikesArray[i].getOwner() != "None") {
			bikesArray[i].print();
		}
	}
}

