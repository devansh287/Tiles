#ifndef _tilelist_h
#define _tilelist_h

#include <iostream>
#include <string>
#include "tilenode.h"
using namespace std;

class TileList {
public:
    TileList();
    ~TileList();
    void addFront(TileNode* node);
    void addBack(TileNode* node);
    void clear();
    void debug();
    TileNode* getFront() const;
    void highlight(int x, int y);
    void lower(int x, int y);
    bool raise(int x, int y);
    TileNode* remove(int x, int y);
    int removeAll(int x, int y);

private:
    TileNode* front;
};

#endif // _tilelist_h
