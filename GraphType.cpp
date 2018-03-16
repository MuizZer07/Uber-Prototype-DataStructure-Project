#ifndef GRAPHTYPE_CPP
#define GRAPHTYPE_CPP

#include "GraphType.h"

const int NULL_EDGE = 0;


template<class VertexType>
GraphType<VertexType>::GraphType()
{
    int maxV = 50;
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    edges = new double*[maxV];

    for(int i = 0; i < maxV; i++)
    edges[i] = new double[maxV];

    marks = new bool[maxV];
}
template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    edges = new int*[maxV];

    for(int i = 0; i < maxV; i++)
    edges[i] = new int[maxV];

    marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete [] vertices;

    for(int i = 0; i < maxVertices; i++)
    delete [] edges[i];

    delete [] edges;
    delete [] marks;
}

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
    vertices[numVertices] = vertex;
    for(int index = 0; index < numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}
template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
{
    int index = 0;
    while(!(vertex == vertices[index])) index++;

    return index;
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, double weight)
{
    int row;
    int col;
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    edges[row][col] = weight;
}
template<class VertexType>
VertexType* GraphType<VertexType>::getAllVertices()
{
    return vertices;
}
template<class VertexType>
int GraphType<VertexType>::getNumVertices()
{
    return numVertices;
}
template<class VertexType>
double GraphType<VertexType>::GetWeight(VertexType fromVertex, VertexType toVertex)
{
    int row;
    int col;
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::ShortestPath()
{
    path = edges;
    int i, j, k;
    int places = numVertices;
    for (k = 0; k < places; k++)
    {
        for (i = 0; i < places; i++)
        {
            for (j = 0; j < places; j++)
            {
                if ((path[i][k] * path[k][j] != 0) && (i != j))
                {
                    if ((path[i][k] + path[k][j] < path[i][j]) || (path[i][j] == 0))
                    {
                        path[i][j] = path[i][k] + path[k][j];
                    }
                }
                else if( i == j) path[i][j] = 0;
            }
        }
    }
}
template<class VertexType>
double GraphType<VertexType>::getShortestDistance(VertexType fromVertex, VertexType toVertex)
{
    int row;
    int col;
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    return path[row][col];
}
#endif // GRAPHTYPE_CPP
