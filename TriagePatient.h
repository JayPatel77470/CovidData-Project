/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
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

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {
     class TriagePatient : public Patient{
         char* m_listOfSymptoms;
     public:
         TriagePatient();
         ~TriagePatient();
         virtual char type() const;
         std::ostream& csvWrite(std::ostream&) const;
         std::istream& csvRead(std::istream&);
         std::ostream& write(std::ostream&) const;
         std::istream& read(std::istream&);
     };
}
#endif // !SDDS_TRIAGEPATIENT_H


