#pragma once
#ifndef Guard_Core_h
#define Guard_Core_h
#include<vector>
#include<string>
#include<iostream>
#include<ios>
#include<algorithm>
#include<fstream>
#include"grade.h"
#include"median.h"
class Core {
public:
	Core():midterm(0),final(0){}
	Core(std::ifstream& is) { read(is); }
	bool valid() const { return !homework.empty(); }
	std::string name() const{ return n; }
	virtual std::ifstream& read(std::ifstream&);
	virtual double grade() const;
	virtual ~Core(){}
protected:
	double midterm, final;
	std::ifstream& read_common(std::ifstream& is)
	{
		is >> n >> midterm >> final;
		return is;
	}
	std::vector<double> homework;
private:
	std::string n;
};
class Grad :public Core {
public:
	Grad():thesis(0) {}
	Grad(std::ifstream& is) { read(is); }
	double grade() const
	{
		return std::min(thesis, Core::grade());
	}
	std::ifstream& read(std::ifstream&);
private:
	double thesis;
};
bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
#endif // !Guard_Core_h
