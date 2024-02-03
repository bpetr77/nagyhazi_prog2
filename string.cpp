
#ifdef _MSC_VER
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>

#include "memtrace.h"
#include "string.h"

using std::cin;
using std::ios_base;

String::String(char ch) {
    len = 1;
    pData = new char[len+1];
    pData[0] = ch;
    pData[1] = '\0';
}



String::String(const char *p) {

    len = strlen(p);

    pData = new char[len+1];

    strcpy(pData, p);
}


String::String(const String& s1) {
    len = s1.len;
    if ((pData = s1.pData) == NULL) return;
    pData = new char[len+1];
    strcpy(pData, s1.pData);
}

String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s) {
        delete[] pData;
        len = rhs_s.len;
        if ((pData = rhs_s.pData) == NULL) return *this;
        pData = new char[len+1];
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}

char& String::operator[](unsigned int idx) {
    if (idx >= len) throw "String: indexelesi hiba";
    return pData[idx];
}

const char& String::operator[](unsigned int idx) const {
    if (idx >= len) throw "String: indexelesi hiba";
    return pData[idx];
}


String String::operator+(const String& rhs_s) const {
    String temp;
    temp.len = len + rhs_s.len;
    delete []temp.pData;

    if (temp.len == 0) {
        temp.pData = NULL;
        return temp;
    }
    temp.pData = new char[temp.len+1];

    if (pData == NULL)
        temp.pData[0] = '\0';
    else
        strcpy(temp.pData, pData);

    if (rhs_s.pData != NULL)
        strcat(temp.pData, rhs_s.pData);

    return temp;

}

bool String::operator==(const String& rhs_s)const {

    if(std::strcmp(this->pData, rhs_s.pData) == 0)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}


std::istream& operator>>(std::istream& is, String& s0) {
    char ch;
    String temp;

    std::ios_base::fmtflags fl = is.flags();
    is.setf(std::ios_base::skipws);

    while (is >> ch) {
        is.unsetf(std::ios_base::skipws);
        if (ch == '\n') {
            is.putback(ch);
            break;
        } else {
            temp += ch;
        }
    }

    is.setf(fl);
    s0 = temp;

    return is;
}

