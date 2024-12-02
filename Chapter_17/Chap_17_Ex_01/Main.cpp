/*
Chap_17_Ex_01
1. Napiste program, ktery bude pocitat znaky ze vstupu az do prvniho
vyskytu znaku $ a tento znak ponecha ve vstupnim toku.
*/

#include <iostream>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char ch;
    int count = 0;

    cout << "Write something:\n";

    while (cin.get(ch) && ch != '$')
        count++;
    if (ch == '$')
        cin.putback(ch);
    else
        cout << "End of input was reached\n";
    cout << count << " characters read\n";
    cin.get(ch);
    cout << "Then next input character is " << ch << endl;
    return 0;
}