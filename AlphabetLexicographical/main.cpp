#include <iostream>
#include "LexcoSorting.h"
#include <exception>

using namespace std;


//property<vertex_name_t, std::string> > VertexProperty;

int main()
{

    try
    {
        LexcoSorting l;
        cout << "Enter File Path and Name" << endl ;
        char cfilename[200];
        cin.getline(cfilename,sizeof(cfilename));
        cout << "File Name : " << cfilename << endl;
        l.Execute(cfilename);
        getchar();
                  //"C:\\Users\\Jayant Kumar\\Documents\\alphabet.txt");
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
