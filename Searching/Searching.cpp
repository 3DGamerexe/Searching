/* Homework #6, Aaliyah Madison */

#include <iostream>
#include <iomanip>
#include <vector>
//#include <stack>
#include <unordered_map>
using namespace std;

const int N = 9;
//node class for the stack implementation
class Node {

public:
    class Stack;

    Node() {
        next = 0;
    }
    Node(char i, Node* in = nullptr) {
        info = i;
        next = in;
    }
    char info;
    Node* next;
};

//stack functions
class Node::Stack {
public:
    Node* top = nullptr;
    Node* tmp = nullptr;

    //pushes to the top of the stack
    void push(char value) {
        Node* tmp = new Node(value);
        tmp->next = top;
        top = tmp;
    }

    //removes from the top of the stack
    void pop() {
        if (top == nullptr) {
            return;
        }
        Node* tmp = top;
        top = top->next;
        delete tmp;
        /*while (tmp->next != top) {
            tmp = tmp->next;
        }
        delete top;
        top = tmp;
        top->next = nullptr;*/
    }

    bool empty() const {
        return top == nullptr;
    }

    //prints the Stack
    void print() {
        while (top != nullptr) {
            std::cout << top->info << " ";
            top = top->next;
        }
    }
};

class Graph {

public:
    
    //creates the directed graph edges
    void addEdge(char src, char dest) {
        adjList[src].push_back(dest);
    }


    void DFS(char start) {
        std:unordered_map<char, bool> visited;
        Node::Stack stack; 

        stack.push(start);
        visited[start] = true;

        while (!stack.empty()) {
            char currentNode = stack.top->info;
            stack.pop();
            std::cout << currentNode << " ";

            for (char adj : adjList[currentNode]) {
                if (!visited[adj]) {
                    stack.push(adj);
                    visited[adj] = true;
                }
            }
        }

        
    }

private:
    //adjacency list
    vector<char> adjList[N];
};



void Menu() {
    std::cout << endl;
    std::cout << std::setw(25) << "M E N U" << endl;
    std::cout << "Depth-First Search (0), Minimum Path Search (1)" << endl;
    std::cout << "Exit Program(2)" << endl << endl;
}

int main()
{
    //create directed graph
    Graph G;
    G.addEdge('A', 'B');
    G.addEdge('A', 'C');
    G.addEdge('A', 'D');
    G.addEdge('B', 'E');
    G.addEdge('C', 'B');
    G.addEdge('C', 'G');
    G.addEdge('D', 'C');
    G.addEdge('D', 'G');
    G.addEdge('E', 'C');
    G.addEdge('E', 'F');
    G.addEdge('F', 'C');
    G.addEdge('F', 'H');
    G.addEdge('G', 'F');
    G.addEdge('G', 'H');
    G.addEdge('G', 'I');
    G.addEdge('H', 'E');
    G.addEdge('H', 'I');
    G.addEdge('I', 'F');

    //G.printGraph();

    int menuValue;

    do {
        Menu();
        std::cout << std::setw(20) << "Choose? ";
        std::cin >> menuValue;

        if (menuValue > 2 || menuValue < 0 || cin.fail()) {
            std::cout << endl;
            std::cout << "Invalid. Enter a number from the menu provided." << endl;
        }

        else {
            switch (menuValue) {
            case 0:
                char value;
                std::cin >> value;
                G.DFS(value);
                break;
            }
        }

        if (menuValue == 2) {
            std::cout << "Thank you! Have a nice day!" << endl;
        }
    } while (menuValue != 2);
}
