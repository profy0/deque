#include <iostream>
#include <exception>
#include "deq.h"

using namespace std;

int main() {
    deque <int> q;
    int n;
    cout << "Enter the number of elements(for int): ";
    cin >> n;
    cout << "Now push_front and pop_back\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter element(for int): ";
        int x;
        cin >> x;
        q.push_front(x);
    }
    cout << "getCount(number of elements) - " << q.getCount() << "\n";
    q.print();
    for (int i = 0; i < n; i++) { // If you put n+1 there will be an exception 
        try {
            q.pop_back();
        }
        catch (exception t) {
            cerr << t.what();
            return 0;
        }
        
        q.print();
    }

    deque <double> q2;

    cout << "Enter the number of elements(for double): ";
    cin >> n;
    cout << "Now push_back and pop_front\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter element(for double): ";
        double x;
        cin >> x;
        q2.push_back(x);     
    }
    cout << "getCount(number of elements) - " << q2.getCount() << "\n";
    q2.print();
    for (int i = 0; i < n; i++) {
        try {
            q2.pop_front();
        }
        catch (exception t) {
            cerr << t.what();
            return 0;
        }
        q2.print();
    }

    
    deque <char*> q3;

    cout << "Enter the number of elements(for char*): ";
    cin >> n;
    cout << "Now push_back and pop_back\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter element(for char*): ";
        char* x = new char;
        cin >> x;
        q3.push_back(x);
    }
    cout << "getCount(number of elements) - " << q3.getCount() << "\n";
    q3.print();
    for (int i = 0; i < n; i++) {
        try {
            q3.pop_back();
        }
        catch (exception t) {
            cerr << t.what();
            return 0;
        }
        q3.print();
    }

}
