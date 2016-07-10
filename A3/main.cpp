#include "bike.h"
#include "bike_shed.h"
using namespace std; 

int main() {

	Bike_shed shed;

	Bike John = Bike("John", { 1, 2, 3 });
	Bike Jane = Bike("Jane", { 4, 5, 6 });
	Bike Sean = Bike("Sean", { 7, 8, 9 });
	Bike Andrea = Bike("Andrea", { 10, 11, 12 });
	Bike Peter = Bike("Peter", { 13, 14, 15 });
	Bike Mohammed = Bike("Mohammed", { 16, 17, 18 });
	Bike Hong = Bike("Hong", { 19, 20, 21 });

	John.setBell(true);
	Jane.setBell(true);
	Sean.setBell(true);
	Andrea.setBell(true);
	Peter.setBell(true);
	Mohammed.setBell(true);
	Hong.setBell(true);

	John.setNLights(2);
	Jane.setNLights(2);
	Sean.setNLights(2);
	Andrea.setNLights(3);
	Peter.setNLights(4);
	Mohammed.setNLights(1);
	Hong.setNLights(1);

	John.setReflector(true);
	Jane.setReflector(true);
	Sean.setReflector(false);
	Andrea.setReflector(true);
	Peter.setReflector(true);
	Mohammed.setReflector(true);
	Hong.setReflector(true);


	shed.park(John);
	shed.print();
	shed.park(Jane);
	shed.print();
	shed.park(Sean);
	shed.print();
	shed.park(Andrea);
	shed.print();
	shed.park(Peter);
	shed.print();

	cout << shed.checkLegal() << endl;
	shed.remove("Peter");
	shed.print(); 
	shed.remove("John");
	shed.print();
	shed.remove("Andrea");

	//add the bikes of Mohammed and Hong
	shed.park(Mohammed);
	shed.print();
	shed.park(Hong);
	shed.print();
}