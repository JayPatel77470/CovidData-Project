/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
Version 1.1
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
2021/07/04  Created this module
2021/07/18  Edited the read function due to some unconditional jumps errors
2021/07/23  Edited the read function as it was not accepting the zeros as a correct value.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

	Time& Time::setToNow() {
		this->m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		int hour;
		int minute;

		hour = m_min / 60;
		minute = m_min % 60;
		ostr.fill('0');
		ostr.width(2);
		ostr << hour;
		ostr << ":";
		ostr.fill('0');
		ostr.width(2);
		ostr << minute;

		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {
		int hour = 0;
		int minute = 0;
		char colon;
		int flag = 0;
		
		istr >> hour;
		istr >> colon;
		istr >> minute;
		if (hour <= 0 && minute <= 0)
		{
			flag = 1;
		}

		if (flag == 1 || cin.fail()) {
			istr.setstate(ios::failbit);
		}
		else {
			
			if (colon != ':' || cin.fail())
			{
				istr.setstate(ios::failbit);
			}
			else
			{
				
				if (flag == 1 || cin.fail())
				{
					istr.setstate(ios::failbit);
				}
				else
				{
					m_min = (hour * 60) + minute;
				}
			}
		}

		return istr;
	}

	Time& Time::operator-=(const Time& D) {
		while (this->m_min < D.m_min)
		{
			this->m_min += 1440;
		}

		this->m_min -= D.m_min;

		return *this;
	}

	Time Time::operator-(const Time& D)const {
		Time A;
		A.m_min = this->m_min;
		while (A.m_min < D.m_min)
		{
			A.m_min += 1440;
		}

		A.m_min = A.m_min - D.m_min;

		return A;
	}

	Time& Time::operator+=(const Time& D) {
		this->m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const {
		Time A;
		A.m_min = this->m_min;
		A.m_min += D.m_min;
		return A;
	}

	Time& Time::operator=(unsigned int val) {
		this->m_min = val;
		return *this;
	}

	Time& Time::operator *= (unsigned int val) {
		this->m_min = this->m_min * val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const {
		Time A;
		A.m_min = this->m_min;
		A.m_min = A.m_min * val;

		return A;
	}

	Time& Time::operator /= (unsigned int val) {
		this->m_min = this->m_min / val;

		return *this;
	}
	Time Time::operator /(unsigned int val)const {
		Time A;
		A.m_min = this->m_min;
		A.m_min = A.m_min / val;

		return A;
	}

	Time::operator int()const {
		return (int)m_min;
	}

	Time::operator unsigned int()const {
		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D) {
		D.read(istr);
		return istr;
	}
}