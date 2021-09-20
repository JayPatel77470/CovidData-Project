/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
Version 1.1
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
2021/07/18  Created this module
2021/07/21  Edited the read function and added a space after "OHIP:"
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {
	
	Patient::Patient(int TicketNumber, bool IOFlag) :m_ticket(TicketNumber) {
		m_IOFlag = IOFlag;
		m_name = nullptr;
		m_OHIPNumber = 0;
	}
	
	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}

	char Patient::type() const{
		return char(0);
	}
	
	bool Patient::fileIO() const {
		return m_IOFlag;
	}
	
	void Patient::fileIO(bool IOFlag) {
		m_IOFlag = IOFlag;
	}
	
	bool Patient::operator==(const char characterToCompare)const {
		bool ok = false;
		if (type())
			ok = true;
		
		return ok;
	}

	bool Patient::operator==(const Patient& obj)const {
		bool ok = false;
		if (this->type() == obj.type())
			ok = true;
		
		return ok;
	}
	
	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Patient::operator Time() const {
		return Time(m_ticket);
	}

	int Patient::number()const {
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr)const{
		ostr << this->type() << ",";
		ostr << m_name;
		ostr << "," << m_OHIPNumber << ",";
		m_ticket.csvWrite(ostr);
		
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr) {
		
		delete[] m_name;
		m_name = nullptr;
		char temp[100];
		istr.get(temp, 100, ',');
		m_name = new char[strlen(temp) + 1];
		strcpy(m_name, temp);
		istr.ignore(100, ',');
		istr >> m_OHIPNumber;
		istr.ignore(1000, ',');
		m_ticket.csvRead(istr);
		
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr) const {
		
		m_ticket.write(ostr) << endl;
		if (strlen(m_name) > 25)
		{
			for (int i = 0; i < 25; i++)
				ostr << m_name[i];
		}
		else
		{
			ostr << m_name;
		}
		ostr << ", OHIP: " << m_OHIPNumber;
		
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr) {
		
		cout << "Name: ";
		delete[] m_name;
		m_name = nullptr;
		char temp[100];
		istr.get(temp, 100, '\n');
		m_name = new char[strlen(temp) + 1];
		strcpy(m_name, temp);
		istr.ignore(1000,'\n');
		cout << "OHIP: ";
		m_OHIPNumber = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ", true);
		
		return istr;
	}
}