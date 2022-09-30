#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graphnode.hpp"
#include "arc.hpp"
#include "../listlib/List.hpp"

template<typename datatype_arc, typename datatype_node>
class HashEntry{
public:
    GraphNode<datatype_node> *node;
    List<Arc<datatype_arc, datatype_node>*> *ajacency;
};

template <typename datatype_arc, typename datatype_node>
class Graph{

private:

    List<GraphNode<datatype_arc>> *arc_list;
    List<GraphNode<datatype_node>> *node_list;
    List<HashEntry> *adjacency_lists;

public:

    Graph();
    ~Graph();

    void insertNode();
    void insertArc();

    void removeArc();

};

#endif