
#include <iostream>
#include <iomanip>

int k;                      // Брой учебни дисциплини
const int SIZE = 12;        // Максимална дължина на име
const int SIZE_MAX1= 10;    // Максимален брой yчебни дициплини
const int SIZE_MAX2 = 25;   // Максимален брой студенти в групата

struct Student {
	int fac_num;
	char name[SIZE];
	double subjects[SIZE_MAX1];
};

void create_student(Student& s) {

	do {
		std::cout << "Faculty Number: ";
		std::cin >> s.fac_num;
	} while (s.fac_num < 0 || s.fac_num > 99999);

	std::cout << "Family name: ";
	std::cin >> s.name;

	for (int i = 0; i < k; i++) {
		std::cout << "Grade in " << i + 1 << "th subject: ";
		std::cin >> s.subjects[i];
	}
}

void show_students_data(const Student& s) {

	std::cout << std::setw(5) << s.fac_num
		<< std::setw(SIZE + 2) << s.name;
	for (int i = 0; i < k; i++) {
		std::cout << std::setw(5) << s.subjects[i];
	}
}

double average_grades(const Student& s){

	double grade = 0;
	for (int i = 0; i < k; i++) {
		grade += s.subjects[i];
	}
	grade /= k;
	return grade;
}

// a) Input the data for the students of the group

void create_group(int n, Student *s) {

	for (int i = 0; i < n; i++) {
		std::cout << "Data for " << i + 1 << "th stdudent: ";
		create_student(s[i]);
	}
}

// b) Showing the table
void print_table() {

	std::cout << std::setiosflags(std::ios::fixed | std::ios::showpoint)
		<< std::setprecision(2);
	for (int i = 0; i < 5 + SIZE + 2 + 5 * (k + 1) + 1; i++) {
		std::cout << "=";
	}

	std::cout << std::endl;
	std::cout << "F.N."
		<< std::setw(SIZE + 2) << "Family";

	for (int i = 0; i < k; i++) {
		std::cout << std::setw(4) << "D-" << i + 1;
	}
	std::cout << std::setw(6) << "Cp.y." << std::endl;

	for (int i = 0; i < 5 + SIZE + 2 + 5 * (k + 1) + 1; i++) {
		std::cout << "=";
	}
	std::cout << std::endl;
}

void print_table_group(int n, Student* s) {

	print_table();

	// Average grade per subject
	double temp[SIZE_MAX1] = { 0, };
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			temp[i] = temp[i] + s[j].subjects[j];
		}
		temp[i] = temp[i] / n;
	}

	// Prints the data of students and evaluates average
	// grade of all students

	double sum = 0;
	for (int i = 0; i < n; i++) {
		show_students_data(s[i]);
		double result = average_grades(s[i]);
		sum += result;
		std::cout << std::setw(6) << result << std::endl;
	}
	for (int i = 0; i < 5 + SIZE + 2 + 5 * (k + 1) + 1; i++) {
		std::cout << "=";
	}

	// Printing the data for all students marks for all subjects

	std::cout << std::endl << std::setw(5 + SIZE + 5 + 2) << temp[0];
	for (int i = 1; i < k; i++) {
		std::cout << std::setw(5) << temp[i];
	}
	std::cout << std::setw(6) << sum / n << std::endl;
}


// c) 
// Sorting the array by decsending order by the average 
// grade of the array of pointers to the data of the students
// with the help of short section method

void sortGroup(int n, Student** s) {
	for (int i = 0; i < n-1; i++) {
		int k = i; 
		double max = average_grades(*s[k]);
		for (int j = i + 1; j < n; j++) {
			double d = average_grades(*s[j]);
			if (d > max) {
				max = d;
				k = j;
			}
		}
		Student* x;
		x = s[i];
		s[i] = s[k];
		s[k] = x;
	}
}

// d) showing the ^^

void print_sort_group(int n, Student** s) {
	print_table();
	for (int i = 0; i < n; i++) {
		show_students_data(*s[i]);
		double result = average_grades(*s[i]);
		std::cout << std::setw(6) << result << std::endl;
	}
}

int main(){
	// insert the number of subjects
	do {
		std::cout << "Please insert value from 1 to " << SIZE_MAX1 << ": ";
		std::cin >> k;
	} while (k < 1 || k > SIZE_MAX1);

	// Inserting the number of students in the group
	int n;
	do {
		std::cout << "Please insert value from 1 to " << SIZE_MAX2 << ": ";
		std::cin >> n;
	} while (n < 1 || n > SIZE_MAX2);

	Student s[SIZE_MAX2];
	Student* ps[SIZE_MAX2];
	create_group(n, s);
	print_table_group(n, s);
	for (int i = 0; i < n; i++) {
		ps[i] = &s[i];
	}
	sortGroup(n, ps);
	std::cout << std::endl;
	print_sort_group(n, ps);

	return 0;
}