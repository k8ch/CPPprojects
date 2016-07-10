#include "convert.h"

int main() {
	string test = "GREAT canadian weather ,)*#12312";
	char* testConvert = upConvert(test);
	char* testRepeatOut = repeatConvert(test, 5);
	cout << testConvert << endl; 
	cout << testRepeatOut << endl;
	system("PAUSE");

}