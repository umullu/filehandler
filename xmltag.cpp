#include "xmltag.h"

#include <iostream>
#include <regex>

XmlTag::XmlTag(const string &s)
{
    cmatch match;
    regex re ("<([\\?/]?)([^\\?]*)([\\?]?)>");
    if (!regex_match(s.c_str(), match, re)) {
        cout << "Error tag match" << endl;
        return;
    }

    if (match.size() == 4) {
        //cout << "Tag prefix: " << match[1] << endl;
        prefix = match[1].str();

        //cout << "Tag name: " << match[2] << endl;
        name = match[2].str();

        //cout << "Tag suffix: " << match[3] << endl;
        suffix = match[3].str();
    }
}

XmlAttrTag::XmlAttrTag(const string &s)
    : XmlTag(s)
{
    string body = name;
    cmatch match;
    regex re ("(\\w+)\\s*(.*)");
    if (!regex_match(body.c_str(), match, re)) {
        cout << "Error tag body match" << endl;
        return;
    }

    string data;
    if (match.size() == 3) {
        //cout << "Tag name: " << match[1] << endl;
        name = match[1].str();

        //cout << "Tag data: " << match[2] << endl;
        data = match[2].str();
    }

    regex r ("\\w+\\s*=\\s*\"[^\"]*\"");
    for(std::sregex_iterator i = std::sregex_iterator(data.begin(), data.end(), r);
                                 i != std::sregex_iterator();
                                 ++i) {
        smatch m = *i;
        //cout << "Tag attribute: " << m.str() << endl;
        attributes.push_back(XmlAttribute(m.str()));
    }
}

XmlStartTag::XmlStartTag(const string &s)
    : XmlAttrTag(s)
{
    //if (prefix != "" || suffix != "")
    //    cout << "Error: incorrect start tag" << endl;
}

XmlEndTag::XmlEndTag(const string &s)
    : XmlTag(s)
{
    if (prefix != "/" || suffix != "")
        cout << "Error: incorrect end tag" << endl;
}
