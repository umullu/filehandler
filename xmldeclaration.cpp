#include "xmldeclaration.h"

#include <iostream>

XmlDeclaration::XmlDeclaration(const string &s)
    : XmlStartTag(s)
{
    //cout << "prefix=" << prefix << endl;
    //cout << "name=" << name << endl;
    //cout << "suffix=" << suffix << endl;
    if (prefix != "?" || name != "xml" || suffix != "?")
        cout << "Error: incorrect XML decloration tag" << endl;
}
