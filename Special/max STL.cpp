#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    int x [] = {2, 7, 92, 81, 19, 72, 23};

    unsigned int array_length = sizeof (x) / sizeof (int);

    cout << "Maximum : " << *max_element (x, x + array_length) << endl;

    vector <char> v;

    v.push_back ('k');
    v.push_back ('f');
    v.push_back ('g');
    v.push_back ('b');

    cout << "Minimum : " << *min_element ( v.begin (), v.end () ) << endl;

    return 0;
}

/* output
Maximum : 92
Minimum : b

Process returned 0 (0x0)
execution time : 0.078 s
Press any key to continue.
*/

