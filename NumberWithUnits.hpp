/**
*Guy Cohen
*
*/




#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    class NumberWithUnits{
        private:
            double val;
            string type;


        public:
            NumberWithUnits(double, const string &);
            static void read_units(ifstream &units_file);
            static void add_values(const string &unit_a, const string &unit_b);
            /**
            *
            *arithmethic operators
            */
            NumberWithUnits operator+(const NumberWithUnits& num2);
            //NumberWithUnits operator+(double num);
            NumberWithUnits operator+();
            //NumberWithUnits operator-(double num);
            NumberWithUnits operator-(const NumberWithUnits& num2);
            NumberWithUnits operator-();
            NumberWithUnits operator+=(const NumberWithUnits& num2);
            NumberWithUnits operator-=(const NumberWithUnits& num2);

            /**
            *
            *comparison operators.
            *return boolean value
            */
            bool operator>(const NumberWithUnits& num2)const; //bigger
            bool operator<(const NumberWithUnits& num2)const; //smaller
            bool operator>=(const NumberWithUnits& num2)const;//bigger or equal
            bool operator<=(const NumberWithUnits& num2)const;//smaller or equal
            bool operator==(const NumberWithUnits &num2)const;//equal
            bool operator!=(const NumberWithUnits& num2)const;//not equal

            /*
            Operator name 	Syntax 	     	        Prototype examples
                                        Inside class definition 	Outside class definition
            pre-increment 	++a 	 	T& T::operator++(); 	    T& operator++(T& a);
            pre-decrement 	--a 	 	T& T::operator--(); 	    T& operator--(T& a);
            post-increment 	a++ 	 	T T::operator++(int); 	    T operator++(T& a, int);
            post-decrement 	a-- 	 	T T::operator--(int); 	    T operator--(T& a, int);
            */
            NumberWithUnits& operator++(); //++a
            NumberWithUnits& operator--(); //--a
            NumberWithUnits operator++(int);//a++
            NumberWithUnits operator--(int);//a--

            /*
            *
            *dup opertator
            */

            friend NumberWithUnits operator*(const NumberWithUnits& num1, double num);
            friend NumberWithUnits operator*(double num, const NumberWithUnits& num1);

            /**
            *
            *output and input
            */
            friend std::ostream &operator << (std::ostream& out, const NumberWithUnits& type);   //output
            friend std::istream &operator >> (std::istream& in, NumberWithUnits& type1);   //input
            

            


    };
};