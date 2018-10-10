#include "QuanLy.h"
#include<iostream>
#include<string>
using namespace std;

QuanLy::QuanLy(int n) {
	this->n = n;
	this->data = new Person[this->n];
}
QuanLy::~QuanLy(void) {
	delete[] this->data;
}
//Show
void QuanLy::show() {
	for (int i = 0; i < this->n; i++) {
		cout <<i+1<<" ";
		(*(this->data+i)).showPerson();
	}
}
//Da nang hoa Nhap
istream &operator >>(istream&i, QuanLy&ql) {
	ql.data = new Person[ql.n];
	for (int i = 0; i < ql.n; i++)
	{
		cin >>*(ql.data+i);
	}
	return i;
}
//Da nang hoa Xuat
ostream &operator <<(ostream &o, QuanLy &ql) {
	for (int i = 0; i < ql.n; i++) {
		cout <<i+1<<" ";
		o <<*(ql.data+i);
	}
	return o;
}
//Da nang hoa phan tu thu k
Person& QuanLy::operator [](int k) {
	return *(this->data+k);
}

//thiet lap vi tri k co gia tri Person- modify
void QuanLy::setPerson(int k, Person ps) {
	*(this->data+k) = ps;
}
//Tang dan
bool tD(string left, string right) {
	if(left.compare(right)<0) {
		return true;
	}
	return false;
}
//Giam dan
bool gD(string left, string right) {
	if(left.compare(right)<0) {
		return false;
	}
	return true;
}
//Sap xep mergeSort
void QuanLy::merge(int l, int m, int r, bool (*q)(string left, string right)) {
	int i, j, k; 
	int n1 = m - l + 1; 
    int n2 =  r - m; 
	Person *dataL, *dataR;
	dataL = new Person[n1];
	dataR = new Person[n2];
	for (int i = 0; i < n1; i++) {
		*(dataL+i) = *(this->data+l+i);
	}
	for (int j = 0; j < n2; j++) {
		*(dataR+j) = *(this->data+m+1+j);
	}

	i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		//if((dataL+i)->ten.compare((dataR+j)->ten) <0) {******************
		if(q((dataL+i)->ten,(dataR+j)->ten)) {
			*(this->data+k) = *(dataL+i);
			i++;
		} else {
			*(this->data+k) = *(dataR+j);
			j++;
		}
		k++;
	}
	while (i < n1) 
	{ 
		//arr[k] = L[i]; 
		*(this->data+k)= *(dataL+i);
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		//arr[k] = R[j]; 
		*(this->data+k) = *(dataR+j);
		j++; 
		k++; 
	} 
}
void QuanLy::mergeSort(int l, int r) {
	if (l < r) { 

		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(l, m); 
		mergeSort(m+1, r); 
		merge(l, m, r, gD); 
	} 
}
int QuanLy::interpolationSearch(int size, int tuoi) {
	int left = 0;
	int right = size - 1;
	while(left <= right && (tuoi >= (this->data+left)->tuoi) && (tuoi <= (this->data+right)->tuoi)) {
		int pos = left + (float)(right - left) * (tuoi-(this->data+left)->tuoi) / 
			(((this->data +right)->tuoi)-((this->data+left)->tuoi));
		if((this->data + pos)->tuoi == tuoi) {
			return pos;
		} 
		if((this->data)[pos].tuoi < tuoi) {
			left = pos + 1;
		} else {
			right = pos - 1;
		}
	}
	return -1;
}