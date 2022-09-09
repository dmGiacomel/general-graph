#ifndef GRAPHNODE_CPP
#define GRAPHNODE_CPP
#include "../listlib/List.hpp"

template <typename datatype> 
class GraphNode{

private:

    datatype data;
    List<GraphNode*> *adjacency; 

public: 

    GraphNode(); 
    GraphNode(datatype data);
    ~GraphNode();
    
    datatype getData();
    void setData(datatype data);
    
    List<GraphNode<datatype>*>* getAdjacencyList();

    void insertAdjacency(GraphNode *node);

    void printAdjacency();

};

template <typename datatype>
GraphNode<datatype>::GraphNode(){
    adjacency = new List<GraphNode*>();
    data = datatype(0);
}

template <typename datatype>
GraphNode<datatype>::GraphNode(datatype data){
    adjacency = new List<GraphNode*>();
    this->data = data;
}

template <typename datatype>
GraphNode<datatype>::~GraphNode(){
    delete(adjacency);
    data = datatype(0);
}

template <typename datatype>
datatype GraphNode<datatype>::getData(){
    return this->data;
}

template <typename datatype>
void GraphNode<datatype>::setData(datatype data){
    this.data = data;
}

template <typename datatype>
List<GraphNode<datatype>*>* GraphNode<datatype>::getAdjacencyList(){
    return adjacency;
}

template <typename datatype>
void GraphNode<datatype>::insertAdjacency(GraphNode<datatype> *node){

    if(!adjacency->elementExists(node)){
        adjacency->append(node);
    }
}


template <typename datatype>
void GraphNode<datatype>::printAdjacency(){

    unsigned long long int list_size = adjacency->getSize();

    std::cout << "Node: " << data << std::endl;
    std::cout << "Adjacency: ";

    for(unsigned long long int i{0}; i < list_size; i++){
        std::cout << adjacency->getElementByPosition(i)->getData() << " ";
    }

    std::cout << std::endl;
}
#endif