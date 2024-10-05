// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <conio.h>
#include <windows.h>

struct Node {
    int x, y;
    Node* next;
    Node(int _x, int _y) : x(_x), y(_y), next(nullptr) {}
};

class Snake {
public:
    Snake(int start_x, int start_y) {
        Node* head = new Node(start_x, start_y);
        Node* tail = head;
        int length;
        length = 1;
    }
    int foodx, foody;

    void create_food(int max_x, int max_y){
        /*foodx = rand() % 20
        foody = rand() % 10*/
    }

    void draw_game(int max_x, int max_y) {
        system("cls");

        for (int x = 0; x < max_x + 2; x++) {
            std::cout << "#";
        }
        std::cout << std::endl;

        for (int y = 0; y < max_y; y++) {
            std::cout << "#";
            for (int x = 0; x < max_x; x++) {
                std::cout << " ";
            }
            std::cout << "#" << std::endl;
        }

        for (int x = 0; x < max_x + 2; x++) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
};

int main() {
    int max_x = 20;
    int max_y = 10;
    Snake snake(max_x / 2, max_y / 2);
    while (true) {
        snake.draw_game(max_x, max_y);
        Sleep(100);
    }
    return 0;
}