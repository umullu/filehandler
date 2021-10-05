#ifndef XMLATTRIBUTE_H
#define XMLATTRIBUTE_H

#include <string>

using namespace std;

class XmlAttribute
{
public:
    XmlAttribute(const string &s);

    string name;
    string value;
};

#endif // XMLATTRIBUTE_H
