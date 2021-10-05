#include "xmldocument.h"

#include <iostream>
#include <regex>

using namespace std;

XmlDocument::XmlDocument(const string &s)
{
    cmatch match;
    regex re (".*(<\\?xml\\s+.*\\?>)\\s*(<.*>).*");

    if (!std::regex_match(s.c_str(), match, re)) {
        cout << "Error document match" << endl;
        return;
    }

    if (match.size() == 3) {
        //cout << match[1] << endl;
        declaration = std::make_unique<XmlDeclaration>(match[1].str());

        //cout << match[2] << endl;
        rootElement = std::make_unique<XmlTableElement>(match[2].str());
    }
}
