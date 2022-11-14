/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_

namespace sdds {
    class Numbers {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);
    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers&);
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();

        Numbers& sort(bool ascending);
        Numbers operator-()const;
        Numbers operator+()const;
        Numbers& operator=(const Numbers&);
        Numbers& operator+=(double);
        std::ostream& display(std::ostream& ostr )const;

        bool load();
        int numberCount()const;
        void save();
        
    };

    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

