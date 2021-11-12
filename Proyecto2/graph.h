#ifndef GRAPH_H
#define GRAPH_H
#include "iostream"
#include "stdlib.h"
#include "queue"
#include "list"
#include "stack"
#include <QString>
using namespace std;

class Arista;

class Vertice{
public:
    Arista *arisV;
    Vertice *vertV;
    string nom;
    friend class Graph;
};

class Arista{
public:
    Arista *arisA;
    Vertice *vertA;
    int num;
    friend class Graph;
};

class Graph
{
    Vertice *a;
public:
    void ProfPrimero(Vertice *comienzo, Vertice *final);
    void ProfRecorrido(Vertice *comienzo);
    void InsArista(Vertice *comienzo, Vertice *final, int num);
    void InsVertice(string nombre);
    void EliminarArista(Vertice *comienzo, Vertice *final);
    void EliminarVertice(Vertice *vert2);
    void Deny();
    string listAdyacente();
    Vertice *GetVertice (string nombre);
    void Start();
    bool Empty();
    int Size();
    string PrimMejor(Vertice *comienzo, Vertice *final);
    string lavel;
};

#endif // GRAPH_H
