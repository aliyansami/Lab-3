#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int StringLenght(char* mystr) {
	int counter = 0;
	for (int i = 0; mystr[i] != '\0'; i++) {
		counter++;
	}
	
	return counter;
}

int GetCharacterCount(char* myString, char c) {
	
	int counter = 0;
	int stringlen = 0;
	stringlen = StringLenght(myString);
	for (int i = 0; i<stringlen; i++) {
		if (myString[i] == c) {
			counter++;
		}
	}

	char* Temp = new char[stringlen+1];

	int i = 0;
	for (; i < stringlen; i++) {
		Temp[i] = myString[i];
	}
	Temp[i] = '\0';

	delete myString;
	myString = nullptr;

	cout << "myString: " << Temp << "\n";
	cout << "ch: " << c << "\n";
	cout << "Total no. of occurrences: " << counter << "\n";

	delete Temp;
	Temp = nullptr;

	return counter;
}

char* GetStringFromBuffer(char* buffer)
{
	int strLen = StringLenght(buffer);
	char* str = 0;

	if (strLen > 0)
	{
		str = new char[strLen + 1];
		char* tempDest = str;
	
		for (char* tempSrc = buffer; *tempSrc != '\0'; tempSrc++, tempDest++)
		{
			*tempDest = *tempSrc;
		}
		*tempDest = '\0';
	}
	return str;
}

char** ReadStudentsListFromFile() {
	ifstream myfile;
	myfile.open("Data.txt");
	
	int nof_stds = 0;
	int sofname = 0;
	int counter = 0;
	char** list = 0;
		
		myfile >> nof_stds;
		
	    list = new char* [nof_stds];

		for (int i = 0; i <nof_stds+1; i++) {
			char temp[30];
			myfile.getline(temp, 30);
			sofname = StringLenght(temp);
			char* name = 0;
			name = GetStringFromBuffer(temp);
			
			list[i] = new char[sofname];
			list[i] = name;
			
		}
		
	return list;
}

void print(char** list, int& size) {
	for (int i = 0; i <= size; i++) {
		cout << list[i] << "\n";
	}
}

int main() {

	cout << "Excercise #1: " << "\n";
	int size = 0;
	char myStr1[] = "Hello World";
	size=StringLenght(myStr1);
	cout << "Size: " << size << "\n";
	cout << "\n";
	char* Mystring=new char[80];
	char a;

	cout << "Excercise #3" << "\n";
	cout << "Enter the string: " << "\n";
	cin.getline(Mystring,80);
	cout << "Enter the Character: " << "\n";
	cin >> a;
	GetCharacterCount(Mystring, a);

	cout << "Excercise #4: " << "\n";
	ifstream myfile;
	myfile.open("Data.txt");
	int noofstd = 0;
	myfile >> noofstd;
	
	char** matrix = 0;
	matrix	= ReadStudentsListFromFile();
	
	print(matrix, noofstd);
	

	system("pause");
	return 0;
}