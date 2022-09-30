#include <iostream>
#include "graphnode.hpp"
#include "arc.hpp"
#include "graph.hpp"


int main(){

    GraphNode<int> *graphnode1 = new GraphNode<int>(2);
    GraphNode<int> *graphnode2 = new GraphNode<int>(3);

    Arc<int, int> *arc = new Arc<int, int>(10);
    arc->setGraphNode(graphnode1);

    std::cout << arc->getNodeDestiny()->getData() << std::endl;

    arc->setGraphNode(graphnode2);
    std::cout << arc->getNodeDestiny()->getData() << std::endl;

    return 0;
}