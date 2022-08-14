#include"Core.h"
#include<algorithm>
#include<fstream>
#include<iostream>
#include"grade.h"
using std::istream;
using std::vector;
using std::ifstream;
bool compare(const Core& x, const Core& y)
{
	return x.name() < y.name();
}
bool compare_Core_ptrs(const Core* x, const Core* y)
{
	return compare(*x, *y);
}
ifstream& read_hw(ifstream& in, vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}
double Core::grade() const
{
	return::grade(midterm, final, homework);
}
ifstream& Core::read(ifstream& is)
{
	read_common(is);
	read_hw(is, homework);
	return is;
}
ifstream& Grad::read(ifstream& is)
{
	Core::read_common(is);
	is >> thesis;
	read_hw(is, homework);
	return is;
}
