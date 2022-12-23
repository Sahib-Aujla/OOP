/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date: 23 November 2022
*/
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include "Text.h"
namespace sdds{
   class HtmlText:public Text{
        char* m_title{};
        public:
        HtmlText(const char* title=nullptr);
        HtmlText(const HtmlText& obj);
        HtmlText& operator=(const HtmlText&);
        ~HtmlText();

	    std::ostream& write(std::ostream&)const;
   };

}

#endif