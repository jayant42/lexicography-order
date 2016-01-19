#include "LexcoSorting.h"


void LexcoSorting::AddVertex(char c_temp)
{
    VertexProperty v1 ;
    v1.c_literal = c_temp;
  //Vertex vtemp = boost::add_vertex(c_temp,g);
  boost::add_vertex(c_temp,v1,g);
  //g[boost::add_vertex(c_temp,g)].c_literal = c_temp;
}

void LexcoSorting::AddEdge(char sFirst,char sSecond)
{
    boost::add_edge_by_label(sFirst, sSecond, g);
}

void LexcoSorting::PrintOutPut()
{
    Vcontainer c;
    Vcontainer::iterator ii;

    topological_sort(g.graph(), std::back_inserter(c));

    std::cout << "A topological ordering: ";
    for ( ii=c.begin(); ii!=c.end(); ++ii)
    {
        //cout << *ii << " ";
        //cout << *ii << " ";
        cout << g.graph()[*ii].c_literal << " ";
    }

}

string LexcoSorting:: Compare(string sPrevious,string sCurrent)
{
    string op;
    int cnt=0,i=0;
    while(sPrevious[i] !='\0' || sCurrent[i] !='\0')
    {
        if(sPrevious[i] == sCurrent[i]) {
                cnt = 1;
        }
        else {
            break;
        }
        i++;
     }
     if(cnt > 0) {
        op[0] = sPrevious[i];
        op[1] = sCurrent[i];
        op[3] = '\0';
    }
    return op;

}

void LexcoSorting::Execute(string sInputFile)
{
    /* //For Testing
    AddVertex('a');
    AddVertex('b');
    AddVertex('c');
    AddVertex('d');

    AddEdge('a','b');
    AddEdge('d','c');
    AddEdge('b','c');
    //AddEdge('a','b',*g);
    PrintOutPut();*/

    std::ifstream infile(sInputFile);
    std::string strcurrent,strprevious,strCompare;


    while (std::getline(infile, strcurrent))
    {
        if(!strcurrent.empty())
        {

          if(strprevious.empty())
          {
                for(char& c : strcurrent) {
                    AddVertex(c);
                }
          }
          else
          {
                strCompare = Compare(strprevious,strcurrent);
                if(!strCompare.empty())
                {
                    AddEdge(strCompare[0],strCompare[1]);
                }
                AddVertex(strCompare[0]);
                AddVertex(strCompare[1]);

          }
          strprevious = strcurrent;
          //cout << strcurrent;
          //file_contents.push_back('\n');
        }
    }
    PrintOutPut();

}






