#include "AdjacencyMatrix.h"


AdjacencyMatrix::AdjacencyMatrix(){
    this->COUNTER=0;
}
AdjacencyMatrix::AdjacencyMatrix(int Nodes,bool IsDirected){
    this->Nodes=Nodes;
    this->IsDirected=IsDirected;
    this->COUNTER=0;
    this->Init();
}
AdjacencyMatrix::~AdjacencyMatrix(){
    this->VertexList.clear();
    this->HasEdge.clear();
    this->AMatrix.clear();
}
AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix&oldObj){
    this->AMatrix=oldObj.AMatrix;
    this->COUNTER=oldObj.COUNTER;
    this->HasEdge=oldObj.HasEdge;
    this->IsDirected=oldObj.IsDirected;
    this->Nodes=oldObj.Nodes;
    this->VertexList=oldObj.VertexList;
}

void AdjacencyMatrix::Init(){
    int n=this->Nodes;
    HasEdge.resize(n);
    AMatrix.resize(n);
    for(int i=0;i<n;i++){
        HasEdge[i]=vector<bool>(this->Nodes);
        AMatrix[i]=vector<double>(this->Nodes);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            HasEdge[i][j]=false;
            AMatrix[i][j]=0;
        }
    }
}

void AdjacencyMatrix::AddNode(string u){
    if(VertexList.find(u)==VertexList.end()){
        VertexList[u]=this->COUNTER++;
    }
    return;
}

void AdjacencyMatrix::AddEdge(string u,string v,double weight){
    int U,V;
    if(VertexList.find(u)!=VertexList.end()){
        U=VertexList[u];
    }
    else{
        U=this->COUNTER;
        VertexList.insert(make_pair(u,AdjacencyMatrix::COUNTER));
        this->COUNTER++;
    }
    if(VertexList.find(v)!=VertexList.end()){
        V=VertexList[v];
    }
    else{
        V=this->COUNTER;
        VertexList.insert(make_pair(v,AdjacencyMatrix::COUNTER));
        this->COUNTER++;
    }
    if(IsDirected){
        HasEdge[U][V]=true;
        HasEdge[V][U]=true;
        AMatrix[U][V]=weight;
        AMatrix[V][U]=weight;
    }
    else{
        HasEdge[U][V]=true;
        AMatrix[U][V]=weight;
    }
}

double AdjacencyMatrix::GetWeight(string u,string v){
    int U,V;
    if(VertexList.find(u)!=VertexList.end() and VertexList.find(v)!=VertexList.end()){
        U=VertexList[u];
        V=VertexList[v];
        if(HasEdge[U][V]){
            return AMatrix[U][V];
        }
    }
    return 0;
}
bool AdjacencyMatrix::Present(string u){
    if(VertexList.find(u)!=VertexList.end()){
        return true;
    }
    return false;
}

const unordered_map<string,int>& AdjacencyMatrix::GetVertexList()const{
    return this->VertexList;
}
const vector<vector<bool>>& AdjacencyMatrix::GetEdges()const{
    return this->HasEdge;
}
const vector<vector<double>>& AdjacencyMatrix::GetAMatrix()const{
    return this->AMatrix;
}
const int AdjacencyMatrix::GetNodes()const{
    return this->Nodes;
}
const bool AdjacencyMatrix::GetIsDirected()const{
    return this->IsDirected;
}

void AdjacencyMatrix::SetVertexList(const unordered_map<string,int>&vlist){
    this->VertexList.clear();
    this->VertexList=vlist;
}
void AdjacencyMatrix::SetEdges(const vector<vector<bool>>&edges){
    this->HasEdge.clear();
    this->HasEdge=edges;
}
void AdjacencyMatrix::SetAMatrix(const vector<vector<double>>&amatrix){
    this->AMatrix.clear();
    this->AMatrix=amatrix;
}
void AdjacencyMatrix::SetNodes(int n){
    this->Nodes=n;
}
void AdjacencyMatrix::SetIsDirected(bool isd){
    this->IsDirected=isd;
}
void AdjacencyMatrix::SetCounter(int c){
    this->COUNTER=c;
}
void AdjacencyMatrix::ResetCounter(){
    this->COUNTER=0;
}