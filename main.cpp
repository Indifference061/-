#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include<fstream>
#include<random>
#include<time.h>
#include "grade.h"
#include "Core.h"
#include"median.h"
using std::cin;				using std::setprecision;
using std::cout;			using std::sort;
using std::domain_error;   	using std::streamsize;
using std::endl;			using std::string;
using std::max;				using std::vector;
using std::ifstream;
using std::ofstream;
int main()
{
	vector<Core*> students;
	Core* record;
	ifstream infile("grades2");
	string::size_type maxlen = 0;
	char ch;
	while (infile >> ch)
	{
		if (ch == 'U') record = new Core;
		else record = new Grad;
		record->read(infile);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare_Core_ptrs);
	for (vector<Core*>::size_type i = 0; i != students.size(); i++)
	{
		cout << students[i]->name()
			<< string(maxlen + 1 - students[i]->name().size(), ' ');
		try {
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout <<setprecision(3) << final_grade<<setprecision(prec)<<endl;
		}
		catch(domain_error e) {
			cout << e.what() << endl;
		}
		delete students[i];
	}
	return 0;
}