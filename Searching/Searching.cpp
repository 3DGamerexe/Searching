// Searching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* Homework #6, Aaliyah Madison */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int N = 9;

class Graph {

public:

    void addEdge(char src, char dest) {
        int srcIndex = src - 'A';
        int destIndex = dest - 'A';
        adjList[srcIndex].push_back(destIndex);
    }

    void printGraph() {
        for (int i = 0; i < N; i++) {
            std::cout << "Vertex " << char('A' + i) << " : ";
            for (char adj : adjList[i]) {
                std::cout << (char)('A' + adj) << " ";
            }
            std::cout << endl;
        }

    }

private:
    vector<char> adjList[N];
};


void Menu() {
    //created directed graph
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

    G.printGraph();

    std::cout << endl;
    std::cout << std::setw(25) << "M E N U" << endl;
    std::cout << "Depth-First Search (0), Minimum Path Search (1)" << endl;
    std::cout << "Exit Program(2)" << endl << endl;
}


int main()
{
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
                cout << "Working" << endl;
                break;
            }
        }

        if (menuValue == 2) {
            std::cout << "Thank you! Have a nice day!" << endl;
        }
    } while (menuValue != 2);
}
