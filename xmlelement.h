#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <string>
#include <memory>
#include <map>
#include <vector>

#include "xmltag.h"
#include "xmlcontent.h"

using namespace std;

class XmlContent;

class XmlElement
{
public:
    XmlElement(const string &s);

    unique_ptr<XmlStartTag> startTag;
    unique_ptr<XmlContent> content;
    unique_ptr<XmlEndTag> endTag;
};

class XmlTableElement: public XmlElement
{
public:
    XmlTableElement(const string &s);

    vector<vector<string>> rows;
private:
};

#endif // XMLELEMENT_H
