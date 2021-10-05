#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H

#include <string>
#include <memory>

#include "xmldeclaration.h"
#include "xmlelement.h"

using namespace std;

class XmlDocument
{
public:
    XmlDocument(const string &s);
    //~XmlDocument();

    unique_ptr<XmlDeclaration> declaration;
    unique_ptr<XmlTableElement> rootElement;
};

#endif // XMLDOCUMENT_H
