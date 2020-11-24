#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b, c;
    float root1, root2;

    cin >> a >> b >> c;
    root1 = ((-1*b) - sqrt(b - 4*a*c))/2*a;
    cout << root1;
}