#include <iostream>
#include "MyList.h";
#include "Menu.h";
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    Menu menu;
    menu.testBigO();
}
