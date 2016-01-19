#ifndef LexcoSorting_H
#define LexcoSorting_H

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/labeled_graph.hpp"
#include "boost/graph/topological_sort.hpp"
#include <deque>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
using namespace boost;

class LexcoSorting
{
    struct VertexProperty
    {
        char c_literal;
    };

    typedef boost::labeled_graph<boost::adjacency_list< boost::vecS, boost::vecS, boost::directedS,VertexProperty>,char> Graph;
    typedef boost::adjacency_list<>::vertex_descriptor Vertex;
    //typedef boost::labeled_graph<boost::setS, boost::vecS,boost::directedS,VertexProperty> Graph;
    typedef boost::graph_traits<Graph>::vertex_iterator vertex_iter;
    typedef std::vector<Graph::vertex_descriptor>  Vcontainer;

    Graph g;
//    list<Vertex> lVertex = new list<Vertex>(30);

    void AddVertex(char c_temp);
    void AddEdge(char sFirst,char sSecond);
    void PrintOutPut();


public:
    string Compare(string sPrevious,string sCurrent);
    void Execute(string sInputFile);
};

#endif // LexcoSorting_H


