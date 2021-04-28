//#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <limits>//проверки, возможно уберу 
//#include <vector>
using namespace std;

void parse(){
    string line;
    //string power="Power:";
    string ValuePowerString;
    float ValuePowerFloat;
    setlocale(LC_ALL, "en");
    char buff[50];
    if(char(cin.peek()) == '\n')
    cin.ignore();

    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(32767, '\n');
    }

    ifstream PuttyIn;
    PuttyIn.open("text.txt");
    if (!PuttyIn.good())
    {
        std::clog << "Couldn't open file.\n";
        exit(1);
    }
    //PuttyIn >> buff;//считывание первой строки
    while (getline(PuttyIn, line)) {
        /*if (line==power){
        cout << buff << endl;
        }*/
        cout << line << endl;
        int pos = line.find("Power:"); // поиск значения в " "

        if (pos == -1){//прошла одна строка без искомого, - вывод чего-либо после этой строки
            //cout << "not finded" << endl;
            //cout  << "!!!!OK" << endl;
        }
        else{//значение найдено
            //cout << "finded in " << pos << " simvol position" << endl;
            //cout  << pos << endl;
            //cout  << "!!!!OK" << endl;
            //cout  << "line = " << line << endl;
            string PowerCharArray[6];
            int PowerIntArray[5];
            
            int CounterPowerCharArray=1;//номера ячеек в массиве символов PowerCharArray
            for(int CounterSymbolsPower=7; CounterSymbolsPower<12; CounterSymbolsPower++){//с какого по какой символ в строке line считывать
                ValuePowerString=line[CounterSymbolsPower];//посимвольный ввод значения в переменную ValuePowerString
                //ValuePowerString содержит в себе строку значения мощности (массив символов)
                //cout << "ValuePowerString = " << ValuePowerString << endl;
                PowerCharArray[CounterPowerCharArray]=ValuePowerString;
                cout << "PowerCharArray[CounterPowerCharArray]" << PowerCharArray[CounterPowerCharArray] << endl;//вывод значений символьного массива по порядку
                CounterPowerCharArray++;
                PowerIntArray[CounterPowerCharArray] = PowerCharArray [CounterPowerCharArray];
                
            }
            //double ValuePowerDouble = atof (std:: string (ValuePowerString));
        }

    }
    //cout << buff << endl;
    //PuttyIn.getline(buff, 50);
    //cout << buff << endl;
 
    /*if (buff==power){
        cout << buff << endl;
    }*/

    PuttyIn.close();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.clear();

    
}
int main(){
    parse();
    int count;
    /*while(1){//из parse() передать значение в main, когда file.eof(), если передано break
        parse();
    }*/
    /*while(1){
        if(!PuttyIn.eofbit){
            parse();
        }
        else{
            break;
        }
    }*/
}