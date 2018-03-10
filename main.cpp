#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
class o1strings{
  public :
        int k;
        static int testcase;
        char value;
        string str = "0";
        string rev_str;
        void buildstring(){
        for(  long long i=1;i<22;i++){
          rev_str ="";
          for(long long j=str.length()-1;j>=0;j--){
            rev_str += str[j];
          }
          for(long long k=0;k<rev_str.length();k++){
          if(rev_str[k] == '0'){
                    rev_str[k] = '1';
            }
          else{
                    rev_str[k] = '0';
                }
         }
            str.push_back('0');
            str.append(rev_str);
        }
      }
        void getdetails(string temp_line){
        //cin>>k;
        int k = atoi(temp_line.c_str());
        if(k > pow(10,5) || k < 1){exit(0);}
        int find_pos = k-1;
        //cout<<"find pos"<<find_pos<<endl;
        for(int i=0;i<str.length();i++){
                if(i == find_pos)
                   value = str[find_pos];
        }
       // cout<<"Case #"<<o1strings::testcase<<" : ";
        //cout<<value<<endl;
        }

};
int o1strings::testcase=0;
int main()
{
    ofstream outfile;
    ifstream infile;
    string line;
    infile.open("A-large.in");
    outfile.open("outputfile.txt");
    getline(infile,line);

    int tests = atoi(line.c_str());
    vector<o1strings> objects;
    //cin>>tests;
    if(tests >100 || tests < 1){return 0;}
    objects.resize(tests);
    for(int i=0;i<objects.size();i++){
        o1strings::testcase += 1;
        objects[i].buildstring();
        string temp_line;
        getline(infile,temp_line);
        objects[i].getdetails(temp_line);
    }
    for(int i=0;i<objects.size();i++){
        cout<<"Case #"<<i+1<<": ";
        cout<<objects[i].value<<endl;
        outfile<<"Case #"<<i+1<<": ";
        outfile<<objects[i].value<<'\n';
    }
    return 0;
}

//Comments 
//some more comments