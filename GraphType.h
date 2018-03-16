#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H
#include <iostream>
using namespace std;

template<class VertexType>
class GraphType
{

private:
    int numVertices;
    int maxVertices;
    VertexType* vertices;
    double **edges;
    bool* marks;
    double **path;
public:
    GraphType();
    GraphType(int);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty() const;
    VertexType* getAllVertices();
    bool IsFull() const;
    void AddVertex(VertexType);
    void AddEdge(VertexType, VertexType, double);
    double GetWeight(VertexType, VertexType);
    void ClearMarks();
    void MarkVertex(VertexType);
    bool IsMarked(VertexType) const;
    int getNumVertices();
    void ShortestPath();
    double getShortestDistance(VertexType, VertexType);

};
#endif // GRAPHTYPE_H
#include "GraphType.cpp"
