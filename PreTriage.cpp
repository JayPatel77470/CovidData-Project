/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
2021/07/30  Created this module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include <fstream>
#include <cstring>
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), 
												     m_averTriageWait(5),
													 m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		                                             m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
		                                             {
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage() {
		std::ofstream fp;
		fp.open(m_dataFilename);
		if (fp.is_open())
		{
			m_averCovidWait.write(fp);
			fp << ",";
			m_averTriageWait.write(fp);
			fp << std::endl;
			std::cout << "Saving Average Wait Times," << std::endl;
			std::cout << "   COVID Test: ";
			m_averCovidWait.write(std::cout);
			std::cout << std::endl;
			std::cout << "   Triage: ";
			m_averTriageWait.write(std::cout);
			std::cout << std::endl;
			std::cout << "Saving m_lineup..." << std::endl;
			for (int i = 0; i < m_lineupSize; i++)
			{
				std::cout << i + 1 << "- ";
				m_lineup[i]->csvWrite(fp);
				m_lineup[i]->csvWrite(std::cout);
				fp << std::endl;
				std::cout << std::endl;
			}
		}
		fp.close();
		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
			m_lineup[i] = nullptr;
		}
		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		std::cout << "done!" << std::endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p)const {
		unsigned int count = 0;
		Time obj;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (this->m_lineup[i]->type() == p.type())
				count++;
		}

		if (p.type() == 'C')
			obj = m_averCovidWait * (count);
		else if (p.type() == 'T')
			obj = m_averTriageWait * (count);

		return obj;
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time CT = getTime();
		Time PTT = Time(p);
		Time* AWT;
		unsigned int PTN = p.number();
		if (p.type() == 'C')
			AWT = &m_averCovidWait;
		else
			AWT = &m_averTriageWait;
		
		*AWT = ((CT - PTT) + (AWT->operator*(PTN - 1))) / PTN;

	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (type == this->m_lineup[i]->type())
				return i;
		}

		return -1;
	}

	void PreTriage::load() {
		std::cout << "Loading data..." << std::endl;
		std::ifstream fp;
		fp.open(m_dataFilename);
		if (fp.is_open())
		{
			m_averCovidWait.read(fp);
			fp.ignore(1000, ',');
			m_averTriageWait.read(fp);
			fp.ignore(1000, '\n');
			Patient* obj = 0;
			char firstchar;
			int flag = 0;
			for (int i = 0; i < maxNoOfPatients; i++)
			{
				firstchar = 0;
				flag = 0;
				fp >> firstchar;
				fp.ignore(1000, ',');
				if (std::cin.fail())
				{
					flag = 1;
				}
				else
				{
					if (firstchar == 'C') {
						obj = new CovidPatient;
					}
					else if (firstchar == 'T')
					{
						obj = new TriagePatient;
					}
					else
					{
						flag = 1;
					}
				}
				if (flag == 0)
				{
					obj->fileIO();
					obj->csvRead(fp);
					obj->fileIO(false);
					m_lineup[i] = obj;
					m_lineupSize++;
				}
				else
				{
					break;
				}
			}
		}
		    if (!fp.eof())
				std::cout << "Warning: number of records exceeded 100" << std::endl;
			if (m_lineupSize == 0)
				std::cout << "No data or bad data file!" << std::endl << std::endl;
			else
				std::cout << m_lineupSize << " Records imported..." << std::endl << std::endl;
		
		
		fp.close();
	}

	void PreTriage::reg() {
		if (m_lineupSize == maxNoOfPatients)
		{
			std::cout << "Line up full!" << std::endl;
		}
		else
		{
			int selection;
			int flag = 0;
			m_pMenu >> selection;

			switch (selection)
			{
			case 1:
			{
				m_lineup[m_lineupSize] = new CovidPatient;
			}
			break;
			case 2:
			{
				m_lineup[m_lineupSize] = new TriagePatient;
			}
			break;
			default:
			{
				flag = 1;
			}
			break;
			}

			if (flag == 1)
			{
				;
			}
			else
			{
				m_lineup[m_lineupSize]->setArrivalTime();
				std::cout << "Please enter patient information: " << std::endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(std::cin);
				std::cout << std::endl;
				std::cout << "******************************************" << std::endl;
				m_lineup[m_lineupSize]->write(std::cout);
				std::cout << "Estimated Wait Time: ";
				std::cout << getWaitTime(*m_lineup[m_lineupSize]) << std::endl;
				std::cout << "******************************************" << std::endl << std::endl;
				m_lineupSize++;
			}
		}
	}

	void PreTriage::admit() {
	
		int selection;
		int flag = 0;
		m_pMenu >> selection;
		int index = 0;
		switch (selection)
		{
		case 1:
		{
			
		    index = indexOfFirstInLine('C'); 
		}
		break;
		case 2:
		{
			index = indexOfFirstInLine('T');
		}
		break;
		default:
		{
			flag = 1;
		}
		break;
		}

		if (flag == 1)
		{
			;
		}
		else
		{
			char type = m_lineup[index]->type();
			int index = indexOfFirstInLine(type);

			if (index == -1)
			{
				;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "******************************************" << std::endl;
				m_lineup[index]->fileIO(false);
				std::cout << "Calling for ";
				m_lineup[index]->write(std::cout);
				std::cout << "******************************************" << std::endl << std::endl;
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}
		}
	}

	void PreTriage::run(void) {
		int selection;

		do {
			m_appMenu >> selection;
			switch (selection)
			{
			case 1:
			{
				reg();
			}
			break;
			case 2:
			{
				admit();
			}
			break;
			default:
			{
				;
			}
			break;
			}
		} while (selection != 0);
	}
}