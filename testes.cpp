#include <iostream>
#include "graphlib/graphnode.hpp"

int main (){

    GraphNode<int> *no, *no2, *no3;

    no = new GraphNode<int>(1);
    no2 = new GraphNode<int>(2);
    no3 = new GraphNode<int>(3);

    no->insertAdjacency(no2);
    no->insertAdjacency(no3);

    no2->insertAdjacency(no3);
    no2->insertAdjacency(no3);

    no->printAdjacency();
    no2->printAdjacency();

    return 0;
}