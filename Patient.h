/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
Version 1.0
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
2021/07/18  Created this module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#ifndef PATIENT_H_
#define PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"
#include "utils.h"
#include <fstream> 

namespace sdds {
	class Patient : public IOAble{
		char* m_name;
		int m_OHIPNumber;
		Ticket m_ticket;
		bool m_IOFlag;
		
	public:
		Patient(int TicketNumber = 0, bool IOFlag = false);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool IOFlag);
		bool operator==(const char characterToCompare)const;
		bool operator==(const Patient& obj)const;
		void setArrivalTime();
		operator Time() const;
		int number()const;
	    std::ostream& csvWrite(std::ostream&) const;
		std::istream& csvRead(std::istream&);
		std::ostream& write(std::ostream&) const;
		std::istream& read(std::istream&);	
	};
}
#endif // PATIENT_H_
