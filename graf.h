#ifndef GRAF_H
#define GRAF_H
#include<iostream>

class graf
{
    int size_;
    int** mat_;
public:

    graf(int nr_noduri);
    graf(const graf& other);
    void add_muchie(int x, int y);
    void BFS(int nod);
    void DFS(int nod);
    int distanta(int x,int y);
    void afis_lista_adiacenta_nod(const int nod);
    virtual ~graf();
    graf operator+(const graf& other);
    graf operator-(const int nod);
    bool arbore();
    bool conex();
    int nr_noduri();
    int nr_muchii();
    graf& operator=(const graf& other);
    friend std::ostream& operator<<(std::ostream&, const graf&);

};

#endif // GRAF_H
