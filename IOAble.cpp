/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
2021/07/12  Created this module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	std::ostream& IOAble::csvWrite(std::ostream& ostr)const {
		return ostr;
	}
    std::istream& IOAble::csvRead(std::istream& istr){
		return istr;
	}
	std::ostream& IOAble::write(std::ostream& ostr)const {
		return ostr;
	}
	std::istream& IOAble::read(std::istream& istr) {
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj) {
		obj.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, IOAble& obj) {
		obj.read(istr);
		return istr;
	}
}