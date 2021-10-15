//C style string better way
// #include<iostream>
// using namespace std;

// int main()
// {
//     char str[10] = "gfg"; //Declaring ths way compiler will put \0 at the end on its own 
//     cout << str<<"  ";
//     cout<<sizeof(str);
//     return 0;
// }



//C style bad way / Naive way
// #include<iostream>
// using namespace std;

// int main()
// {
//     char str[4] = {'g', 'f', 'g'};

//     char str2[] = {'g', 'f', 'g', '\0'};

//     cout << str<<endl;

//     cout<<str2;
//     return 0;
// }


//C style string functions
#include<bits/stdc++.h>
#include <cstring>
using namespace std;

int main()
{
    // char s1[] = "bcda";
    // char s2[] = "bcd";
    // int res = strcmp(s1, s2);
    // if (res > 0)
    //     cout << "Greater";
    // else if(res == 0)
    //     cout << "Same";
    // else
    //     cout << "Smaller";

    // char str2[5];
    // strcpy(str2, "gfg");
    // cout <<"    " <<str2<<" ";

    //C  style string as a an array of cahr based  it will not give desired/ proper output

    char s2[] = "bbc";

    char s1[] = "aba";
    if (s1 == s2)
        cout << "Same";
    else if(s1 < s2)
        cout << "Smaller";
    else
        cout << "Greater";

    //C++ class based implementation
    string str = "geeksforgeeks";
    cout <<"    " <<str.length() << " ";
    str = str + "xyz";
    cout << str << " ";
    cout << str.substr(1, 3) << " ";
    cout << str.find("for") << " ";

    string str3;
    cout << "Enter your name    ";
    getline(cin , str3 ,',');  //It deaults to take until enter is pressed or till this char is encountered 
    cout << "\nYour name is " << str3;

    string str4 = str3;
    for (int i = 0; i < str4.length(); i++)
        cout << str4[i];
    cout << endl;
    for (auto x: str4)
        cout << x;

    return 0;

}