#ifndef CSV_H_
#define CSV_H_

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

//Template class
//Only supports T1 of type int, double and string
template<class T1,class T2=string,class T3=string>
class CSV{
    //Class attributes
    private:
        vector<vector<T1>>TwoDArray;
        vector<T2>RowHeadings;
        vector<T3>ColumnHeadings;
        string Deliminator;

    //Constructors
    public:
        CSV();
        CSV(vector<vector<T1>>,vector<T2>,vector<T3>,string=";");
        ~CSV();
        CSV(const CSV&);

    //Getters and setters and Main function which generates the csv using the attributes
    protected:
        void setTwoDArray(const vector<vector<T1>>&);
        const vector<vector<T1>>&getTwoDArray()const;
        void setRowHeadings(const vector<T2>&);
        const vector<T2>&getRowHeadings()const;
        void setColumnHeadings(const vector<T3>&);
        const vector<T3>&getColumnHeadings()const;
        void setDeliminator(string);
        string getDeliminator()const;
        void GenerateCSV(string);
};


#endif