#ifndef GRAPHNODE_CPP
#define GRAPHNODE_CPP

template <typename datatype> 
class GraphNode{

private:

    datatype data;

public:

    GraphNode(); 
    GraphNode(datatype data);
    ~GraphNode();
    
    datatype getData();
    void setData(datatype data);
};

template <typename datatype>
GraphNode<datatype>::GraphNode(){
    data = datatype(0);
}

template <typename datatype>
GraphNode<datatype>::GraphNode(datatype data){
    this->data = data;
}

template <typename datatype>
GraphNode<datatype>::~GraphNode(){
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

#endif