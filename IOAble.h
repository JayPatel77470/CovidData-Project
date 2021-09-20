/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h
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


#ifndef _IOABLE_H_
#define _IOABLE_H_
#include <iostream>
namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream&) const = 0;
		virtual std::istream& csvRead(std::istream&) = 0;
		virtual std::ostream& write(std::ostream&) const =  0 ;
		virtual std::istream& read(std::istream&) = 0;
		virtual ~IOAble() {};
	};
    
	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
	std::istream& operator>>(std::istream& istr, IOAble& obj);
}

#endif 