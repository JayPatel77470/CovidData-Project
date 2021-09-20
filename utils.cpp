/* Citation and Sources...
Final Project Milestone 5
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Jay Girishkumar Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/07/04  Preliminary release
2021/07/04  Created this module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt(const char* prompt) {
        int PROMPT;
        char newline;
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        cin >> PROMPT;
        cin.get(newline);
        int flag;
        do
        {
            flag = 0;
            if (cin.fail())
            {
                flag++;
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> PROMPT;
                cin.get(newline);
            }
        } while (flag > 0);

        do
        {
            flag = 0;
            if (newline != '\n')
            {
                flag++;
                cout << "Enter only an integer, try again: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> PROMPT;
                cin.get(newline);
            }

        } while (flag > 0);

        return PROMPT;
    }


    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
        if (prompt != nullptr)
        {
            cout << prompt;
        }

        int PROMPT;
        int flag;

        do {
            PROMPT = getInt();
            flag = 0;
            if (PROMPT < min || PROMPT > max)
            {

                if (errorMessage != nullptr)
                {
                    cout << errorMessage;

                    if (showRangeAtError == true)
                    {
                        cout << "[" << min << " <= value <= " << max << "]: ";
                    }
                }

                flag++;
            }
        } while (flag != 0);

        return PROMPT;
    }

    char* getcstr(const char* prompt, std::istream& istr, char delimiter) {

        char unknown_String[9999];
        char* unknown_String2;
        if (prompt != nullptr)
        {
            cout << prompt;
        }

        istr.getline(unknown_String, 9999, delimiter);

        unknown_String2 = new char[strlen(unknown_String) + 1];

        strcpy(unknown_String2, unknown_String);

        return unknown_String2;

    }
}