#include "xmlcontent.h"

#include <iostream>
#include <regex>

XmlContent::XmlContent(const string &s)
{
    string tag;
    string str = s;
    smatch match;
    regex re ("<([^>]*)>");
    while (!str.empty()) {
        if (regex_search(str, match, re)) {
            // cout << "Tag for searching:" << match[1] << endl;
            tag = match[1];
        } else {
            str = "";
            break;
        }

        regex r ("<"+tag+">.*?</"+tag+">");
        for(sregex_iterator i = sregex_iterator(s.begin(), s.end(), r);
                                     i != sregex_iterator();
                                     ++i) {
            smatch m = *i;
            //cout << "Content: " << m.str() << endl;
            children.push_back(XmlElement(m.str()));
            //cout << "Content position: " << m.position() << endl;
            str = m.suffix();
        }
    }
    if (!children.size())
        data = s;
}
