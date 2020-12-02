#include "Graph.h"

Graph::Graph(){}
Graph::~Graph(){
    this->NodesList.clear();
}
Graph::Graph(const Graph&oldObj){
    this->AM=oldObj.AM;
    this->NodesList=oldObj.NodesList;
}

void Graph::AddNode(string node){
    this->NodesList.push_back(node);
}
void Graph::AddEdge(string node1,string node2,double weight){
    AM.AddEdge(node1,node2,weight);
}


void Graph::setAM(const AdjacencyMatrix&am){
    this->AM=am;
}
const AdjacencyMatrix& Graph::getAM()const{
    return this->AM;
}
void Graph::setNodes(int n){
    this->AM.SetNodes(n);
}
int Graph::getNodes()const{
    return this->AM.GetNodes();
}
void Graph::setIsDirected(bool v){
    this->AM.SetIsDirected(v);
}
bool Graph::getIsDirected()const{
    return this->getIsDirected();
}
void Graph::setNodesList(const vector<string>&nl){
    this->NodesList=nl;
}
const vector<string>& Graph::getNodesList()const{
    return this->NodesList;
}

void Graph::GetCSVRepresentation(string outloc,string Deliminator){
    this->setRowHeadings(this->NodesList);
    this->setColumnHeadings(this->NodesList);
    this->setTwoDArray(AM.GetAMatrix());
    this->setDeliminator(Deliminator);
    this->GenerateCSV(outloc);
}

void Graph::Build(){
    AdjacencyMatrix am(this->NodesList.size());
    this->AM=am;
    for(int i=0;i<NodesList.size();i++){
        this->AM.AddNode(NodesList[i]);
    }
}