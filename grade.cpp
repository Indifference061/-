#include <stdexcept>
#include <vector>
#include<string>
#include "grade.h"
#include "median.h"
#include "Core.h"
using std::domain_error;  using std::vector;
using std::string;
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	double mid = median(hw.begin(), hw.end());
	return grade(midterm, final, mid);
}

