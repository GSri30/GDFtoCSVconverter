#ifndef GRAPH_H_
#define GRAPH_H_

#include "AdjacencyMatrix.h"
#include "CSV.h"

//Graph can be represented as a CSV file
//Hence it inherits CSV class 
class Graph:public CSV<double>{
    //Class attributes
    private:
        AdjacencyMatrix AM;
        vector<string>NodesList;
    //Constructors
    public:
        Graph();
        ~Graph();
        Graph(const Graph&);
    //Member functions
    //Used to add node and edge into the graph
    public:
        void AddNode(string );
        void AddEdge(string ,string ,double =0);

    //Getters and Setters
    public:
        void setAM(const AdjacencyMatrix&);
        const AdjacencyMatrix&getAM()const;
        void setNodes(int);
        int getNodes()const;
        void setIsDirected(bool);
        bool getIsDirected()const;
        void setNodesList(const vector<string>&);
        const vector<string>&getNodesList()const;

    //Functions to build the graph and to generate the CSV file of the current graph
    public:
        void GetCSVRepresentation(string,string =";");
        void Build();
};

#endif