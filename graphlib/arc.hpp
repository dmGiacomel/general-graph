#ifndef ARC_HPP
#define ARC_HPP
#include "graphnode.hpp"

template <typename datatype_arc, typename datatype_node>
class Arc{

private:

    datatype_arc data;
    GraphNode<datatype_node> *node_destiny;

public:

    Arc();
    Arc(datatype_arc data);
    Arc(GraphNode<datatype_node> *node_destiny);
    Arc(datatype_arc data, GraphNode<datatype_node> *node_destiny);
    ~Arc();

    datatype_arc getData();
    GraphNode<datatype_node>* getNodeDestiny();

    void setData(datatype_arc data);
    void setGraphNode(GraphNode<datatype_node> *node_destiny);
};

template <typename datatype_arc, typename datatype_node> 
Arc<datatype_arc, datatype_node>::Arc(){
    data = datatype_arc(0);
    node_destiny = nullptr;
}

template <typename datatype_arc, typename datatype_node>
Arc<datatype_arc, datatype_node>::Arc(datatype_arc data){
    this->data = data;
    node_destiny = nullptr;
}

template <typename datatype_arc, typename datatype_node>
Arc<datatype_arc, datatype_node>::Arc(GraphNode<datatype_node> *node_destiny){
    data = datatype_arc(0);
    this->node_destiny = node_destiny;
}

template <typename datatype_arc, typename datatype_node>
Arc<datatype_arc, datatype_node>::Arc(datatype_arc data, GraphNode<datatype_node> *node_destiny){
    this->node_destiny = node_destiny;
    this->data = data;
}

template <typename datatype_arc, typename datatype_node>
Arc<datatype_arc, datatype_node>::~Arc(){
    data = datatype_arc(0);
}

template <typename datatype_arc, typename datatype_node>
datatype_arc Arc<datatype_arc, datatype_node>::getData(){
    return this->data;
}

template <typename datatype_arc, typename datatype_node>
GraphNode<datatype_node>* Arc<datatype_arc, datatype_node>::getNodeDestiny(){
    return this->node_destiny;
}

template <typename datatype_arc, typename datatype_node>
void Arc<datatype_arc, datatype_node>::setData(datatype_arc data){
    this->data = data;
}

template <typename datatype_arc, typename datatype_node>
void Arc<datatype_arc, datatype_node>::setGraphNode(GraphNode<datatype_node> *node_destiny){
    this->node_destiny = node_destiny;
}

#endif