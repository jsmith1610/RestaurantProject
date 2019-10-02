#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int meat = 0;
	int veggie = 0;
	int pasta = 0;
	int potatoe = 0;
	int chocolate = 0;
	int fruit = 0;

	int apitizerAmt = 0;
	int mainCourseAmt = 0;
	int dessertAmt = 0;

	string apitizer;
	string mainCourse;
	string dessert;

	string message;/*This string is going to be used for if meat ties with veggie
	or if all the are less then 10*/
	string message2;//used if for some reason their is a tie for all the items

	double budget = 0;

	cout << "Welcome to Jake's Taco shop!" << endl;
	cout << "The chef will make your meal \n" << "based on your answers below." << endl;

	cout << "On a Scale of 1-100. How much do you like meat? ";
	cin >> meat;
	if (meat <= 0) {
		meat = 1;
	}
	else if (meat > 100) {
		meat = 100;
	}

	cout << "On a Scale of 1-100. How much do you like Vegetables? ";
	cin >> veggie;
	if (veggie <= 0) {
		veggie = 1;
	}
	else if (veggie > 100) {
		veggie = 100;
	}

	cout << "On a Scale of 1-100. How much do you like Pasta? ";
	cin >> pasta;
	if (pasta <= 0) {
		pasta = 1;
	}
	else if (pasta > 100) {
		pasta = 100;
	}

	cout << "On a Scale of 1-100. How much do you like Potatoes? ";
	cin >> potatoe;
	if (potatoe <= 0) {
		potatoe = 1;
	}
	else if (potatoe > 100) {
		potatoe = 100;
	}

	cout << "On a Scale of 1-100. How much do you like Chocolate? ";
	cin >> chocolate;
	if (chocolate <= 0) {
		chocolate = 1;
	}
	else if (chocolate > 100) {
		chocolate = 100;
	}

	cout << "On a Scale of 1-100. How much do you like fruit? ";
	cin >> fruit;
	if (fruit <= 0) {
		fruit = 1;
	}
	else if (fruit > 100) {
		fruit = 100;
	}

	cout << "What is your budget for dinner? ";
	cin >> budget;
	cout << endl;

	/*Here starts where we are going decide what food the chef
	is going to make for them*/
	if (budget >= 15 || budget <= 10) {//Checks to see if you can afford an apitizer either with a main course or just an apitizer
		apitizerAmt = 5;
		// This is for the Apitizers
		if (meat > veggie || meat == veggie) {
			apitizer = "Apitizer: Chicken Wings\n";
		}
		else if (meat < veggie) {
			apitizer = "Apitizer: Garden Salad\n";
		}
		else {
			apitizer = "Apitizer: Garlic Bread\n";
		}
	}
	//This is for the main course
	if (budget > 10) {
		mainCourseAmt = 10;
		if (meat < 10 && veggie < 10 && pasta < 10 && potatoe < 10) {
			message = "All the values are less then 10 so\n";
			mainCourse = "Main Course: Cheese Omelet\n";
		}
		else if (meat == veggie) {
			message = "Ties go to meat\n";
			if (pasta = potatoe) {
				message2 = "Tie goes to potatoes\n";
				mainCourse = "Main Course: Steak and Potatoes\n";
			}
		}
		else if (meat > veggie && potatoe > pasta) {//This is if meat amd potatoes are the greatest values
			mainCourse = "Main Course: Steak and Potatoes\n";
		}
		else if (meat < veggie) {//This is if Veggie is greater than meat
			mainCourse = "Main Course: Pasta Primavera\n";
		}
		else if (meat > veggie && pasta > potatoe) {/*This is if meat is greater than veggie
		and also if pasta is greater than potatoe*/
			mainCourse = "Main Course: Spaghetti and meat sauce\n";
		}

	}
	else {
		cout << "Sorry but you cannot afford a main course or Desert.\n";
	}
	//This is for the desert portion checking if they have enough and what their preference is.
	if (budget >= 20) {
		dessertAmt = 5;
		if (chocolate < 10 && fruit < 10) {
			dessert = "Vanilla ice cream\n";
		}
		else if (chocolate > fruit) {
			dessert = "Dessert: Chocolate Cake\n";
		}
		else {
			dessert = "Dessert: Apple pie\n";
		}
	}

	double tax = (apitizerAmt + mainCourseAmt + dessertAmt) * 0.07;
	double total = (apitizerAmt + mainCourseAmt + dessertAmt + tax);


	cout << message;
	cout << message2;

	cout << "Your surprise meal consists of... \n";
	cout << apitizer;
	cout << mainCourse;
	cout << dessert;
	cout << endl;

	cout << fixed << setprecision(2);
	cout << "Your bill for this meal is...\n";
	cout << "Meal: " << apitizerAmt + mainCourseAmt + dessertAmt << endl;
	cout << "Tax: " << tax << endl;
	cout << "Total after taxes: " << total << endl;
	return 0;
}