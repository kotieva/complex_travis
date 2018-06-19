#include <fstream>
#include <iostream>
using namespace std;

class Matrix {
private:
    int **ptr;
    int rows;
    int columns;
public:
    Matrix() {
        rows = 5;
        columns = 5;
        ptr = new int*[rows];
        for(int i = 0; i < rows; ++i) {
            ptr[i] = new int[columns];
        }
    }

    Matrix(int _rows, int _columns) {
        rows = _rows;
        columns = _columns;
        ptr = new int*[rows];
        for(int i = 0; i < rows; ++i) {
            ptr[i] = new int[columns];
        }
    }

    ~Matrix() {
        delete [] ptr;
    }

    int getRows() {
        return rows;
    }

    int getColumns() {
        return columns;
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void fill(string path) {
        ifstream fin;
        fin.open(path);
        if (!fin.is_open()) {
            cout << "Ошибка открытия файла!" << endl;
        } else {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    fin >> ptr[i][j];
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Matrix myMatrix(3, 3);
    myMatrix.fill("sinput.txt");
    myMatrix.print();
    return 0;
}
