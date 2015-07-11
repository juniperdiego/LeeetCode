#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

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

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

class MinStack {
    private:
        vector<int> m_data;
        vector<int> m_min;
    public:
        void push(int x) {
            if(m_data.size() == 0)
                m_min.push_back(x);
            else
            {
                if(m_min[m_min.size() - 1] > x)
                    m_min.push_back(x);
                    m_min.push_back(m_min[m_min.size() - 1]);
            }
            m_data.push_back(x);
        }

        void pop() {
            m_data.pop_back();
            m_min.pop_back();
        }

        int top() {
            int size = m_data.size();
            if(size > 0)
                return m_data[size - 1];
            else
                return -1;
        }

        int getMin() {
            int size = m_min.size();
            if(size > 0)
                return m_min[size - 1];
            else
                return -1;

        }
};


int main()
{



    return 0;
}
