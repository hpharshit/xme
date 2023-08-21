// M[i,j]=M[j,i]
// can use lower or upper triangle matrix concept
#include <iostream>
using namespace std;
class Matrix
{
    int *A;
    int n;

public:
    Matrix(){};
    Matrix(int n)
    {
        this->n = n*(n+1)/2;
        A = new int[this->n];
    };
    void Set(int i, int j, int x)
    {
        // upper 
        if (i <= j)
        {
            A[n*(i-1)+ (i-1)*(i-2)/2+(j-i)] = x;
            A[i*(i-1)/2+j-1]=x;
        }
    }
    int Get(int i, int j)
    {
        if (i <= j)
            return A[n*(i-1)+ (i-1)*(i-2)/2+(j-i)];
        else
            return A[i*(i-1)/2+j-1];
    }
    void Display(int a)
    {
        int i, j;
        for (i = 1; i <= a; i++)
        {
            for (j = 1; j <= a; j++)
            {
                   printf("%d ", A[j-1]);
            }
            printf("\n");
        }
    }

    ~Matrix()
    {
        delete[] A;
    };
};

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    Matrix m(d);

    int x;
    cout << "Enter All Elements: \n";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }
    cout<<"\nDisplaying lower triangle matrix : \n";
    m.Display(d);

    return 0;
}