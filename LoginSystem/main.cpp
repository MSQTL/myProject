#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn();

bool isRegister(string username);

int choice();

int main() {

	system("title LoginSystem");
	choice();
}

bool isLoggedIn() {

	string username, password, un, pw;

	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read("C:\\Users\\sergm\\Desktop\\LoginSystem\\Users\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {
		return true;
	}
	else if (un == username && pw != password) {
		cout << "Invalid password entered!" << endl;
		isLoggedIn();
	}
	else {
		return false;
	}
}

bool isRegister(string username) {

	ifstream file("C:\\Users\\sergm\\Desktop\\LoginSystem\\Users\\" + username + ".txt");

	if (file.is_open()) {
		return true;
	}
	else {
		return false;
	}
}

int choice() {

	string choice;

	cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;
	if (choice == "1") {
		string username, password;

		cout << "select a username: "; cin >> username;
		cout << "select a password: "; cin >> password;

		if (!isRegister(username)) {

			ofstream file;
			file.open("C:\\Users\\sergm\\Desktop\\LoginSystem\\Users\\" + username + ".txt");
			file << username << endl << password;
			file.close();
		}
		else {

			cout << "Username is busy!" << endl;
		}
		

		main();
	}
	else if (choice == "2") {

		bool status = isLoggedIn();

		if (!status) {

			cout << "False login!" << endl;
			system("PAUSE");
			return 0;
		}
		else {

			cout << "Succesfully logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
	else {

		cout << "Invalid command entered!" << endl;
		main();
	}
}