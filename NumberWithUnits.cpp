/**
*
*Guy Cohen
*
*/
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<cmath>
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;
const double EPS = 0.001;


namespace ariel{
    static map<string, map<string, double>> con_map;

    NumberWithUnits::NumberWithUnits(double val, const string& type){//init
    if(con_map.count(type) == 0){
            throw invalid_argument{"Unit doesn't exist in the units table!"};
        }
                this->type = type;
                this->val = val;
    }

    void NumberWithUnits::add_values(const string &unit_a, const string &unit_b){
        for(auto &var : con_map[unit_b]){
            if(var.first != unit_a){
                con_map[unit_a][var.first] = var.second*con_map[unit_a][unit_b];
                con_map[var.first][unit_a] = 1.0/(var.second*con_map[unit_a][unit_b]);
            }
        }
    }

    //read the units from the file
    void NumberWithUnits::read_units(ifstream &units_file){
        string unit_A;
        string unit_B;
        string buffer;
        double value1 = 0;
        double value2 = 0;
        while(!(units_file.eof())){
            units_file >> value1 >> unit_A >> buffer >> value2 >> unit_B;
            con_map[unit_A][unit_B] = value2;
            con_map[unit_B][unit_A] = 1/value2;
            add_values(unit_A,unit_B);
            add_values(unit_B,unit_A);
        }
    }
    /**
    *
    *arithmethic operators
    */
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& num2){ //+ operator
        double temp = 0;
        if(this->type == num2.type){
            return NumberWithUnits((this->val + num2.val), this->type);
        }
        try{
            temp = con_map.at(num2.type).at(this->type);
            //return NumberWithUnits(temp,this->type);
            return NumberWithUnits((this->val + (num2.val*temp)), this->type);
        }
        catch(exception& e){
            throw invalid_argument("Different units"); //different types of units
        }
    }

    //NumberWithUnits NumberWithUnits::operator+(double num){ //(+) operator
    //    return NumberWithUnits((this->val + num), this->type);
    //}

    NumberWithUnits NumberWithUnits::operator+(){
        NumberWithUnits ans(+this->val, this->type);
        return ans;
    }

    //NumberWithUnits NumberWithUnits::operator-(double num){//(-) operator
    //    return NumberWithUnits((this->val - num), this->type);
    // }

    NumberWithUnits NumberWithUnits::operator-(){
        return NumberWithUnits(-this->val, this->type);
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& num2){//(-) operator
        double temp = 0;
        if(this->type == num2.type){
            return NumberWithUnits((this->val - num2.val), this->type);
        }
        try{
            temp = con_map.at(num2.type).at(this->type);
            return NumberWithUnits((this->val - (num2.val*temp)), this->type); //different types of units
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }

    }

    NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits& num2){//(-=) operator
        double temp = 0;
        if(this->type == num2.type){
            this->val -= num2.val;
            return *this;
        }
        try{
            temp = con_map.at(num2.type).at(this->type);
            this->val -= num2.val*temp; 
            return *this;
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }

    }


    NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits &num2){//(+=) operator
        double temp = 0;
        if(this->type == num2.type){
            this->val += num2.val;
            return *this;
        }
        try{
            temp = con_map.at(num2.type).at(this->type);
            this->val += num2.val*temp; 
            return *this;
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }
    }
    /**
    *
    *comparison operators.
    *return boolean value
    */

    bool NumberWithUnits::operator>(const NumberWithUnits &num2)const{ //bigger
        double temp = 0;
        if(this->type == num2.type){
            return (this->val > num2.val); //if num1 value bigger than num2 value: return true, else return false
        }
        try{
            temp = con_map.at(num2.type).at(this->type); 
            return ((this->val - num2.val*temp)>0);               //if num1 value bigger than num2 value: return true, else return false
        }
        catch(exception& e){
            throw invalid_argument("Different units");   //different types of units
        }
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &num2)const{ //smaller
        double temp = 0;
        if(this->type == num2.type){
            return (this->val < num2.val);   //if num2 value bigger than num1 value: return true, else return false 
        }
        try{
            temp = con_map.at(num2.type).at(this->type); 
            return (this->val < num2.val*temp);    //if num2 value bigger than num1 value: return true, else return false
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &num2)const{//bigger or equal
        double temp = 0;
        if(this->type == num2.type){
            return ((this->val > num2.val) || this->val == num2.val);   //if num1 value bigger or equal than num2 value: return true, else return false 
        }
        try{
            temp = con_map.at(num2.type).at(this->type);
            return ((this->val > num2.val*temp) || (this->val == num2.val*temp));    //if num1 value bigger or equal than num2 value: return true, else return false 
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }
    }

    bool NumberWithUnits::operator<=(const NumberWithUnits &num2)const{//smaller or equal
        double temp = 0;
        if(this->type == num2.type){
            return ((this->val < num2.val) || (this->val == num2.val));   //if num2 value bigger or equal than num1 value: return true, else return false 
        }   
        try{
            temp = con_map.at(num2.type).at(this->type); 
            return ((this->val < num2.val*temp) || (this->val == num2.val*temp));    //if num2 value bigger or equal than num1 value: return true, else return false 
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }
    }

    bool NumberWithUnits::operator==(const NumberWithUnits &num2)const{//equal
        double temp = 0;
        if(this->type == num2.type){
            return (fabs(num2.val - this->val)<EPS);   //if num2 value equal to num1 value: return true, else return false 
        }
        try{
            temp = con_map.at(num2.type).at(this->type); 
            return (fabs(temp*num2.val - this->val)<EPS);    //if num2 value equal to num1 value: return true, else return false 
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &num2)const{//not equal
        double temp = 0;
        if(this->type == num2.type){
            return (!(this->val == num2.val));   //if num2 value not equal to num1 value: return true, else return false 
        }
        try{
            temp = con_map.at(num2.type).at(this->type); 
            return (!(fabs(temp*num2.val - this->val)<EPS));    //if num2 value not equal to num1 value: return true, else return false 
        }
        catch(exception& e){
            throw invalid_argument("Different units");//different types of units
        }
    }

    /*
    Operator name 	   Syntax 	     	        Prototype examples
    *                              Inside class definition 	  Outside class definition
    *pre-increment 	    ++a 	 	 T& T::operator++(); 	     T& operator++(T& a);
    *pre-decrement 	    --a 	 	 T& T::operator--(); 	     T& operator--(T& a);
    *post-increment 	a++ 	 	 T T::operator++(int); 	     T operator++(T& a, int);
    *post-decrement 	a-- 	 	 T T::operator--(int); 	     T operator--(T& a, int);
    */
    NumberWithUnits &NumberWithUnits::operator++(){ //++a
        ++this->val;
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator--(){ //--a
        --this->val;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int){//a++
        this->val ++;
        return NumberWithUnits(this->val - 1, this->type);
    }
    NumberWithUnits NumberWithUnits::operator--(int){//a--
        this->val--;
        return NumberWithUnits(this->val + 1, this->type);
    }

    /**
    *
    *dup operator
    *
    */
    NumberWithUnits operator*(const NumberWithUnits &num1, double num){
        return NumberWithUnits(num1.val * num, num1.type);
    }

    NumberWithUnits operator*(double num, const NumberWithUnits &num1){
        return NumberWithUnits(num*num1.val, num1.type);
    }

    /**
    *
    *output and input
    */
    ostream &operator << (std::ostream& out, const NumberWithUnits &type){
        return out << type.val << "[" << type.type << "]";
    }

    istream &operator >> (std::istream& in, NumberWithUnits &type1){
        if (con_map.find(type1.type) == con_map.end())
    {
        throw invalid_argument("Unit type not exist");
    }
        char tmp0 = ' ', tmp1 = ' ';
        string str = " ";
        double num = 0;
        in >> skipws >> num >> tmp0 >> str;
        uint ind = str.length() - 1;
        if (str.at(ind) != ']'){
            in >> tmp1;
            type1 = NumberWithUnits(num, str);
            return in;
        }
        else{
            str = str.substr(0, ind);
            type1 = NumberWithUnits(num, str);
            return in;
        }
    }
}