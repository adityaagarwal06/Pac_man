#ifndef GHOST_H
#define GHOST_H

#include<simplecpp>

class ghost
{
    public:
        Circle g;
        ghost();
        ghost(int ,int ,int );
        int ghostCapture(Circle );
        //bool ghostCapture(Circle );
        void ghost_random(int &,int &);
        void ghostMove(int ,int &,int &);
    protected:
    private:
};

#endif // GHOST_H
