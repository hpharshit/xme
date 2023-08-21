// M[i,j]=zero      i<j
// M[i,j]=non zero      i>=j
// total no. of non zero elements= n*(n+2)/2
// total no. of zero elements= n^2-n*(n+2)/2 =n*(n-1)/2
// arr[n*(n+1)/2] array is to be formed to store non zero elements
// accessing index formula should be M[i][j]=[n+n-1+n-2.....n-(i-2)]+[j-i]        //row major
                                    //      = [n*(i-1)+ (i-1)*(i-2)/2]+(j-i)  
                                           
// accessing index formula should be M[i][j]= [j*(j-1)/2] + [i-1]  //column major
   
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
        if (i <= j)
            A[n*(i-1)+ (i-1)*(i-2)/2+(j-i)] = x;//for row major
            // A[i*(i-1)/2] + j-1] = x;//for column major

    }
    int Get(int i, int j)
    {
        if (i <= j)
            return A[n*(i-1)+ (i-1)*(i-2)/2+(j-i)];//for row major
            // A[i*(i-1)/2] + j-1] = x;//for column major

        else
            return 0;
    }
    void Display(int a)
    {
        int i, j;
        for (i = 1; i <= a; i++)
        {
            for (j = 1; j <= a; j++)
            {
                if (i <= j)
                    printf("%d ", A[n*(i-1)+ (i-1)*(i-2)/2]+(j-i)); //for row major
            // A[i*(i-1)/2] + j-1] = x;//for column major

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