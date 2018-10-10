#include "Person.h"
#include "QuanLy.h"
#include<iostream>
using namespace std;

int main() {
	QuanLy ql01(5);
	Person ps01("A",11,"aaa",1);
	Person ps02("T",33,"fff",1);
	Person ps03("E",88,"ccc",1);
	Person ps04("D",22,"ggg",1);
	Person ps05("C",55,"ddd",1);

	ql01.setPerson(0,ps01);
	ql01.setPerson(1,ps02);
	ql01.setPerson(2,ps03);
	ql01.setPerson(3,ps04);
	ql01.setPerson(4,ps05);

	cout <<ql01;
	cout <<"----------------------"<<endl;
	//cout <<ql01[1];

	ql01.mergeSort(0, 4);
	cout <<ql01;
	//cout <<"vi tri can tim la: "<<ql01.interpolationSearch(5,2211)<<endl;
	system("pause");
	return 0;
}