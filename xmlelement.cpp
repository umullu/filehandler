#include "xmlelement.h"

#include <iostream>
#include <regex>

using namespace std;

XmlElement::XmlElement(const string &s)
{
    cmatch match;
    regex re ("(<[^>]*>)(.*)(<[^>]*>)");

    if (!std::regex_match(s.c_str(), match, re)) {
        cout << "Error element match" << endl;
        return;
    }

    if (match.size() == 4) {
        //cout << "Element start tag: " << match[1] << endl;
        startTag = std::make_unique<XmlStartTag>(match[1].str());

        //cout << "Element  content: " <<  match[2] << endl;
        content = std::make_unique<XmlContent>(match[2].str());

        //cout << "Element end tag: " <<  match[3] << endl;
        endTag = std::make_unique<XmlEndTag>(match[3].str());
    }
}


XmlTableElement::XmlTableElement(const string &s)
    : XmlElement(s)
{
    for( auto& r: content->children) {
        vector<string> cols;
        for (auto& c: r.content->children) {
            //cout << c.startTag->name << ": " << c.content->data << endl;
            cols.push_back(c.content->data);
        }
        rows.push_back(cols);
    }
}
