// Hi! This class has the entire functions required

#include "tilelist.h"

//constructor, initializing the front as a null pointer
TileList::TileList()
{
    front = nullptr;
}

//the destructor
TileList::~TileList()
{
    TileNode* curr = front;
    //traversing through the loop and deleting each value
    while (curr != nullptr)
    {
        int x = curr->x;
        int y = curr->y;

        curr = curr->next;

        //calling remove function on the present node's x and y values
        //and storing the return in a temporary node and deleting it

        TileNode* temp = remove (x, y);
        delete temp;
    }
}

//adding something to the back of the list
void TileList::addBack(TileNode* newNode)
{
    TileNode* temp = front;
    //if the list is empty or not
    if (temp != nullptr)
    {
        //going to the list till one reaches the lasgt node
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        //adding the desired node to the last node as its next
        temp->next = newNode;
        temp->next->next = nullptr;
    }
    else
    {
        front = newNode;
    }
}

//adding something to the front of the list
void TileList::addFront(TileNode* newNode)
{
    TileNode* temp = front;
    front = newNode;
    front->next = temp;
}

void TileList::debug() {
    // TODO: write this function (optional)

}

//returning the front of the list
TileNode* TileList::getFront() const
{
    return front;
}

//highlighting the a node in the list
void TileList::highlight(int x, int y)
{
    TileNode* temp = front;
    //going through the list until one reaches the x, y coordinates
    //of the desired tile
    while (temp != nullptr)
    {
        if(temp->contains (x, y))
        {
            //setting the color of the tile to yellow once on reaches it
            temp->color = "yellow";
            break;
        }
        temp = temp->next;
    }
}

//lowering the selected tile
void TileList::lower (int x, int y)
{
    TileNode* temp = front;
    //traversing the list till we find the tile
    while (temp != nullptr)
    {
        if (temp->contains(x, y))
        {
            //removing the tile
            temp = remove(x,y);
            //then adding it to the back
            addBack(temp);
            break;
        }
        temp = temp->next;
    }

}

//raising a tile to the top, and checking if something has been raised or not
bool TileList::raise(int x, int y)
{
    TileNode* temp = front;
    TileNode* dup;

    //value to be returned
    bool b = false;

    //traversing the list till we find the tile
    while (temp != nullptr)
    {
        if (temp->contains(x, y))
        {
            //setting the return value to be true
            b = true;

            //removing the tile
            temp = remove(x,y);

            //then adding it to the front
            addFront(temp);
            break;
        }
        temp = temp->next;
    }
    return b;
}

//removing a tile from the list
TileNode* TileList::remove (int x, int y)
{
    //the return value
    TileNode* removal;

    TileNode* curr = front;

    //if the value to be removed is at the front
    if (curr != nullptr && curr->contains(x,y))
    {
        removal = curr;
        front = curr->next;
        removal->next=nullptr;
        return removal;
    }

    //traversing the list till the required tile is found
    while (curr->next != nullptr)
    {
        if (curr->next->contains(x,y))
        {
            //setting the return value
            removal = curr->next;

            //removing it from the list and adjusting the list accordingly
            curr->next = curr->next->next;

            //setting the next value of the returned node to nullptr
            removal->next = nullptr;

            //returning the appropriate value
            return removal;
        }
        curr = curr->next;
    }
    return nullptr;
}

//removing all nodes at a point
int TileList::removeAll(int x, int y)
{
    //counter variable i.e. return value
    int c = 0;

    TileNode* curr = front;

    //traversing the list till the node is found
    while (curr!= nullptr)
    {
        if (curr->contains(x, y))
        {
            //increasing the counter
            c++;
            curr = curr->next;

            //removing the node
            TileNode* temp = remove(x,y);

            //deleting it
            delete temp;
        }
        else
        {
           curr = curr->next;
        }
    }
    return c;
}

//clearing the entire screen
void TileList::clear()
{
    //traversing the list
    TileNode* curr = front;
    while (curr != nullptr)
    {
        //finding the x and y values of the current node
        int x = curr->x;
        int y = curr->y;

        //changing the traversing variable's position
        curr = curr->next;

        //deleting the node now
        TileNode* temp = remove (x, y);
        delete temp;
    }
}
