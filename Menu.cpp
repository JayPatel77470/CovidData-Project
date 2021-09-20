/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {

	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}

	Menu::Menu(const Menu& obj) {
		m_text = nullptr;
		m_noOfSel = 0;
		if (obj.m_text != nullptr && obj.m_noOfSel != 0)
		{
			m_text = new char[strlen(obj.m_text) + 1];
			strcpy(m_text, obj.m_text);
			m_noOfSel = obj.m_noOfSel;
		}
	}

	Menu& Menu::operator=(const Menu& obj) {
		if (obj.m_text != nullptr && obj.m_noOfSel != 0 && *this)
		{
			delete[] m_text;
			m_text = nullptr;
			m_text = new char[strlen(obj.m_text) + 1];
			strcpy(m_text, obj.m_text);
			m_noOfSel = obj.m_noOfSel;
		}

		return *this;
	}

	Menu::operator bool() const {
		return (m_text != nullptr && m_noOfSel != 0);
	}

	void Menu::display()const {
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}
	

	int& Menu::operator>>(int& Selection) {
		display();
		int userSelection = getInt(0,m_noOfSel,"> ", "Invalid option ", true);
		Selection = userSelection;

		return Selection;
	}
}