#include <iostream>
using namespace std;
template<typename T>
class Matrix
{
private:
    int rows;
    int cols;
    T**matrix;
public:
    Matrix()
    {
        rows=cols=0;
        matrix=new T*[0];
        matrix[0]=new T[0];
    }
    ~Matrix()
    {
        for(int i=0; i<rows; i++)
        {
            delete[]matrix[i];
            matrix[i]=0;
        }
    }
    Matrix(int rows,int cols)
    {
        this->rows=rows;
        this->cols=cols;
        matrix=new T*[rows];
        for(int i=0; i<rows; i++)
            matrix[i]=new T[cols];
    }
    Matrix(const Matrix&obj)
    {
        rows=obj.rows;
        cols=obj.cols;
        matrix=new T*[rows];
        for(int i=0; i<rows; i++)
            matrix[i]=new T[cols];
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                matrix[i][j]=obj.matrix[i][j];
    }
    Matrix<T>&operator=(const Matrix<T>&obj)
    {
        if(this==&obj)
            return *this;
        for(int i=0; i<rows; i++)
            delete[]matrix[i];
        rows=obj.rows;
        cols=obj.cols;
        matrix=new T*[rows];
        for(int i=0; i<rows; i++)
            matrix[i]=new T[cols];
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                matrix[i][j]=obj.matrix[i][j];
        return *this;

    }
    Matrix operator+=(const Matrix&obj)
    {
        if(rows!=obj.rows || cols!=obj.cols)
        {
            cout<<"Can't add two matrices of different sizes."<<endl;
            return *this;
        }
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                matrix[i][j]+=obj.matrix[i][j];
        return *this;
    }
    T&operator()(int r,int c)
    {
        if(r<0 || r>=rows || c<0 || c>=cols)
        {
            cout<<"Incorrect indexes"<<endl;
            return matrix[0][0];
        }
        return matrix[r][c];
    }
    template<typename T2>
    friend ostream& operator<<(ostream& os,const Matrix<T2>& obj);

};
template<typename T2>
ostream& operator<<(ostream& os,const Matrix<T2>& obj)
{
    for(int i=0; i<obj.rows; i++){
        for(int j=0; j<obj.cols; j++)
            os<<obj.matrix[i][j]<<"\t";
         os<<endl;
    }
    return os;

}
int main()
{
    Matrix<int> m1(2,2);
    m1(0,0)=1;
    m1(0,1)=2;
    m1(1,0)=3;
    m1(1,1)=4;
    cout<<m1;
    Matrix<int>m2;
    m2=m1;
    cout<<m2(0,0)<<endl;
    cout<<(m1+=m2);
    return 0;
}
