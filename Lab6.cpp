#include <fstream>
#include <iostream>
#include <queue>
#include <string>
bool isMatrix(int row, int size)
{
    if(size % row == 0)
        return true;
    std::cout << "One or more of the provided inputs was not a matrix.";
        return false;
}
std::queue<int> mMult(std::queue<int> f, std::queue<int> s, int r1, int r2)
{
    if(f.size()/r1 != r2)
        std::cout <<"Matrix's are not compatible for multiplication.";
    else
    {
        int A[f.size()/r1];
        int B[r2];
        std::queue<int> result;
        for(int k=0; r2; k++)
        {
            for(int i=0; r2; i++)
            {

            }
        }

    }

}
void mAdd(std::queue<int> f, std::queue<int> s, int r1, int r2)
{
    if((r1!=r2) or (f.size()/r1!=s.size()/r2))
        std::cout<< "Matrices are not the same size.";
    else
    {
        std::queue<int> result;
        int j=f.size();
        for(int i=0; i<j;i++)
        {
            result.push(f.front()+s.front());
            f.pop();
            s.pop();
        }
        for(std::queue<int> dump= result; !dump.empty(); dump.pop())
            std::cout<< dump.front()<< std::endl;
    }

}
/*void mtran(std::queue<int> f, std::queue<int> s, int r1, int r2)
{
int arr[f.size()];
int j=f.size();
for(int i=j-1;i!=j;i-r1){
    arr[i]=f.pop();
    if((i-r1<0))
        i=i+j;
}
//for(int i=0; i<)
}*/

std::queue<int> first;
std::queue<int> second;
std::ifstream m1,m2;
int r1, r2, value;
std::string val;
int main()
{
m1.open("input1.txt");
if(m1.is_open())
{
    while(getline (m1,val, ',') )
    {
        value=std::stoi(val);
        first.push(value);
    }
    m1.close();
    m1.open("input1.txt");
    while(getline (m1, val))
        r1++;
    isMatrix(r1, first.size());

}
else
    std::cout<< "Unable to open first file.\n";
m2.open("input1.txt");
if(m2.is_open())
{
    while(getline (m2,val, ',') )
    {

        value=std::stoi(val);
        second.push(value);
    }
    m2.close();
    m2.open("input1.txt");
    while(getline (m2, val))
        r2++;
    isMatrix(r2, second.size());
}
else
    std::cout<< "Unable to open second file.\n";
mAdd(first, second, r1, r2);
//for(std::queue<int> dump= first; !dump.empty(); dump.pop())
   // std::cout<< dump.front();
//for(std::queue<int> dump= second; !dump.empty(); dump.pop())
  //  std::cout<< dump.front();
}
