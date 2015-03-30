#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;
bool isMatrix(queue<int> m, int r)
{
    if(m.size() % r == 0)
        return true;
        std::cout << "Invalid Matrix provided by files.";
        return false;
}
void makeArr(queue<int> m, int r, int arr[])
{
    int size=m.size();
    for(int i=0; i<size; i++, m.pop())
    {
        arr[i]=m.front();
        if(i%(size/r)==0)
            std::cout<< std::endl;
        std::cout<< arr[i]<< " ";
    }
    std::cout<< "\n";
}
void makeSum(int arr1[], int arr2[], int r1, int r2, int size1, int size2)
{
    if((size1 != size2)or(r1 != r2))
    {
        std::cout<<"Matrix size does not match, can not compute sum.\n";
        return;
    }
    int arr[size1];
    std::cout<< "Sum of matrices:";
    for(int i=0; i<size1; i++)
    {
        if(i%(size1/r1)==0)
            std::cout << std::endl;
        arr[i]=arr1[i]+arr2[i];
        std::cout<< arr[i]<< " ";
    }
    std::cout<< std::endl;
}
void makeTran(int arr[], int r, int size)
{
    std::cout<< "Transpose of Matrix:\n";
    int var[size];
    for(int j=0; j<size/r; j++)
        for(int i=0; i<r; i++)
        {
            if(i%r==0)
                std::cout<< std::endl;
            var[j*r + i]=arr[j+ i*(size/r)];
            std::cout<< var[j*r + i]<< " ";
        }
    std::cout<< std::endl;
}
void makeMult(int arr1[], int arr2[], int r1, int r2, int size1, int size2)
{
    if(r2 == size1/r1)
    {
        std::cout<< "Matrices are first times second compatible:\n";
        int arr[r1*size2/r2];
    for(int a=0;a<r1;a++)
    {
        int sum;
       for(int i=0; i<size2/r2; i++)
       {
           sum=0;
            for(int j=0; j<r2; j++)
            {
               sum=sum+arr1[a*r2+j]*arr2[i+(size2/r2)*j];
            }
            arr[size2/r2*a+i]=sum;
       }
    }
    for(int a=0;a<r1*size2/r2;a++)
    {
        if(a%(size2/r2) == 0)
        std::cout<<std::endl;
        std::cout<< arr[a]<< " ";
    }

    std::cout<<std::endl;
        if(r1 == size2/r2)
            {
            std::cout<< "Matrices are second times first compatible:\n";
                    int arr[size1/r1*r2];
            for(int a=0;a<r2;a++)
            {
               for(int i=0; i<size1/r1; i++)
               {
                   int sum=0;
                    for(int j=0; j<r1; j++)
                    {
                       sum=sum+arr2[a*r1+j]*arr1[i+(size1/r1)*j];
                    }
                    arr[size1/r1*a+i]=sum;
                    if((i%r2) == 0)
                        std::cout<< std::endl;
                    std::cout<< arr[size1/r1*a+i]<< " ";
               }
            }
            std::cout<< std::endl;
            }
    }
    else if(r1 == size2/r2)
    {
    std::cout<< "Matrices are second times first compatible:\n";
            int arr[size1/r1*r2];
    for(int a=0;a<r2;a++)
    {
       for(int i=0; i<size1/r1; i++)
       {
           int sum=0;
           for(int j=0; j<r1; j++)
           {
              sum=sum+arr2[a*r1+j]*arr1[i+(size1/r1)*j];
           }
           arr[size1/r1*a+i]=sum;
            if((i%r2) == 0)
                std::cout<< std::endl;
            std::cout<< arr[size1/r1*a+i]<< " ";
       }
    }
    std::cout<<std::endl;
    }
    else
        std::cout<< "The matrices can not be multiplied. Dimension mismatch.\n";
}
std::ifstream m1, m2;
std::queue<int> M1, M2;
std::string val;
int r1, r2, value;
int main()
{
    m1.open("input1.txt");
    if(m1.is_open())
    {
        while(getline(m1, val, ','))
        {
            //getline(m1, val, ',');
            value=stoi(val);
            M1.push(value);
        }
        m1.close();
        m1.open("input1.txt");
        while(getline(m1, val))
        {
            r1++;
        }
    }
    else
        std::cout<< "First input file invalid.";
        if(!isMatrix(M1, r1))
        {
            std::cout << "File 1 error.\n";
            return 0;
        }
    m2.open("input2.txt");
    if(m2.is_open())
    {
        while(m2.good())
        {
            getline(m2, val, ',');
            value=stoi(val);
            M2.push(value);
        }
        m2.close();
        m2.open("input2.txt");
        while(getline(m2, val))
        {
            r2++;
        }
    }

    else
        std::cout<< "Second input file invalid.";
        if(!isMatrix(M2, r2))
        {
            std::cout << "File 2 error.\n";
            return 0;
        }
    int arr1[M1.size()], arr2[M2.size()];
    makeArr(M1, r1, arr1);
    makeArr(M2, r2, arr2);
    makeSum(arr1, arr2, r1, r2, M1.size(), M2.size());
    makeTran(arr1, r1, M1.size());
    makeTran(arr2, r2, M2.size());
    makeMult(arr1, arr2, r1, r2, M1.size(), M2.size());
    return 0;
}
