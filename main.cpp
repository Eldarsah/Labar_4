#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Queue<int> mc(3);
    mc.print();

    mc.push(14);
    mc.push(4);
    mc.push(2001);
    mc.print();

    Queue<char> mc1(10);
    mc1.push('E');
    mc1.push('l');
    mc1.push('d');
    mc1.push('a');
    mc1.push('r');
    mc1.print();

    mc1.pop(2,'s');
    mc1.print();

    Queue<string> m(3);
    m.push("Chikmobil");
    m.push("AUE");
    m.print();

    return 0;
}
