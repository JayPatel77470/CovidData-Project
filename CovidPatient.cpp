/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
2021/07/21  Created this module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "CovidPatient.h"
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket){
	   nextCovidTicket++;
   }

   char CovidPatient::type() const {
	   return 'C';
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = number() + 1;
	   istr.ignore(1000,'\n');
	   
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) const {
	   if (fileIO())
	   {
		   Patient::csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "COVID TEST\n";
		   Patient::write(ostr);
		   ostr << std::endl;
	   }

	   return ostr;
   }
   
   std::istream& CovidPatient::read(std::istream& istr) {
	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   Patient::read(istr);
	   }

	   return istr;
   }
}