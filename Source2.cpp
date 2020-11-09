#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	int num;
	string filestr;
	bool evenNum;
	bool evenfile;
	cout << "Enter a number: ";
	cin >> num;
	fstream my_file("numbers.txt", ios::in);
	if (!my_file) {
		cout << "File opening failed!";
		return 0;
	}
	getline(my_file, filestr, '\0');
	int filenum = stoi(filestr);
	if ((filenum % 2) == 0) {
		evenfile = true;
	}
	else {
		evenfile = false;
	}
	if ((num % 2) == 0) {
		evenNum = true;
	}
	else {
		evenNum = false;
	}
	if (evenfile == evenNum) {
		cout << "You lost.";
	}
	else {
		cout << "You won!";
	}
	my_file.close();
	ofstream write_my_file("numbers.txt");
	string numstr = to_string(num);
	write_my_file << numstr << endl;
	return 0;
}

