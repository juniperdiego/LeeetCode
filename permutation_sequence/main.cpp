#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void printVector(vector<int> array );


class Solution {
        vector<bool> m_avaliable;
        int m_k;
        int m_cnt;
        vector<int> m_array;
    public:
        string m_str;

        void dfs_permutation(int size, int dep)
        {
            if(dep == size)
            {
                m_cnt ++;
                if(m_cnt == m_k)
                {
                    for(int i = 0; i < size; i++)
                    {
                        m_str += m_array[i] + '1';
                    }
                    return;
                }
            }

            //dfs to the next level
            // every level has size choices, its time complexity is O(n^n)
            for(int i = 0; i < size; i++)
            {
                if( m_avaliable[i] == true)
                {
                    //cout <<"dep = " <<dep <<endl;
                    //cout <<"i   = " <<i <<endl;
                    m_array[dep] = i;
                    m_avaliable[i] = false;
                    dfs_permutation( size, dep+1);
                    m_avaliable[i] = true;
                }

            }



        }
        string getPermutation(int n, int k) 
        {
            //initinalize the member variable
            m_avaliable.resize(n, true);
            m_array.resize(n);
            m_k = k;
            m_cnt = 0;
            m_str.clear();

            //call dfs
            dfs_permutation(n, 0);
            
            // return 
            return m_str;
        }

        string getPermutation2(int n, int k) 
        {
            k--;

            string s;
            vector<int> container;
            vector<int> res;

            for(int i = 1; i <=n; i++)
            {
                container.push_back(i);
            }
            //printVector(container);

            for(int i = n-1; i >=0; i--)
            {
                int index = k/calcFactorial(i);
                int value =  container[index];
                res.push_back(value);


                vector<int>::iterator findit = find(container.begin(),container.end(),value);
                container.erase(findit);
                k = k%calcFactorial(i);
#if 0
                cout << "===================================" <<endl;
                cout << "i =\t" << i <<endl;
                cout << "index =\t" << index <<endl;
                printVector(container);
                printVector(res);
                cout << "===================================" <<endl;
#endif
            }
            //printVector(res);

            for(int i = 0; i <res.size(); i++)
            {
                s += res[i] + '0';
            }
            return s;
        }

        int calcFactorial(int n)
        {
            if(n == 0 || n == 1)
                return 1;
            int sum = 1;
            for(int i = 2; i <= n; i++)
                sum *= i;
            return sum;
        }
            

};



void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

void printVector(vector<int> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

int main()
{
    int a[] = {5, 6, 7, 8, 4, 3, 2, 1};
    //int a[] = {5, 6, 7, 8};//, 4, 3, 2, 1};
    vector<int> b ;
#if 0
    b.push_back(5);
    b.push_back(6);
    b.push_back(7);
    b.push_back(8);
#else
    b.push_back(4);
    b.push_back(3);
    b.push_back(2);
    b.push_back(1);
    b.push_back(0);
#endif


    Solution sl;
    string  str; 

#if 0
    for(int i = 0 ; i < 100; i++)
    {
        str= sl.getPermutation(5 , i); 
        cout << i << "\t" << str << endl;
    }
#endif
    
    str= sl.getPermutation(8 ,31492); 
    cout <<"1\t"<< 31492 << "\t" << str <<"xx"<< endl;
    str = sl.getPermutation2(8 ,31492); 
    cout <<"2\t"<< 31492 << "\t" << str <<"yy"<< endl;

    return 0;
}
