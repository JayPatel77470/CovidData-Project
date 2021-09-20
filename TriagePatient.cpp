/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <cstring>
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
	   m_listOfSymptoms = nullptr;
	   nextTriageTicket++;
   }

   TriagePatient::~TriagePatient() {
	   delete[] m_listOfSymptoms;
	   m_listOfSymptoms = nullptr;
   }

   char TriagePatient::type() const {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const {
	   Patient::csvWrite(ostr);
	   ostr << ",";
	   ostr << m_listOfSymptoms;

	   return ostr;
   }
   
   std::istream& TriagePatient::csvRead(std::istream& istr) {
	   delete[] m_listOfSymptoms;
	   m_listOfSymptoms = nullptr;
	   Patient::csvRead(istr);
	   istr.ignore(1000, ',');
	   
	   char temp[1000];
	   istr.getline(temp, 1000, '\n');
	   
	   m_listOfSymptoms = new char[strlen(temp) + 1];
	   strcpy(m_listOfSymptoms, temp);
	   nextTriageTicket = number() + 1;

	   return istr;
   }
   
   std::ostream& TriagePatient::write(std::ostream& ostr) const {
	   if (fileIO())
	   {
		   csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "TRIAGE" << std::endl;
		   Patient::write(ostr);
		   ostr << std::endl << "Symptoms: " << m_listOfSymptoms << std::endl;
	   }

	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr) {
	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   delete[] m_listOfSymptoms;
		   m_listOfSymptoms = nullptr;
		   Patient::read(istr);
		   std::cout << "Symptoms: ";

		   char temp[1000];
		   istr.getline(temp, 1000, '\n');
		   m_listOfSymptoms = new char[strlen(temp) + 1];
		   strcpy(m_listOfSymptoms, temp);
	   }
	   
	   return istr;
   }
  

}