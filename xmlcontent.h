#ifndef XMLCONTENT_H
#define XMLCONTENT_H

#include <vector>

#include "xmlelement.h"

using namespace std;

class XmlElement;

class XmlContent
{
public:
    XmlContent(const string &s);

    vector<XmlElement> children;
    string data;
};

#endif // XMLCONTENT_H
