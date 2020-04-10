#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>
using namespace std;
struct monthly{
	int date;
	string month;
	int year;
};
struct passenger{
	string username;
	string password;
	string name;
	long long int contact;
	string cnic;
	int balance;
	monthly m;
	string totalrides;
	};
void writeToFile(passenger &p)
{
	srand(time(NULL));
	p.balance = rand() % 12000;
	p.totalrides = rand() % 11;
	if (p.totalrides == "10"){
		p.totalrides = "free-ride";
	}
	else{
		p.totalrides = "n.a";
	}
	ofstream obj;
	obj.open("Passenger.txt", ios::app);
	obj << p.username << "," << p.password <<","<< p.name << "," << p.contact << "," << p.cnic << "," << p.balance << ","<<p.totalrides<<endl;
	obj.close();
}
void writeToFile2(passenger&p){
	ofstream obj;
	obj.open("passenger login.txt", ios::app);
	obj << p.username << "," << p.password << endl;
}
void input_passenger(){
	passenger p;
	cin.ignore();
	cout << "Enter the username: ";
	getline(cin, p.username);
	cout << "Enter the password: ";
	getline(cin, p.password);
	cout << "Enter the name of passenger: ";
	getline(cin, p.name);
	cout << "Enter the contact number of passenger: ";
	cin >> p.contact;
	cout << "Enter the cnic number of passenger: ";
	cin.ignore();
	getline(cin, p.cnic);
	writeToFile(p);
	writeToFile2(p);
}
struct captain{
	string available;
	string username;
	string password;
	string name;
	long long int contact;
	string cnic;
	string carnumber;
	string carname;
	string location;
	monthly m;
	string feedback;
	string drops;
	};
void writeToFile1(captain &c)
{
	srand(time(NULL));
	c.feedback = rand() % 5;
	if (c.feedback == "0"){
		c.feedback = "poor";
	}
	else if (c.feedback == "1"){
		c.feedback = "average";
	}
	else if (c.feedback == "2"){
		c.feedback = "good";
	}
	else if (c.feedback == "3"){
		c.feedback = "excellent";
	}
	else{
		c.feedback = "superb";
	}
	ofstream obj;
	obj.open("Captain.txt", ios::app);
	obj << c.username << "," << c.password << "," << c.name << "," << c.contact << "," << c.cnic << "," << c.carname << "," << c.carnumber << "," << c.available << "," << c.feedback <<  endl;
	obj.close();
}
void writeToFile(captain&c){
	ofstream obj;
	obj.open("captain login.txt", ios::app);
	obj << c.username << "," << c.password << endl;
	obj.close();
}
void input_captain(){
	srand(time(NULL));
	captain c;
	cout << "Add a new captain" << endl;
	cout << "Enter username for the captain: ";
	cin.ignore();
	getline(cin, c.username);
	cout << "Enter the password for the captain: ";
	getline(cin, c.password);
	cout << "Enter the name of the captain: ";
	getline(cin, c.name);
	cout << "Enter the contact number of the captain: ";
	cin >> c.contact;
	cout << "Enter the CNIC number of the captain: ";
	cin.ignore();
	getline(cin, c.cnic);
	cout << "Enter the name of car: ";
	getline(cin, c.carname);
	cout << "Enter the car-number of car: ";
	getline(cin, c.carnumber);
	c.available = rand() % 2;
	if (c.available == "1"){
		c.available = "avialable";
	}
	else{
		c.available = "not available";
	}
	writeToFile(c);
	writeToFile1(c);
	}
void mainmenu(){
	cout << "1. Admin Login " << endl;
	cout << "2. User Login " << endl;
	cout << "3. Extras" << endl;
	cout << "4. Exit" << endl;
}
void adminmenu(){
	cout << "1.	Add a new captain" << endl;
	cout << "2. Add a new passenger" << endl;
	cout << "3.	View all captains" << endl;
	cout << "4.	View all passengers" << endl;
	cout << "5.	Remove a captain" << endl;
	cout << "6.	Search a caption" << endl;
	cout << "7.	Search a passenger" << endl;
	cout << "8.	View monthly report of any Captain" << endl;
	cout << "9.	View monthly report of any Passenger" << endl;
	cout << "10.Block rides for captain" << endl;
	cout << "11.Block rides for passenger" << endl;
	cout << "12.View removed captains" << endl;
	cout << "13.View blocked captains" << endl;
	cout << "14.View available/free captains" << endl;
	cout << "15. Free-ride " << endl;
	cout << "16. View passengers free-ride" << endl;
	cout << "17. Exit" << endl;
}
void usermenu(){
	cout << "1. Captain" << endl;
	cout << "2. Passenger" << endl;
}
void captainmenu(){
	cout << endl;
	cout << "1. My Profile" << endl;
	cout << "2.	All rides which I have drop" << endl;
	cout << "3.	Report of Rides" << endl;
	cout << "4.	Edit profile" << endl;
	cout << "5. Exit" << endl;
}
void passengermenu(){
	cout << endl;
	cout << "1.	My Profile" << endl;
	cout << "2.	Edit Profile" << endl;
	cout << "3.	Book a ride" << endl;
	cout << "4.	View balance" << endl;
	cout << "5.	My History" << endl;
	cout << "6.	Cancelled Rides" << endl;
	cout << "7.	Exit" << endl;
}
void update(){
	cout << "Enter the captian name to search in the data: ";
	captain c;
	string search;; string line;
	ifstream obj;
	ofstream temp;
	ofstream temp2;
	obj.open("Captain.txt");
	cout << "Enter the name you want to search: ";
	cin.ignore();
	getline(cin, search);
	if (obj.is_open()){
		temp.open("deleted.txt", ios::app);
		temp2.open("tempo.txt", ios::app);
		while (!obj.eof()){
			getline(obj, line);
			if (((line.find(search, 0))) != string::npos){
				temp << line << endl;
			}
			else{
				temp2 << line << endl;
			}
		}      temp.close();
		temp2.close();
		obj.close();
		remove("captain.txt");
	}
	remove("captain.txt");
	remove("deleted.txt");
	rename("tempo.txt", "captain.txt");
	cout << "Enter your username: ";
	getline(cin, c.username);
	cout << "Enter your password: ";
	getline(cin, c.password);
	cout << "Name:  ";
	getline(cin, c.name);
	cout << "Car: ";
	getline(cin, c.carname);
	cout << "Enter car number:  ";
	getline(cin, c.carnumber);
	cout << "Enter CNIC number: ";
	getline(cin, c.cnic);
	cout << "Enter contact number: ";
	cin >> c.contact;
	ofstream myfile; ofstream obj1;
	myfile.open("captain.txt", ios::app | ios::out);
	obj1.open("captain login.txt", ios::app | ios::out);
	myfile << c.username << "," << c.password << "," << c.name << "," << c.contact << "," << c.cnic << "," << c.carname << "," << c.carnumber << endl;
	obj1 << c.username << "," << c.password << endl;
}
void passenger_update(){
	cout << "Enter the passenger name to search in the data: ";
	passenger p;
	string search;; string line;
	ifstream obj;
	ofstream temp;
	ofstream temp2;
	obj.open("passenger.txt");
	cout << "Enter the name you want to search: ";
	cin.ignore();
	getline(cin, search);
	if (obj.is_open()){
		temp.open("deleted.txt", ios::app);
		temp2.open("tempo.txt", ios::app);
		while (!obj.eof()){
			getline(obj, line);
			if (((line.find(search, 0))) != string::npos){
				temp << line << endl;
			}
			else{
				temp2 << line << endl;
			}
		}      temp.close();
		temp2.close();
		obj.close();
		remove("passenger.txt");
	}
	remove("captain.txt");
	remove("deleted.txt");
	rename("tempo.txt", "passenger.txt");
	cout << "Enter your username: ";
	getline(cin, p.username);
	cout << "Enter your password: ";
	getline(cin, p.password);
	cout << "Name:  ";
	getline(cin, p.name);
	cout << "Contact number: ";
	cin>>p.contact;
	cout << "Enter balance:  ";
	cin >> p.balance;
	cout << "Enter CNIC number: ";
	getline(cin, p.cnic);
		ofstream myfile;  ofstream obj1;
	obj1.open("passenger login.txt", ios::app | ios::out);
	myfile.open("passenger.txt", ios::app | ios::out);
	myfile << p.username << "," << p.password << "," << p.name << "," << p.contact << "," << p.balance << "," << p.cnic  << endl;
	obj1 << p.username << "," << p.password << endl;
}
void writeToFile1(passenger &p)
{
	srand(time(NULL));
	string location[10] = { "Model Town", "Township", "Faisal Town", "Bahria Town", "Wapda Town", "Valencia", "Pak Arab", "Central Park", "DHA", "Johar Town" };
	string location2[10] = { "Model Town", "Township", "Faisal Town", "Bahria Town", "Wapda Town", "Valencia", "Pak Arab", "Central Park", "DHA", "Johar Town" };
	float price;
	price = (rand() %10000);
	ofstream obj;
	obj.open("book a ride.txt", ios::app);
	obj << "Current Location" << "," << "Destination" << "," << "Name of Passenger" << "," << "Date" << "," << "Month" << "," << "Year" << "," << "Price" << endl;
	obj << location[rand() % 10] << "," << location2[rand() % 10] << "," << p.name << "," << p.m.date << "," << p.m.month << "," << p.m.year << "," << price << endl << endl;
	obj.close();
}
int main()
{
	cout << "\t****************************************************************************************\n";
	cout << "\t*                                 Name: Abdullah Mujahid                               *\n";
	cout << "\t*                                 Ref ID#                                                          *\n";
	cout << "\t*                                 Programming Fundamental Final Project                *\n";
	cout << "\t****************************************************************************************\n";
	cout << endl;
	cout << endl;
	cout << endl;
	for (int j = 0; j < 10; j++){
		Sleep(100);
		cout << ">";
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			Sleep(10);
			if (i == 0){
				cout << " ";
			}

		}
		cout << "          v"<<endl;
	}
	cout << "          LOADING ";
	for (int i = 0; i < 10; i++){
		Sleep(100);
		cout << "<";
	}
	
	cout << endl << "CAREEM BOOKING SYSTEM" << endl;
	Sleep(2000);
	int choice;
	while (1 > 0){
		mainmenu();
		cin >> choice;
		if (choice == 1){
			if (choice == 1){
				cin.ignore();
				string username = "";  		string password = "";
				char check;
				cout << "Enter the username of admin: ";
				getline(cin, username);
				cout << "Enter the password of admin: ";
				check = _getch();
				while (check != 13) {
					password.push_back(check);
					cout << '*';
					check = _getch();
				}
				cout << endl;
				ifstream obj; obj.open("admin.txt");
					if (obj.is_open()){
						string line;
						while (!obj.eof()){
							getline(obj, line);
							if (line.find(username, 0) != string::npos){
								if (line.find(password, 0) != string::npos){
									captain c;
								int choice;
								cout << "ADMIN SECTION" << endl;
								adminmenu();
								cout << "Enter your choice: ";
								cin >> choice;
								if (choice == 1){    // add a captain
									input_captain();
								}
								else if (choice == 2){    // add a passenger
									input_passenger();
								}
								else if (choice == 3){    //view all captain
									system("CLS");
									cout << "View all captains registered" << endl;
									string line; ifstream obj; obj.open("Captain.txt");
									while (!obj.eof()){
										getline(obj, line);
										cout << line << endl;
									}
									cout << endl;
								}
								else if (choice == 4){    //view all passenger
									system("CLS");
									passenger p;
									cout << "View all passengers registered" << endl;
									string line; ifstream obj; obj.open("Passenger.txt");
									if (obj){
										while (!obj.eof()){
											getline(obj, line);
											cout << line << endl;
										}
									}
									else{
										cout << "file is empty" << endl;
									}
									cout << endl;
								}
								else if (choice == 5){    //remove  a captain
									captain c;
									string search;; string line;
									ifstream obj;
									ofstream temp;
									ofstream temp2;
									obj.open("Captain.txt");
									cout << "Enter the name you want to search: ";
									cin.ignore();
									getline(cin, search);
									if (obj.is_open()){
										temp.open("removedcaptain.txt", ios::app);
										temp2.open("tempo.txt", ios::app);
										while (!obj.eof()){
											getline(obj, line);
											if (((line.find(search, 0))) != string::npos){
												for (int i = 0; i < 1 && line != "/0"; i++){
													temp << line << endl;
												}
											}
											else{
												temp2 << line << endl;
											}
										}      temp.close();
										temp2.close();
										obj.close();
										remove("Captain.txt");
										rename("tempo.txt", "captain.txt");
									}
									else{
										cout << "File is empty" << endl;
									}
								}
									else if (choice == 6){       // search a captain
					    				captain c;
										string search;; string line;
										ifstream obj;
										obj.open("Captain.txt");
										cout << "Enter the name you want to search: ";
										cin.ignore();
										getline(cin, search);
										if (obj.is_open()){
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find(search, 0))) != string::npos){
													cout << "Captain Found" << endl;
													for (int i = 0; i < 1 && line != "/0"; i++){
														cout << line << endl;
													}
												}
												else{
													cout << "No record found" << endl;
												}
											}
										}
										else{
											cout << "File is empty" << endl;
										}
									}
									else if (choice == 7){               //search a passenger
										passenger p;
										string search;; string line;
										ifstream obj;
										obj.open("Passenger.txt");
										cout << "Enter the name you want to search: ";
										cin.ignore();
										getline(cin, search);
										if (obj.is_open()){
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find(search, 0))) != string::npos){
													cout << "Passenger Found " << endl;
													for (int i = 0; i < 1 && line != "/0"; i++){
														cout << line << endl;
													}
												}
												else{
													cout << "No record found" << endl;
												}
											}
										}
										else{
											cout << "File is empty" << endl;
										}
									}
									else if (choice == 10){ //blocking a captain
										cout << "Blocked captains" << endl;
										captain c;
									 string line;
										ifstream obj;
										ofstream temp;
										ofstream temp2;
										obj.open("Captain.txt");
										if (obj.is_open()){
											temp.open("blocked captain.txt", ios::app);
											temp2.open("tempo.txt", ios::app);
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find("poor"))) != string::npos){
													for (int i = 0; i < 1 && line != "/0"; i++){
														temp << line << endl;
													}
												}
												else{
													temp2 << line << endl;
												}
											}      temp.close();
											temp2.close();
											obj.close();
											remove("Captain.txt");
											rename("tempo.txt", "captain.txt");
										}
										else{
											cout << "File is empty" << endl;
										}

										}
									else if (choice == 12){
										system("CLS");
										cout << "View all removed captains " << endl;
										string line; ifstream obj; obj.open("removedcaptain.txt");
										if (obj){
										while (!obj.eof()){
											getline(obj, line);
											cout << line << endl;
										}
									}
										else{
											cout << "No record found"<<endl;
										}
										cout << endl;
										break;
									}
									else if (choice == 13){
										system("CLS");
										cout << "All blocked captains " << endl;
										string line; ifstream obj; obj.open("blocked captain.txt");
										if (obj){
											while (!obj.eof()){
												getline(obj, line);
												cout << line << endl;
											}
											cout << endl;
										}
									

									}
									else if (choice == 14){
										cout << "Available captains" << endl;
										captain c;
										string line;
										ifstream obj;
										obj.open("Captain.txt");
										if (obj.is_open()){
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find("not available"))) != string::npos){
													//ehh
																}
												else{
													for (int i = 0; i < 1 && line != "/0"; i++){
														cout << line << endl;
													}
												}
														}
										}
										else{
											cout << "File is empty" << endl;
										}
										break;
									}
									else if (choice == 15){
										 string line;
										ifstream obj;
										ofstream temp;
										obj.open("passenger.txt");
										cin.ignore();
										if (obj.is_open()){
											temp.open("freerides.txt", ios::app);
											
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find("free-ride"))) != string::npos){
													for (int i = 0; i < 1 && line != "/0"; i++){
														temp << line << endl;
													}
												}
											}      temp.close();
											
											obj.close();
											
										}
									}
									else if (choice == 16){
										cout << "View free rides" << endl;
										string line; ifstream obj; obj.open("freerides.txt");
										if (obj){
											while (!obj.eof()){
												getline(obj, line);
												cout << line << endl;
											}
											cout << endl;
										}
										else{
											cout << "Empty file" << endl;

										}
									}
									else if (choice == 17){
										return 0;
									}
								}
							}
							else {
								cout << "You have entered an invalid option. Please choose the right option again." << endl;
							}
							break;
						}
					}
				}
	}
		else if (choice == 2){
			{
				captain c;
				cout << "USER SECTION" << endl;
				usermenu();
				cout << "Enter your choice: ";
				cin >> choice;
				if (choice == 1){
					char check;
					string username = "";
					cout << "Please enter your username: ";
					cin.ignore();
					getline(cin, username);
					string password = "";
					cout << "Please enter your password: ";
					check = _getch();
					while (check != 13) {
						password.push_back(check);
						cout << '*';
						check = _getch();
					}
					ifstream obj; obj.open("captain login.txt");
					if (obj.is_open()){
						string line;
						while (!obj.eof()){
							getline(obj, line);
							if (line.find(username, 0) != string::npos){
								if (line.find(password, 0) != string::npos){
									cout << "CAPTAIN MENU" << endl;
									captainmenu();
									cout << endl;
									cout << "Enter you choice: ";
									cin >> choice;
									if (choice == 1){
										captain c;
										string search;; string line;
										ifstream obj;
										obj.open("Captain.txt");
										cout << "Enter the name you want to search: ";
										cin.ignore();
										getline(cin, search);
										if (obj.is_open()){
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find(search, 0))) != string::npos){
													cout << "Record Exists " << endl;
													for (int i = 0; i < 1 && line != "/0"; i++){
														cout << line << endl;
													}
												}
											}
										}
										else{
											cout << "Nothing in file" << endl;
										}
									}
									else if (choice == 4){
										update();
									}
								}
							}
						}
					}
				}
				else if (choice == 2){
					cout << "Passenger section" << endl;
					char check;
					string username = ""; 		string password = "";
					cout << "Please enter passenger username: ";
					cin.ignore();
					getline(cin, username);
					cout << "Please passenger password: ";
					check = _getch();
					while (check != 13) {
						password.push_back(check);
						cout << '*';
						check = _getch();
					}
					ifstream obj; obj.open("passenger login.txt");
					if (obj.is_open()){
						string line;
						while (!obj.eof()){
							getline(obj, line);
							if (line.find(username, 0) != string::npos){
								if (line.find(password, 0) != string::npos){
									cout << endl;
									cout << "PASSENGER MENU" << endl;
									passengermenu();
									cout << endl;
									cout << "Enter your choice: ";
									cin >> choice;
									if (choice == 1){
										cout << "Passenger profile" << endl;
										cout << "Enter your name: ";
										passenger p;
										string search;; string line;
										ifstream obj;
										obj.open("passenger.txt");
										cout << "Enter the name you want to search: ";
										cin.ignore();
										getline(cin, search);
										if (obj.is_open()){
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find(search, 0))) != string::npos){
													cout << "Record Exists " << endl;
													for (int i = 0; i < 1 && line != "/0"; i++){
														cout << line << endl;
													}
												}
											}
										}
										else{
											cout << "File is empty"<<endl;
										}
										cout << endl;
									}
									else if (choice == 2){
										passenger_update();
									}
									else if (choice == 3){

										ofstream obj;
										obj.open("book a ride.txt");
										passenger p;
										string location[10] = { "Model Town", "Township", "Faisal Town", "Bahria Town", "Wapda Town", "Valencia", "Pak Arab", "Central Park", "DHA","Johar Town" };
										string location2[10] = { "Model Town", "Township", "Faisal Town", "Bahria Town", "Wapda Town", "Valencia", "Pak Arab", "Central Park", "DHA", "Johar Town" };
										cout << "Book a ride" << endl;
										 location[rand() % 10];
										 location2[rand() % 10];
										cout << "Enter the name to whom you want to book a ride for: ";
										cin.ignore();
										getline(cin, p.name);
										cout << "Enter the date: ";
										cin >> p.m.date;
										cout << "Enter the month: ";
										cin.ignore();
										getline(cin, p.m.month);
										cout << "Enter the year: ";
										cin >> p.m.year;
										writeToFile1(p);
										cout << endl;
									}
									else if (choice == 6){
										string line;
										string search;
										cout << "Enter the name of passenger to whom the ride is booked" << endl;
										cin.ignore();
										getline(cin, search);
										ifstream obj;
										ofstream temp;
										ofstream temp2;
										obj.open("freerides.txt");
										cin.ignore();
										if (obj.is_open()){
											temp.open("cancelledrides.txt", ios::app);
											temp2.open("tempo.txt", ios::app);
											while (!obj.eof()){
												getline(obj, line);
												if (((line.find(search))) != string::npos){
													for (int i = 0; i < 1 && line != "/0"; i++){
														temp << line << endl;
													}
												}
												else{
													temp2 << line << endl;
												}
											}      temp.close();
											temp2.close();
											obj.close();
											remove("freerides.txt");
											rename("tempo.txt", "freerides.txt");
										}
									}
									else if (choice == 7){
										return 0;
									}
								}
							}
						}
					}
					else{
						cout << "No record exist" << endl;
					}
				}
				break;
			}
		}
				else if (choice == 3){
					//moving name and car was shifted in another cpp file submited earlier 
				}
				else if (choice == 4){
					return 0;
				}
		else{
			cout << "Wrong Choice" << endl;
		}
}
	return 0;
}
