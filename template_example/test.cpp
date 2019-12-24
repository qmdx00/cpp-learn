#include <iostream>

using namespace std;

template <typename T>
T add(T x, T y)
{
    return x + y;
}

int main(int argc, char const *argv[])
{
    cout << add(1, 2) << endl;
    cout << add(1.0, 2.3) << endl;
    return 0;
}
