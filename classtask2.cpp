#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** data;
    int rows;
    int cols;

    void allocate(int r, int c, int fillValue = 0) {
        data = new int*[r];
        for (int i = 0; i < r; ++i) {
            data[i] = new int[c];
            for (int j = 0; j < c; ++j) {
                data[i][j] = fillValue;
            }
        }
    }

    void deallocate() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    DynamicMatrix(int r, int c, int fillValue = 0) {
        rows = r;
        cols = c;
        allocate(rows, cols, fillValue);
    }

    ~DynamicMatrix() {
        deallocate();
    }

    void set(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = value;
        }
    }

    int get(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        }
        return 0;
    }

    void resize(int newRows, int newCols, int fillValue = 0) {
        int** newData = new int*[newRows];
        for (int i = 0; i < newRows; ++i) {
            newData[i] = new int[newCols];
            for (int j = 0; j < newCols; ++j) {
                if (i < rows && j < cols) {
                    newData[i][j] = data[i][j];
                } else {
                    newData[i][j] = fillValue;
                }
            }
        }

        deallocate();

        data = newData;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; ++i) {
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; ++j) {
                transposed[i][j] = data[j][i];
            }
        }

        deallocate();

        data = transposed;
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    void print(bool addTwoToOddIndices = false) const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int index = i * cols + j;
                int value = data[i][j];
                if (addTwoToOddIndices && (index % 2 == 1)) {
                    value += 2;
                }
                cout << value << " ";
            }
            cout << endl;
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};
int main() {
    DynamicMatrix mat(2, 3);

    int count = 1;
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            mat.set(i, j, count++);
        }
    }

    cout << "Original Matrix:" << endl;
    mat.print();

    mat.resize(3, 4, -1);
    cout << "\nResized Matrix (3x4, filled with -1):" << endl;
    mat.print();

    mat.transpose();
    cout << "\nTransposed Matrix:" << endl;
    mat.print();

    cout << "\nMatrix (adding 2 to elements at odd linear indices):" << endl;
    mat.print(true);

    return 0;
}
