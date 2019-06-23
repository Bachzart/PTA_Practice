#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num, tens, hundred, unit;
    cin >> num;
    hundred = num / 100;
    tens = num / 10 % 10;
    unit = num % 10;
    num = unit*100 + tens*10 + hundred;
    cout << num << endl;
    return 0;
}

