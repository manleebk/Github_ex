#pragma once
#include "Person.h"
#include<String>
#include<iostream>
using namespace std;

class QuanLy {
public:
	Person *data;
	int n; 
public:
	QuanLy(int);
	~QuanLy(void);
	void setPerson(int, Person);
	void show();
	friend istream &operator >>(istream &, QuanLy&);
	friend ostream &operator <<(ostream&, QuanLy&);
	Person &operator[](int);

	friend bool tD(string, string);
	friend bool gD(string, string);
	void merge(int, int, int,bool (*q) ( string , string));
	void mergeSort(int, int);
	//Tim kiem noi suy interpolationSearch(int size, int tuoi)
	int interpolationSearch(int, int);
};

