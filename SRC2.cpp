#define NUM 30
//#include "list.h"
#include "iostream"

void instructions();
void testlist(List);

void instructions()
{
      cout<<"********\nCommands"<<endl;
      cout<<"********\n\n";
      cout<<"i - insert text at line <num>"<<endl;
      cout<<"w - overwrite text at line <num>"<<endl
            <<"d - delete text at line<num>"<<endl
            <<"e - edit text at line <num>"<<endl
            <<"s - change document title"<<endl
            <<"q - quit text editor"<<endl
            <<"Press c to continue ";
      char c;
      cin>>c;
}

void testlist(List e)
{
      e.display();
      char op;
      int choice;

      do{
            cout<<"?";
            cin>>op;

            switch(op){
                  case 'i':
                        int r;
                        cout<<"Enter line for text to be entered into--> ";            
                        cin>>r;
                        cin.ignore();
                        cout<<"Enter text to be entered"<<endl;
                        char strin[SIZE];
                        cin.getline(strin, SIZE);
                                cout<<flush;
                        e.insert(strin,r);
                        system("clear");
                        e.display();
                        break;
                  case 'd':
                        char k[SIZE];
                        cout<<"Enter text to be deleted--> ";
                        cin.getline(k,SIZE);
                                cout<<flush;
                        e.del(k);
                        system("clear");
                        e.display();
                        break;
                  case 'e':
                        break;
                  case 'w':
                        int t;
                        cout<<"Enter line for text to be entered--> ";
                        cin>>t;
                        cout<<"Enter text to be entered"<<endl;
                        char p[SIZE];
                        cin>>p;
                        system("clear");
                        e.display();
                        break;
                  case 's':
                        char a[NUM];
                        cout<<"Enter title--> ";
                        cin.getline(a, NUM);
                                cout<<flush;
                        e.settitle(a);
                        system("clear");
                        e.display();
                        break;
                  case '*':
                                system("clear");
                        instructions();
                        system("clear");
                        e.display();
                        break;
                  default:
                        break;

            }
      }
      while(op !='q') ;      
            cout<<"Goodbye";
      }



int main()
{
      List e;
      testlist(e);
      return 0;
}

Node Class

#define LEN 40
#include "string.h"

class Node                  //Node class for linked list of lines(character arrays)
{
private:
    char element[LEN];
    Node *next;
      Node *previous;
public:
    Node();
      Node(char *);
    char *getelement();
    void setelement(char *);
    Node *getnext() const;
    void setnext(Node *);
      Node *getprevious() const;
      void setprevious(Node *);
 };  

Node::Node(char *f)
:next(NULL),
previous(NULL)
{
      strcpy(element, f);
}

Node::Node()
:next(NULL),
 previous(NULL)
{
      int i;
      element[LEN] = ' ';
}

char* Node::getelement()  
{
    return element;
}

void Node::setelement(char *f)
{
    strcpy(element, f);
}

Node * Node::getnext() const
{
    return next;
}

void Node::setnext(Node *n)
{
    next = n;
}

Node *Node::getprevious() const
{
      return previous;
}

void Node::setprevious(Node *n)
{
      previous = n;
}




List Class

#include "string.h"
#include "iostream"
//#include "node.h"
#include "stdlib.h"
#define NUM 30
#define SIZE 80

class List:public Node                  //Linked List of lines
{
      
      private:
          Node *first;
            int no_of_lines;            //keeps check of # of lines in document
            char title[NUM];
      public:
            List();
          void settitle(char *);
            char * gettitle();
            bool empty();
          int length();
          void insert(char *, int);
               void del(char *);
            void display();
            void traverse(char *(*op)(char *));
};

List::List()
:first(NULL),
 no_of_lines(0)
{
      Node::Node();
      int i;
      title[SIZE] = ' ';
}

void List::settitle(char *f)
{
      strcpy(title,f);
}

char *List::gettitle()
{
      return title;
}

bool List::empty()
{
    return (first == NULL) ? true: false;
}

int List::length()
{
    int i = 0;
    Node *n = first;

   
    while(n != NULL)
    {
        i++;
        n = n->getnext();
    }

    return i;
}


void List::insert(char *e, int pos)
{
    int i = 0;
    Node *n = new Node(e);

    if (pos == 0)
    {
        n->setnext(first);

        if (first != NULL)
            first->setprevious(n);

        first = n;
    }
    else
    {
        Node *temp = first;
        int i = 0;

        while(i < (pos - 1) && temp->getnext() != NULL)
        {
            i++;
            temp = temp->getnext();
        }

        if (i != (pos - 1))
            cout << "Error. Illegal position." << endl;
        else
        {
            n->setnext(temp->getnext());
            temp->setnext(n);
            n->setprevious(temp);

            if (n->getnext() != NULL)
                n->getnext()->setprevious(n);

        }
    }
}

void List::del(char *e)
{
    int i = 0;
    Node *n = first;

   
    if (n->getelement() == e)
    {
        first = n->getnext();
   
        if (first != NULL)
            first->setprevious(NULL);

        delete(n);
    }
    else
    {
         while(n != NULL)
            if (n->getelement() == e)
                break;
            else
                n = n->getnext();

        if (n == NULL)
            cout << "Error. Element not in list." << endl;
        else
        {
           n->getprevious()->setnext(n->getnext());
            if (n->getnext() != NULL)
                n->getnext()->setprevious(n->getprevious());

            delete(n);
        }
    }
}

void List::display()            
{
      int i,j;
      cout<<"\t\t\tTitle : "<<title<<endl;
      for(i=0;i<80;i++) cout<<"*";
      cout<<endl<<endl;
      for(j=1;j<SIZE;j++){
            cout<<getelement()<<endl;
      cout<<endl;
      }

      for(i=0;i<80;i++) cout<<"*";
      cout<<endl<<endl<<"Number of lines: "<<no_of_lines<<endl;
      cout<<"Enter * to see the instructions"<<endl;
}
