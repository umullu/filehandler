#ifndef XMLTAG_H
#define XMLTAG_H

#include <string>
#include <vector>

#include "xmlattribute.h"

using namespace std;

class XmlTag
{
public:
    XmlTag(const string &s);

    string prefix;
    string name;
//    string data;
    string suffix;
};

class XmlAttrTag : public XmlTag
{
public:
    XmlAttrTag(const string &s);

    vector<XmlAttribute> attributes;
};

class XmlStartTag : public XmlAttrTag
{
public:
    XmlStartTag(const string &s);
};

class XmlEndTag : public XmlTag
{
public:
    XmlEndTag(const string &s);
};

#endif // XMLTAG_H
