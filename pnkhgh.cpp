#include <iostream>
#include <map>
using namespace std;

char find (char c)
{
    char count[256];
    int len = 0;
    for ( c != 0; ((c >= 'a' && c <= 'z') ; c++ )
    {
    len += count[c];
    }
    return len;
}
int main()
{
    int t;
    while(t--){
    char c;
    int size = 0 ,length;
    cin >> c;
    size = StringLength (c);
    cout << "The total number of characters entered is: " << size << endl;
}
    return 0;
}