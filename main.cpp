#include <iostream>

using namespace std;

typedef string Elem;
class CNode
{
private:
    Elem elem;
    CNode* next;
    friend class CircleList;
};

class CircleList
{
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem& e);
    void remove();

private:
    CNode* cursor;
};
CircleList::CircleList()
    : cursor{nullptr}
{
}

CircleList::~CircleList()
{
    while (!empty())
        remove();
}

bool CircleList::empty() const
{
    return cursor == nullptr;
}

const Elem& CircleList::front() const
{
    return cursor->next->elem;
}

const Elem& CircleList::back() const
{
    return cursor->elem;
}

void CircleList::advance()
{
    cursor = cursor->next;
}

void CircleList::add(const Elem& e)
{
    if (cursor != nullptr)
    {
        CNode* temp{new CNode()};
        temp->elem = e;
        temp->next = cursor->next;
        cursor->next = temp;
    }
    else
    {
        cursor = new CNode();
        cursor->elem = e;
        cursor->next = cursor;
    }
}

void CircleList::remove()
{
    if (cursor != nullptr)
    {
        cursor->next = cursor->next->next;
        delete cursor->next;
        cursor->next = nullptr;
    }
}
int main()
{
    return 0;
}

