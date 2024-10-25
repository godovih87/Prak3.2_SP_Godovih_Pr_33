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
    Node* head;
    Node* tail;
    int foodx, foody;
    int length;

    Snake(int start_x, int start_y) {
        head = new Node(start_x, start_y);
        tail = head;
        length = 1;
        create_food(20, 10);
    }

    void create_food(int max_x, int max_y) {
        foodx = rand() % max_x;
        foody = rand() % max_y;
    }

    void draw_game(int max_x, int max_y) {
        system("cls");

        for (int x = 0; x < max_x + 2; x++) std::cout << "#";
        std::cout << std::endl;

        for (int y = 0; y < max_y; y++) {
            std::cout << "#";
            for (int x = 0; x < max_x; x++) {
                if (is_snake(x, y)) {
                    std::cout << "O";
                }
                else if (x == foodx && y == foody) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << "#" << std::endl;
        }

        for (int x = 0; x < max_x + 2; x++) std::cout << "#";
        std::cout << std::endl;
    }

    bool is_snake(int x, int y) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->x == x && temp->y == y) return true;
            temp = temp->next;
        }
        return false;
    }

    void move(char direction, int max_x, int max_y) {
        int new_x = head->x;
        int new_y = head->y;

        if (direction == 'w') new_y--;
        else if (direction == 's') new_y++;
        else if (direction == 'a') new_x--;
        else if (direction == 'd') new_x++;
        else return;

        if (new_x < 0 || new_x >= max_x || new_y < 0 || new_y >= max_y) {
            std::cout << "Game Over!" << std::endl;
            exit(0);
        }

        Node* new_head = new Node(new_x, new_y);
        new_head->next = head;
        head = new_head;

        if (new_x == foodx && new_y == foody) {
            create_food(max_x, max_y);
            length++;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }
};

int main() {
    int max_x = 20;
    int max_y = 10;
    Snake snake(max_x / 2, max_y / 2);
    char direction = 'd';

    while (true) {
        if (_kbhit()) {
            char new_direction = _getch();
            if (new_direction == 'w' || new_direction == 'a' || new_direction == 's' || new_direction == 'd') {
                direction = new_direction;
            }
        }

        snake.move(direction, max_x, max_y);
        snake.draw_game(max_x, max_y);
        Sleep(200);
    }

    return 0;
}