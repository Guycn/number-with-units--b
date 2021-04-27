/**
 *
 * @author Guy Cohen
 * @since 2021-04
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cfloat>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;
const int ten = 10;
const int eleven = 11;

void Initializes_unit_using_input(istringstream &input ,string str,NumberWithUnits& unit){
    input =istringstream{str};
    input >> unit;
}

int main() {

    double value = 0;
    string str = "";
    char flag = ' ';
    char _operator = ' ';
    string buffer;

    istringstream input;
    ofstream myfile("myUnitFile.txt");
    myfile << "1 km = 1000 m" << endl;
    myfile << "1 m = 100 cm" << endl;
    myfile << "1 kg = 1000 g" << endl;
    myfile << "1 ton = 1000 kg" << endl;
    myfile << "1 hour = 60 min" << endl;
    myfile << "1 min = 60 sec" << endl;
    myfile << "1 day = 24 hour" << endl;
    myfile << "1 month = 30 day" << endl;
    myfile << "1 year = 12 month" << endl;   
    myfile.close(); 
    ifstream units_file{"myUnitFile.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{2,"km"};
    NumberWithUnits b{2,"km"};

    cout << "Choose 2 numbers with unit and compare them:" << endl; //choose units 
    cout << "Type the first number with unit(value and unit):" << endl;
    cout << "For example 100[m]" << endl;
    getline(cin,str);
    Initializes_unit_using_input(input,str,a);
    cout << "Type the second number with unit(value and unit):" << endl;
    getline(cin,str);
    Initializes_unit_using_input(input,str,b);
    cout << "\na=" << a << endl;                             //new NumberWithunits a
    cout << "b=" << b << "\n" <<endl; 
    while(flag!='5'){
        cout << "1.comparison _operators.\n2.Arithmethic _operators.\n3.increment/decrement _operators.\n4.input new value.\n5.quit." << endl;
        flag = getchar();
        getline(cin,buffer);

        if(flag == '1'){
            cout << "Choose which action you want to perform:" << endl;
            cout << "1.a>b.\n2.a<b.\n3.a>=b.\n4.a<=b.\n5.a==b.\n6.a!=b" << endl;
            _operator = getchar();
            getline(cin,buffer);

            /**
            *
            *comparison _operators
            *
            */
            if(_operator == '1'){
                try{
                    if(a>b){
                        cout << "\nTrue a > b\n" << endl;
                    }
                    else{
                        cout << "\nFalse a < b\n" << endl;
                    }
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '2'){
                try{
                    if(a<b){
                        cout << "\nTrue a < b\n" << endl;
                    }
                    else{
                        cout << "\nFalse a > b\n" << endl;
                    }
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '3'){
                try{
                    if(a>=b){
                        cout << "\nTrue a >= b\n" << endl;
                    }
                    else{
                        cout << "\nFalse a < b\n" << endl;
                    }
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '4'){
                try{
                    if(a<=b){
                        cout << "\nTrue a <= b\n" << endl;
                    }
                    else{
                        cout << "\nFalse a > b\n" << endl;
                    }
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '5'){
                try{
                    if(a==b){
                        cout << "\nTrue a = b\n" << endl;
                    }
                    else{
                        cout << "\nFalse a != b\n" << endl;
                    }
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '6'){
                try{
                    if(a!=b){
                        cout << "\nTrue a != b\n" << endl;
                    }
                    else{
                        cout << "\nFalse a = b\n" << endl;
                    }
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else{
            cout << "\nWrong chice, try again...\n";
            }
        }

        /**
            *
            *Arithmethic _operators
            *
            */

        else if(flag == '2'){
            cout << "Choose which action you want to perform:" << endl;
            cout << "1.a+b.\n2.b+a.\n3.a+(double value).\n4.b+(double value).\n5.a-b.\n6.b-a\n7.a-(double value).\n8.b-(double value)\n9.a+=b.\nA.b+=a.\nB.a-=b.\nC.b-=a" << endl;
            _operator = getchar();
            getline(cin,buffer);
            if(_operator == '1'){       //a+b
                try{
                    NumberWithUnits c = a+b; 
                    cout << "\n" <<(a+b) << "\n" << endl;
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '2'){   //b+a
               try{
                   cout << "\n" << (b+a) << "\n" << endl;   
               }
               catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '3'){        //a+(double)number
                cout << "Type double number:" << endl;
                double num;
                cin >> num;
                getline(cin,buffer);
                cout << "\n" <<(a+num) << "\n" << endl;
            }
            else if(_operator == '4'){         ///b+(double)number
                cout << "Type double number:" << endl;
                double num;
                cin >> num;
                getline(cin,buffer);
                cout << "\n" <<(b+num) << "\n" << endl;
            }
            else if(_operator == '5'){   //a-b
                try{
                    cout << "\n" << (a-b) << "\n" << endl;
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '6'){   //b-a
                try{
                    cout << "\n" << (b-a) << "\n" << endl;
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == '7'){
                cout << "Type double number:" << endl;
                double num;
                cin >> num;
                getline(cin,buffer);
                cout << "\n" << (a-num) << "\n" << endl;
            }
            else if(_operator == '8'){
                cout << "Type double number:" << endl;
                double num;
                cin >> num;
                getline(cin,buffer);
                cout << "\n" << (b-num) << "\n" << endl;
            }
            else if(_operator == '9'){
                try{
                    cout << (a+=b) << endl;
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == 'A'){
                try{
                    cout << "\n" << (b+=a) << "\n" << endl;
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == 'B'){
                try{
                    cout << (a-=b) << endl;
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else if(_operator == 'C'){
                try{
                    cout << (b-=a) << endl;
                }
                catch(exception& e){
                    cout << "\nDifferent units.\n" << endl;
                }
            }
            else{
            cout << "\nWrong chice, try again...\n";
            }
        }
        
        else if(flag == '3'){
            cout << "Choose which action you want to perform:" << endl;
            cout << "1.a++.\n2.b++.\n3.++a.\n4.++b.\n5.a--.\n6.b--.\n7.--a.\n8.--b." << endl;
            _operator = getchar();
            getline(cin,buffer);
            if(_operator == '1'){
                cout << "\n" << (a++) << "\n" << endl; //a
                cout << "\n" << (a) << "\n" << endl; //a.value+1
            }
            else if(_operator == '2'){
                cout << "\n" << (b++) << "\n" << endl; //a
                cout << "\n" << (b) << "\n" << endl; //b.value+1
            }
            else if(_operator == '3'){
                cout << "\n" << (++a) << "\n" << endl; //a.value+1
            }
            else if(_operator == '4'){
                cout << "\n" << (++b) << "\n" << endl; //b.value+1

            }
            else if(_operator == '5'){
                cout << "\n" << (a--) << "\n" << endl; //a
                cout << "\n" << (a) << "\n" << endl; //a.value-1
            }
            else if(_operator == '6'){
                cout << "\n" << (b--) << "\n" << endl; //b
                cout << "\n" << (b) << "\n" << endl; //b.value-1
            }
            else if(_operator == '7'){
                cout << "\n" << (--a) << "\n" << endl; //a.value-1
            }
            else if(_operator == '8'){
                cout << "\n" << (--b) << "\n" << endl; //b.value-1
            }
            else{
            cout << "\nWrong chice, try again...\n";
            }

        }
        else if(flag == '4'){
            cout << "Type the first numberWithUnits value and units:\n For example: 300[km]" << endl;
            cin >> str;
            getline(cin, buffer);
            Initializes_unit_using_input(input,str,a);
            cout << "Type the second numberWithUnits value and units:" << endl;
            cin >> str;
            getline(cin, buffer);
            Initializes_unit_using_input(input,str,b);
            cout << "\na=" << a << endl;                             //new NumberWithunits a
            cout << "b=" << b << "\n" <<endl;                             //new NumberWithUnits b

        }

    }
}
