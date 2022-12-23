/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date: 23 November 2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "HtmlText.h"

namespace sdds
{
    HtmlText::HtmlText(const char *title)
    {
        if (title != nullptr )
        {
            delete[] m_title;
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    HtmlText::HtmlText(const HtmlText &obj):Text(obj)
    {
        m_title = nullptr;
        *this = obj;
    }
    HtmlText &HtmlText::operator=(const HtmlText &obj)
    {
        if (this != &obj)
        {
            delete[] m_title;
            (Text&)*this = obj;

            if (obj.m_title != nullptr)
            {
                m_title = new char[strlen(obj.m_title) + 1];
                strcpy(m_title, obj.m_title);
            }
        }
        return *this;
    }
    HtmlText::~HtmlText()
    {
        delete[] m_title;
    }
    std::ostream &HtmlText::write(std::ostream & os) const
    {
        os<<"<html><head><title>";
        if(m_title!= nullptr){
            os<<m_title;
        }else{
            os<<"No Title";
        }
        os<<"</title></head>\n<body>\n";
        bool MS=false;
        int i=0;
        
        const HtmlText& obj=*this;
        if (m_title != nullptr) {
            os << "<h1>" << m_title << "</h1>\n";
        }
        else {
            os << "No Title";
        }
        for ( i = 0; obj[i]; i++) {
            switch (obj[i]) {
            case ' ':
                if (MS == true) {
                    os << "&nbsp;";
                }
                else {
                    os << " ";
                    MS = true;
                }
                
                break;
            case '>':
                os << "&gt;";
                MS = false;

                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                os << obj[i];
                MS = false;
                break;
            }
        }
        os << "</body>\n</html>";

    return os;
    }
};