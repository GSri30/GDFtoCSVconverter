#include "CSV.h"

template<class T1,class T2,class T3>
CSV<T1,T2,T3>::CSV(){}

template<class T1,class T2,class T3>
CSV<T1,T2,T3>::CSV(vector<vector<T1>>tda,vector<T2>RowHeadings,vector<T3>ColumnHeadings,string deliminator){
    this->TwoDArray=tda;
    this->RowHeadings=RowHeadings;
    this->ColumnHeadings=ColumnHeadings;
    this->Deliminator=deliminator;
}

template<class T1,class T2,class T3>
CSV<T1,T2,T3>::~CSV(){
    this->ColumnHeadings.clear();
    this->RowHeadings.clear();
    this->TwoDArray.clear();
}

template<class T1,class T2,class T3>
CSV<T1,T2,T3>::CSV(const CSV&oldObj){
    this->TwoDArray=oldObj.TwoDArray;
    this->ColumnHeadings=oldObj.ColumnHeadings;
    this->RowHeadings=oldObj.RowHeadings;
    this->Deliminator=oldObj.Deliminator;
}


template<class T1,class T2,class T3>
void CSV<T1,T2,T3>::setTwoDArray(const vector<vector<T1>>&newtda){
    this->TwoDArray=newtda;
}

template<class T1,class T2,class T3>
const vector<vector<T1>>& CSV<T1,T2,T3>::getTwoDArray()const{
    return this->TwoDArray;
}

template<class T1,class T2,class T3>
void CSV<T1,T2,T3>::setRowHeadings(const vector<T2>&rowheadings){
    this->RowHeadings=rowheadings;
}

template<class T1,class T2,class T3>
const vector<T2>& CSV<T1,T2,T3>::getRowHeadings()const{
    return this->RowHeadings;
}

template<class T1,class T2,class T3>
void CSV<T1,T2,T3>::setColumnHeadings(const vector<T3>&columnheadings){
    this->ColumnHeadings=columnheadings;
}

template<class T1,class T2,class T3>
const vector<T3>& CSV<T1,T2,T3>::getColumnHeadings()const{
    return this->ColumnHeadings;
}

template<class T1,class T2,class T3>
void CSV<T1,T2,T3>::setDeliminator(string d){
    this->Deliminator=d;
}

template<class T1,class T2,class T3>
string CSV<T1,T2,T3>::getDeliminator()const{
    return this->Deliminator;
}


template<class T1,class T2,class T3>
void CSV<T1,T2,T3>::GenerateCSV(string outloc){

    try{
        int pos =  outloc.find(".");
        string token ;
        token = outloc.substr(pos + 1, outloc.size());

        if(token!="csv"){
            throw token;
        }

        ofstream file;
        file.open(outloc);

        int m=this->RowHeadings.size();
        int n=this->ColumnHeadings.size();

        for(int i=0;i<n;i++){
            file<<Deliminator<<this->ColumnHeadings[i];
        }
        file<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!j){
                    file<<this->RowHeadings[i];
                }
                file<<Deliminator<<setprecision(15)<<this->TwoDArray[i][j];
            }

            file<<endl;
        }
        
        file.close();
    } catch(string t){
        cerr<<"\u001B[31m"<<"Error : "<<"\u001B[0m"<<"Output file extension should be .csv : ."<<t<<" Provided"<<endl;
        exit(0);
    }

}


//Explicit instantiations
//Else we can define the functions in .h file itself to avoid explicit instantiations and support wide range of data types
template class CSV<double>;
template class CSV<string>;
template class CSV<int>;