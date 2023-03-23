
#include <iostream>

int validation(int&);

const int SIZE = 16;
const int SIZE_max = 20;

struct Person {
	char first_name[SIZE];
	char last_name[SIZE];
};

// intput the data of the person
void read_person(Person& P) {
	std::cout << "First name: " << std::endl;
	std::cin >> P.first_name;
	std::cout << "Last name: " << std::endl;
	std::cin >> P.last_name;
}

// output of the data of the person
void print_person(const Person& P) {
	std::cout << "First name: " << P.first_name << std::endl;
	std::cout << "Last name: " << P.last_name << std::endl;
}

struct Client {
	Person name;
	double amount; //sum in the bank account
};

void read_client(Client& C) {
	std::cout << "Name of the client: \n";
	read_person(C.name);
	std::cout << "Amount of the client: ";
	std::cin >> C.amount;
}

void print_client(const Client& C) {
	std::cout << "Name of the client: \n";
	print_person(C.name);
	std::cout << "Amount of the client: " << C.amount << std::endl;
}

int main() {
	// a)
	// input the data with single array
	std::cout << "Insert the data for n from 1 to " << SIZE_max << ": ";
	int n;
	std::cin >> n;
	validation(n);
	Client arr[SIZE_max];
	for (int i = 0; i < n; i++) {
		read_client(arr[i]);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// b)
	// outputs the data 
	std::cout << "Clients of the bank: \n";
	for (int i = 0; i < n; i++) {
		print_client(arr[i]);
		std::cout << std::endl;
	}

	//c)
	// Sum of the duty
	double sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].amount < 0) {
			sum += arr[i].amount;
			std::cout << "Sum of the duty of the clients is: " << sum << std::endl;
		}
		else std::cout << "There is no duty of the clients \n";
	}

	return 0;
}

int validation(int& n) {
	if (n < 1 || n > 20) {
		std::cout << "Please insert correct number: ";
		std::cin >> n;
		validation(n);
	}
	system("cls");
	return n;
}