#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

void maybe_space() {
    if (rand()%2) {
        cout << " ";
    }
    if (rand()%2) {
        cout << " ";
    }
}

void print_name() {
    cout << (char)(rand()%6 + 'a');
}

void print_name_or_variable() {
    if (rand()%3) {
        print_name();
    } else if (rand()%2) {
        cout << "_";
    } else {
        cout << "_";
        cout << (char)(rand()%4 + 'a');
    }
}
void print_variable() {
    if (rand()%2) {
        cout << "_";
    } else {
        cout << "_";
        cout << (char)(rand()%10 + 'a');
    }
}

void print_thing() {
    maybe_space();
    print_name();
    maybe_space();
    cout << "(";
    maybe_space();
    print_name();
    for (ll i = 0; i < rand()%10; ++i) {
       maybe_space();
       cout << ",";
       maybe_space();
       print_name();
    }
    maybe_space();
    cout << ")";
}

void print_query() {
    maybe_space();
    print_name();
    maybe_space();
    cout << "(";
    maybe_space();
    print_name_or_variable();
    for (ll i = 0; i < rand()%10; ++i) {
       maybe_space();
       cout << ",";
       maybe_space();
       print_name_or_variable();
    }
    maybe_space();
    cout << ")";
}
void print_query2() {
    maybe_space();
    print_name();
    maybe_space();
    cout << "(";
    maybe_space();
    print_variable();
    for (ll i = 0; i < rand()%10; ++i) {
       maybe_space();
       cout << ",";
       maybe_space();
       print_variable();
    }
    maybe_space();
    cout << ")";
}

int main() {
    for (ll i = 0; i < 200; ++i) {
        for (ll j = 0; j <= rand()%10; ++j) {
            print_thing();
        }
        cout << endl;
    }
    cout << endl;
    for (ll i = 0; i < 100; ++i) {
        print_query();
        cout << endl;
    }
    for (ll i = 0; i < 100; ++i) {
        print_query2();
        cout << endl;
    }
}
