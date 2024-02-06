#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int x = 0; //This variable will save the value of the number you select from the menu
	int y = 0; //This variable will come into play when you are asked at the end if you would like to continue
	while (x != 6) { //This while loop will continue to run until you enter in 6 which is linked to EXIT in the menu
	cout << "Here is the menu for the command you can run: " << endl
		<< "1: List the directory content" << endl <<
		"2: Print a working directory" << endl <<
		"3: Create a new directory" << endl <<
		"4: Display a message" << endl <<
		"5: Concencrate and display content of a file" << endl <<
		"6. EXIT" << endl;	
	cin >> x;	
	
	if (x == 1) { //You chose to get the list of the content in the directory 
		cout << "You have chosen to get a list of the directory content!" << endl;
		int dir = system("dir"); //This will save a value in dir based on if the command "dir" was able to be completed when running it through the built in system function
		if (dir == 0) {//if dir == 0 then the command ran successfully
			cout << "Your resquest to get the list of the directory has been completed!" << endl;
		}
		else {//anything besides 0 means something happened
			cout << "Unfortunately we were unable to complete your request or the command returned a non-zero value: " << dir << endl;
		}
	}
	else if (x == 2) { // You have chosen to get a print of the working directory it will look like the path you are working in
		cout << "You have chosen to print a working directory!" << endl;
		int cd = system("cd");
		if (cd == 0) {
			cout << "Your request to print a working directory has been completed!" << endl;
		}
		else {
			cout << "Unfortunately we were unable to complete your request or the command returned a non-zero value: " << cd << endl;
		}
	}
	else if (x == 3) { //You have chosen to create a new directory 
		string directory;
		int z = 0; //This variable will be used when asking if the directory is correct 
		cout << "You have chosen to create a new directory!" << endl;
		while (z != 1) { //This while loop will loop through until the user is certain that that is the correct directory they would like to make
			cout << "Please enter the name of the directory you would like to create: " << endl; 
			cin >> directory;
			cout << "You would like to create a new directory named: " << directory << ", is this correct?" << endl
				<< "1. Yes" << endl << "2. No" << endl;
			cin >> z;
		}
		cout << "You have chosen to create a new directory named: " << directory << "!" << endl;
		int mkdir = system(("mkdir " + directory).c_str()); //The .c_str() is a built in function that returns a pointer to an array that contains a null-terminated sequence of charcters representing the current value of the string object.
		if (mkdir == 0) {
			cout << "Your request to create a new directory named: " << directory << " has successfully been created!" << endl;
			cout << "To make sure we don't run into an error we will immediately delete this directory! Thank you!" << endl;
			int rmdir = system(("rmdir " + directory).c_str()); // The directory you just created was deleted to make sure down the road you didn't run into a problem, also to try to keep your directory clean
		}
		else {
			cout << "Unfortunately we were unable to create a new directory or it returned a non-zero value: " << mkdir << endl;
		}
	}
	else if (x == 4) { // You have chosen to echo a message
		string echo;
		cout << "You have chosen to display a message!" << endl <<
			"Please enter the word or phrase you would like to echo to the output window: ";
		cin >> echo;
		int _echo = system(("echo " + echo).c_str());
		if (_echo == 0) {
			cout << "Obviously your request has successfully been completed!" << endl;
		}
		else {
			cout << "Unfortunatly your request has failed or it returned a non-zero value: " << _echo << endl;
		}
	}
	else if (x == 5) { //You have chosen to type
		cout << "You have chosen to concencrate and display the contents of a file!" << endl;
		int type = system("type nul > Test.cpp");
		if (type == 0) {
			cout << "Your request to concencrate and display the contents of a file was successful!" << endl;
		}
		else {
			cout << "Unfortunately your request failed, or returned a non-zero: " << type << endl;
		}
		cout << "Unfortunately I don't know much about type and couldn't figure it out! But it seems to work!" << endl;
	}
	cout << "Would you like to continue? " << endl <<
		"1. Yes" << endl << "2. No" << endl;
	cin >> y;
	if (y == 2) {
		cout << "You have chosen to not continue!" << endl <<
			"Thank you, Goodbye" << endl;
		break;
	}
	}
	return 0;
}