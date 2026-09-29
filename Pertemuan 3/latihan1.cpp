#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if (top == MAX - 1) {
        cout << "Stack Penuh! \n";
    } else {
        top++;
        stack[top] = value;
    }
}

// TODO : Mengambil karakter paling atas
char pop() {
    if (top == -1) {
        cout << "stack kosong !\n"; 
    } else {
        cout << stack[top];
        top--;
    }

    return '\0';
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack
    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    // TODO Mengeluarkan karakter dari stack
    for (int i = 0; i < kata.length(); i++) {
        cout << pop();
    }
    
    cout << endl;

    return 0;
}