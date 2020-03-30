#include "graf.h"
using namespace std;

graf::graf(int nr_noduri)
{
    size_=nr_noduri;
    mat_ = new int*[size_];
    for (int i = 0; i < size_; ++i)
        mat_ [i] = new int[size_];
}

graf::graf(const graf& other)
{
    if (size_ <= 0)
    {
        mat_ = NULL;
    }
    else
    {
        size_=other.size_;
        mat_ = new int*[size_];
        for (int i = 0; i < size_; ++i)
            mat_ [i] = new int[size_];
        for(int i=0; i<size_; i++)
            for(int j=0; j<size_; j++)
                mat_[i][j]=other.mat_[i][j];
    }
}

graf::~graf()
{
    for (int i = 0; i < size_; ++i)
        delete [] mat_[i];
    delete [] mat_;
    size_=0;
}

graf& graf::operator=(const graf& other)
{
    if (size_ <= 0)
    {
        mat_ = NULL;
    }
    else
    {
        size_=other.size_;
        mat_ = new int*[size_];
        for (int i = 0; i < size_; ++i)
            mat_ [i] = new int[size_];
        for(int i=0; i<size_; i++)
            for(int j=0; j<size_; j++)
                mat_[i][j]=other.mat_[i][j];
    }
}

void graf::add_muchie(int x, int y)
{
    mat_ [x][y]=mat_ [y][x]=1;
}

std::ostream& operator<<(std::ostream& out, const graf& g)
{
    for (int i = 1; i < g.size_; i++)
        for (int j = 1; j < g.size_; j++)
            if(g.mat_[i][j]==1)
                out<<i<<' '<<j<<'\n';
    return out;
}
