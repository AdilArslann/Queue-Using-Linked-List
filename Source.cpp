#include <iostream>
#include <stack>
using namespace std;

struct queuenode {
    int data;
    queuenode* link;
    queuenode(int d)
    {
        data = d;
        link = NULL;
    }
};

struct Queue {
    queuenode* frontt, * backk;
    Queue()
    {
        //creates a fresh queue
        frontt = backk = NULL;
    }

    //checks if the queue is empty or not
    bool isEmpty()
    {
        if (frontt == NULL && backk == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int x)
    {

        // Creates a new linked list node
        queuenode* temp = new queuenode(x);
        temp->data = x;
        temp->link = NULL;

        if (frontt == NULL) {
            frontt = backk = temp;
            return;
            /*Checks if the node is empty if so then the new node is both front
            and back until a new node is added to the queue*/
        }
        else
        {
            backk->link = temp;
            backk = temp;
            //Adds a node from the back
        }
    }

    //removing a node from the front
    void dequeue()
    {
        if (isEmpty() == true)
        {
            cout << "There is so nothing in the queue." << endl;
            return;
            //checks if the queue is empty
        }
        else
        {
            frontt = frontt->link; //moves front one node
        }
        if (frontt == NULL)
            backk = NULL;
        /*checks if the front is null(zero) then it makes the back null
        too since the queue is empty*/
    }

    void front()
    {
        if (isEmpty() == true)
        {
            cout << "The queue is empty" << endl;
            return;
        }
        else
        {
            cout << frontt->data << endl;
            //outputs the front node
        }
    }
    void back()
    {
        if (isEmpty() == true)
        {
            cout << "The queue is empty" << endl;
            return;
        }
        else
        {
            cout << backk->data << endl;
            //outputs the back node
        }
    }

    void display()
    {
        if (isEmpty() == true)
        {
            cout << "The Queue is empty" << endl;
            return;
        }
        else
        {
            queuenode* temp = frontt;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << endl;
        }
    }

    void reverse()
    {
        stack<int> temp;
        queuenode* tmp = frontt;
        while (!isEmpty())
        {
            temp.push(tmp->data);
            tmp = tmp->link;
            dequeue();
        }
        while (!temp.empty())
        {
            enqueue(temp.top());
            temp.pop();
        }
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{

    Queue q;
    //testing the queue
    q.front();
    q.back();
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.clear();
    q.display();
    q.enqueue(855);
    q.display();
    q.enqueue(74);
    q.enqueue(41);
    q.enqueue(43);
    q.front();
    q.back();
    if (q.isEmpty() == true)
    {
        cout << " It is empty" << endl;
    }
    else
    {
        cout << "It is not empty" << endl;
    }
    q.display();
    q.reverse();
    q.display();
    q.clear();
    if (q.isEmpty() == true)
    {
        cout << "It is empty" << endl;
    }
    else
    {
        cout << "It is not empty" << endl;
    }
}