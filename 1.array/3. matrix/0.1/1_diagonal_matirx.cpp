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
        this->n = n;
        A = new int[n];
    };
    void Set(int i, int j, int x)
    {
        if (i == j)
            A[i - 1] = x;
    }
    int Get(int i, int j)
    {
        if (i == j)
            return A[i - 1];
        else
            return 0;
    }
    void Display()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                    printf("%d ", A[i]);
                else
                    printf("0 ");
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
    cout << "Enter All Elements";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }

    m.Display();

    return 0;
}