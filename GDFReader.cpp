#include "GDFReader.h"


GDFReader::GDFReader(){}
GDFReader::GDFReader(string inputfilepath,string outputfilepath){
    this->setinputFilePath(inputfilepath);
    this->setoutputFilePath(outputfilepath);
}
GDFReader::~GDFReader(){}

inline string GDFReader::trim(string s){
    string str=s;
    str.erase(0, str.find_first_not_of(' '));     
    str.erase(str.find_last_not_of(' ')+1);
    return str;
}


//The input file can contain gaps and empty lines and also most of the other corner cases are handled by this code.

void GDFReader::ModifyFile(){
    try{
        int pos =  this->getinputFilePath().find(".");
        string t ;
        t = this->getinputFilePath().substr(pos + 1, this->getinputFilePath().size());

        if(t!="gdf"){
            throw t;
        }

        fstream file;
        file.open(this->getinputFilePath());
        
        if(!file.is_open()){
            throw 404;
        }

        Graph G;
        stringstream ss;

        string token;
        int namecolumn=0,node1column=0,node2column=0,weighcolumn=0,directedcolumn=0,currColumn=0;

        string line;getline(file,line);
        while(line==""){
            getline(file,line);
        }

        //Reading Nodedef
        if((trim(line).substr(0,8))==NODEDEF){
            ss<<trim(line).substr(8,line.length()-8);
            
            currColumn=0;
            while(getline(ss,token,',')){
                if(token.find("name")!=string::npos)namecolumn=currColumn;
                currColumn++;
            }

            ss.clear();

            while(getline(file,line) and trim(line).substr(0,8)!=EDGEDEF){
                ss<<line;
                currColumn=0;
                while(getline(ss,token,',')){
                    if(currColumn==namecolumn){
                        G.AddNode(trim(token));
                    }
                    currColumn++;
                }
                ss.clear();
            }
            
            G.Build();

        }
        
        //Reading Edgedef
        if(trim(line).substr(0,8)==EDGEDEF){
            ss<<trim(line).substr(8,line.length()-8);
            currColumn=0;
            while(getline(ss,token,',')){
                if(token.find("node1")!=string::npos)node1column=currColumn;
                if(token.find("node2")!=string::npos)node2column=currColumn;
                if(token.find("weight")!=string::npos)weighcolumn=currColumn;
                if(token.find("directed")!=string::npos)directedcolumn=currColumn;
                currColumn++;
            }
            
            ss.clear();

            while(getline(file,line)){
                ss<<line;
                currColumn=0;
                string node1,node2;double weight;bool directed;
                while(getline(ss,token,',')){
                    if(currColumn==node1column){
                        node1=trim(token);
                    }
                    else if(currColumn==node2column){
                        node2=trim(token);
                    }
                    else if(currColumn==weighcolumn){
                        weight=stod(trim(token));
                    }
                    else if(currColumn==directedcolumn){
                        directed=(trim(token)=="true");
                    }
                    currColumn++;
                }
                if(currColumn!=4)throw 504;
                G.AddEdge(node1,node2,weight);
                if(!directed){
                    G.AddEdge(node2,node1,weight);
                }
                ss.clear();
            }
        }

        G.GetCSVRepresentation(this->getoutputFilePath(),";");
        file.close();
        
        cout<<"\u001B[32m"<<"Generated the .csv successfully!"<<"\u001B[0m"<<endl;
    
    }
    catch(string t){
        cerr<<"\u001B[31m"<<"Error : "<<"\u001B[0m"<<"Input file extension should be .gdf : ."<<t<<" Provided"<<endl;
        exit(0);
    }
    catch(int i){
        if(i==404)
        cerr<<"\u001B[31m"<<"Error : "<<"\u001B[0m"<<"Couldn't find the file at the specified input path"<<endl;
        if(i==504)
        cerr<<"\u001B[31m"<<"Error : "<<"\u001B[0m"<<"Found some ambiguity in the input file"<<endl;
        exit(0);
    }
}