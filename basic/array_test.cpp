#include <iostream>

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << sizeof(arr)/sizeof(arr[0]) << std::endl;
    return 0;
}
