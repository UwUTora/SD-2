#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// TODO : Insert di Depan
void insertFirst(int n) {
    Node* newNode = new Node();

    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// TODO : Insert di belakang
void insertLast(int n) {
    Node *newNode = new Node();
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }

}

// TODO : Insert setelah nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "Linked list kosong, insert di depan dulu\n";
        return;
    }

    Node *newNode = new Node();
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head;
    while (p != NULL && p -> value != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " Tidak ada \n";
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List nya kosong \n";
        return;
    }
    Node *temp = head;
    head = head -> next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List nya kosong \n";
        return;
    }

    if(head -> value == value) {
        deleteFirst();
        return;
    }

    Node *p = head;
    while (p -> next != NULL && p -> next -> value != value) {
        p = p -> next;
    }
    if (p -> next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ada \n";
    } else {
        Node *temp = p -> next;
        p -> next = temp -> next;
        if (temp == tail) tail = p;
        delete temp;
    }
}

// Cetak linked list
void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";

    getchar();
}

int main () {
    int pilihan;
        do {
        cout << "===MENU SINGLE LINKED LIST===\n";
        cout << "0. Keluar\n";
        cout << "1. Tambah di Depan\n";
        cout << "2. Tambah di Belakang\n";
        cout << "3. Tambah Setelah Nilai Tertentu\n";
        cout << "4. Hapus Berdasarkan Nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 0:
                return 0;
            case 1: {
                int n;
                cout << "Masukkan nilai untuk ditambahkan di depan: ";
                cin >> n;
                insertFirst(n);
                break;
            }
            case 2: {
                int n;
                cout << "Masukkan nilai untuk ditambahkan di belakang: ";
                cin >> n;
                insertLast(n);
                break;
            }
            case 3: {
                int n, check;
                cout << "Masukkan nilai untuk ditambahkan: ";
                cin >> n;
                cout << "Masukkan nilai setelah mana node akan ditambahkan: ";
                cin >> check;
                insertAfter(n, check);
                break;
            }
            case 4: {
                int value;
                cout << "Masukkan nilai node yang ingin dihapus: ";
                cin >> value;
                deleteMiddle(value);
                break;
            }
            case 5:
                printList();
                getchar();
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";

        }
    } while (pilihan != 0);

    return 0;
}