#include <iostream>
#include <string>
class Sales_data
{
    friend std::istream& operator>>(std::istream&, Sales_data&);  // input
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);  // output
    friend Sales_data operator+(const Sales_data&, const Sales_data&);  // addition

public:
    //Sales_data();
    ~Sales_data();
    Sales_data(const std::string &s, unsigned n, double p) :bookno_(s), units_sold(n), revenue(p) {}
    Sales_data() :Sales_data("", 0, 0.0f) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(std::istream &is);

    Sales_data& operator+=(const Sales_data&);  // compound-assignment
    std::string isbn() const { return bookno_; }
private:
    inline double avg_price() const;

    std::string bookno_;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
