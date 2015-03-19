#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


void printVector(vector<char> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

void printVector(vector<int> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

class Solution 
{
    public:   
        int largestRectangleArea(vector<int> &height) {

            //add 0 to the end
            height.push_back(0);

            int size = height.size(); //this new_size is 1 + old_size
            stack<int> st;

            int max_area = 0;



            for(int i = 0; i< size; )
            {
                if(st.empty() || height[i] > height[st.top()])
                {
                    st.push(i);
                    i++;
                }
                else
                {
                    //st must be not empty here
                    // i can't ++; handle many times perhaps

                    int idx = st.top();
                    st.pop();

                    int area;

                    if(st.empty())
                    {
                        area = height[idx] * i;
                    }
                    else
                    {
                        area = height[idx] * (i-st.top()-1);
                    }

                    max_area = max(max_area, area);

                }
            }
            return max_area;
        }

        int maximalRectangle(vector<vector<char> > &matrix)
        {
            if(matrix.empty() || matrix[0].empty())
                return 0;
            size_t row = matrix.size();
            size_t col = matrix[0].size();

            vector<int> f;
            f.resize(col, 0);

            int ret = 0;
            for(int i = 0; i < row; i++)
            {
                // update f
                for(int j = 0; j < col; j++)
                {
                    // the first row 
                    if(i == 0)
                    {
                        if(matrix[0][j] == '1')
                            f[j] = 1;
                        else
                            f[j] = 0;
                    }
                    // other rows
                    else
                    {
                        if(matrix[i][j] == '1')
                            f[j] = f[j] + 1;
                        else
                            f[j] = 0;
                    }
                }

                ret = max(ret, largestRectangleArea(f));
            }

            return ret;

        }
        int maximalRectangle3(vector<vector<char> > &matrix) {
            if (matrix.empty())  return 0;

            const int m = matrix.size();
            const int n = matrix[0].size();
            vector < vector<int> > ll;
            vector < vector<int> > rr;
            vector < vector<int> > hh;

            vector<int> H(n, 0);
            vector<int> L(n, 0);
            vector<int> R(n, n);

            int ret = 0;
            for (int i = 0; i < m; ++i) {
                int left = 0, right = n;
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        ++H[j];
                        L[j] = max(L[j], left);
                    } else {
                        left = j+1;
                        H[j] = 0;
                        L[j] = 0; 
                        R[j] = n;
                    }
                }
                ll.push_back(L);
                hh.push_back(H);
                for (int j = n-1; j >= 0; --j) {
                    if (matrix[i][j] == '1') {
                        R[j] = min(R[j], right);
                        ret = max(ret, H[j]*(R[j]-L[j]));
                        // cout<<ret<<endl;
                    } else {
                        right = j;
                    }
                }
                rr.push_back(R);
            }
#if 1
            cout << "maxtrix" <<endl;
            for (int i = 0; i < m; ++i) {
                printVector(matrix[i]);
            }
            cout <<endl;
            cout << "ll" <<endl;
            for (int i = 0; i < m; ++i) {
                printVector(ll[i]);
            }
            cout <<endl;
            cout << "rr" <<endl;
            for (int i = 0; i < m; ++i) {
                printVector(rr[i]);
            }
            cout <<endl;
            cout << "hh" <<endl;
            for (int i = 0; i < m; ++i) {
                printVector(hh[i]);
            }
            cout <<endl;
#endif
            return ret;
        }

        int maximalRectangle4(vector<vector<char> > &matrix) {
            int m = matrix.size();
            if (!m) return 0;
            int n = matrix[0].size();
            if (!n) return 0;

            int h[n], l[n], r[n];
            for (int i = 0; i < n; ++i) {
                h[i] = l[i] = r[i] = 0;
            }

            int max_area = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        h[j] += 1;
                    } else {
                        h[j] = 0;
                    }
                }

                for (int j = 0; j < n; ++j) {
                    l[j] = j;
                    while (l[j] >= 1 && h[l[j] - 1] >= h[j])
                        l[j] = l[j] - 1;
                }

                for (int j = n - 1; j >= 0; --j) {
                    r[j] = j;
                    while (r[j] < n - 1 && h[r[j] + 1] >= h[j])
                        r[j] = r[j] + 1;
                }

                for (int j = 0; j < n; ++j) {
                    int tmp_area = h[j] * (r[j] - l[j] + 1);
                    if (tmp_area > max_area) max_area = tmp_area;
                }
            }
            return max_area;
        }
} ;


int main()
{
    vector<vector<char> > matrix;
    vector<char> a;

    a.push_back('1');
    a.push_back('1');
    a.push_back('0');
    a.push_back('1');
    a.push_back('1');
    matrix.push_back(a);

    a.clear();
    a.push_back('0');
    a.push_back('1');
    a.push_back('1');
    a.push_back('0');
    a.push_back('1');
    matrix.push_back(a);

    a.clear();
    a.push_back('1');
    a.push_back('0');
    a.push_back('1');
    a.push_back('1');
    a.push_back('1');
    matrix.push_back(a);

    a.clear();
    a.push_back('1');
    a.push_back('1');
    a.push_back('1');
    a.push_back('1');
    a.push_back('0');
    matrix.push_back(a);

    a.clear();
    a.push_back('1');
    a.push_back('0');
    a.push_back('1');
    a.push_back('1');
    a.push_back('0');

    matrix.push_back(a);
    Solution sl;
    cout << sl.maximalRectangle4( matrix);
    cout <<endl<< "==============" <<endl;

    cout << endl;
    return 0;
}
