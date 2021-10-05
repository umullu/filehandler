#ifndef XMLDECLARATION_H
#define XMLDECLARATION_H

#include <string>

#include "xmltag.h"

using namespace std;

class XmlDeclaration : public XmlStartTag
{
public:
    XmlDeclaration(const string &s);
};

#endif // XMLDECLARATION_H
