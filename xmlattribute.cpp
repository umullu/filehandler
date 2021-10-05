#include "xmlattribute.h"

#include <iostream>
#include <regex>

XmlAttribute::XmlAttribute(const string &s)
{
    cmatch match;
    regex re ("(\\w+)\\s*=\\s*\"([^\"]+)\"");

    if (!regex_match(s.c_str(), match, re)) {
        cout << "Error attribute match" << endl;
        return;
    }

    if (match.size() > 0) {
        //cout << match[1] << endl;
        name = match[1];
    }
    if (match.size() > 1) {
        //cout << match[2] << endl;
        value = match[2];
    }
}
