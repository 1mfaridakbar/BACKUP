#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
void gotoxy (int, int);

class ListNode
{
public:
    char c;
    ListNode *next;
};

int main()
{
    ofstream outputFile;
    ListNode *nodePtr;
    ListNode *head;
    ListNode *newNode = new ListNode ();
    head = newNode;
    newNode ->next = nullptr;
    nodePtr = nullptr;
    //Open file
    outputFile.open("input.txt");
    cout << "Please type 'x' and then hit enter when you are done. \n";
	while (newNode->c = getchar())
	{
    //If head is empty, create node
    if (nodePtr == nullptr)
    {
         nodePtr = newNode;
    }
    else //If head is not empty, create new node, set next to the new node
    {
         nodePtr->next = newNode;
         nodePtr = newNode;
    }
    //Key pressed to exit program
    if (nodePtr->c == 'x')
         break;
    newNode = new ListNode();
    newNode->next = nullptr;
	}
	
	//Display linked list
	cout << "Here is what you have typed so far:\n";
	nodePtr - head;
	while (nodePtr != nullptr)
	{
    cout << nodePtr->c;
    nodePtr = nodePtr->next;
	}
	cout << endl;
	//While loop for writing nodes into file
	nodePtr = head;
	while (nodePtr != nullptr)
        
	{
    outputFile << nodePtr->c;
    nodePtr = nodePtr->next;
	}
	outputFile.close();
	system("pause");
	return 0;
}

void gotoxy (int x, int y)
{
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}


