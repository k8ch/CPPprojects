/*	
	Kateryna Chernega
*/
#include "convert.h"

//PART 1 

char* upConvert(const std::string& in) {

	int length = 0;

	//traverse through the array
	for (int i = 0; i < in.length(); i++) {
		//add to the length of the array every time the character is in the range of A...Z, or a..z, or a space. 
		if ((in.at(i) >= 'a' && (in.at(i) <= 'z')) || ((in.at(i) >= 'A') && (in.at(i) <= 'Z')) || (in.at(i) == ' ')) {
			length++;
		}
	}
	//create an array of characters, that is the resulting array
	char* result = new char[length];
	//iterate through array of char
	for (int i = 0; i < length; i++) {
	//substitutes every letter for a capital letter
	 if ((in.at(i) >= 'a') && (in.at(i) <= 'z')) {
			char capital = in.at(i) - 32;
			result[i] = capital;
		}
	 //when space is encountered, print it as is
		else {
			result[i] = in.at(i);
		}		
	}
	//indicates the end of the char array
	result[length] = '\0';
	return result;
}

// PART 2

char* repeatConvert(const std::string& in, int r) {
	//create a new string and copy the string in to a new string
	std::string newString = in; 

	//iterate trough the string
	for (int i = 0; i < newString.length(); i++) {
		//each time the following characters are found, repeat them r times.
		if ((newString.at(i) == 'a') || (newString.at(i) == 'e') || (newString.at(i) == 'i') || (newString.at(i) == 'o')
			|| (newString.at(i) == 'A') || (newString.at(i) == 'E') || (newString.at(i) == 'I') || (newString.at(i) == 'O'))  {
			char k = newString.at(i); 
			newString.insert(i, r - 1, k); 
			//increase i by r-1 to get total number of vowels to be equal to r. 
			i += r - 1; 
		}
	}
	//create a new array of characters
	char* charArray = new char[newString.length()];
	for (int i = 0; i < newString.length(); i++) {
		charArray[i] = newString.at(i); 
	}
	//indicate the end of the char array
	charArray[newString.length()] = '\0';
	return charArray;
}