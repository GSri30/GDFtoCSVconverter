#ifndef ADJACENCYMATRIX_H_
#define ADJACENCYMATRIX_H_

#include<vector>
#include<unordered_map>
using namespace std;

class AdjacencyMatrix{
    //Class attributes
    private:
        int COUNTER;
        unordered_map<string,int>VertexList;
        vector<vector<bool>>HasEdge;
        vector<vector<double>>AMatrix;
        int Nodes;
        bool IsDirected;
    
    //Constructors
    public:
        AdjacencyMatrix();
        AdjacencyMatrix(int,bool=false);
        ~AdjacencyMatrix();
        AdjacencyMatrix(const AdjacencyMatrix&);

    //Member functions to add nodes, edges,  initialise the matrix etc
    public:
        void Init();
        void AddNode(string);
        void AddEdge(string,string,double=1);
        double GetWeight(string,string);
        bool Present(string);

    //Getters and Setters
    public:
        const unordered_map<string,int>&GetVertexList()const;
        const vector<vector<bool>>&GetEdges()const;
        const vector<vector<double>>&GetAMatrix()const;
        const int GetNodes()const;
        const bool GetIsDirected()const;

        void SetVertexList(const unordered_map<string,int>&);
        void SetEdges(const vector<vector<bool>>&);
        void SetAMatrix(const vector<vector<double>>&);
        void SetNodes(int);
        void SetIsDirected(bool);
        void SetCounter(int);
        void ResetCounter();
};

#endif