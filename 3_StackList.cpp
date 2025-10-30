#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

class StackList {
private:
    SNode* head;
public:
    StackList() : head(nullptr) {}
    ~StackList() {
        SNode* current = head;
        while (current != nullptr) {
            SNode* next_node = current->next;
            delete current;
            current = next_node;
        }
    }
    void push(int val) {
        SNode* newNode = new SNode(val);
        newNode->next = head;
        head = newNode;
    }
    void pop() {
        if (head == nullptr) { cout << "Underflow\n"; return; }
        SNode* temp = head;
        head = head->next;
        delete temp;
    }
    void print() const {
        SNode* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    StackList s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.print();
    s.pop();
    s.print();
    return 0;
}
