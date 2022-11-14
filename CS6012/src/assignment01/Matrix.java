/*
 * Matrix.java
 * Author: Muyuan Zhang
 * CS 6012 Assignment 1: Matrix
 * File 1 of 2
 */

package assignment01;

public class Matrix {
    int numRows_;
    int numColumns_;
    int data_[][];

    // constructor with data for new matrix (automatically determines dimensions)
    public Matrix(int data[][]) {
        // d.length is the number of 1D arrays in the 2D array
        numRows_ = data.length;

        if (numRows_ == 0) {
            numColumns_ = 0;
        }
        else {
            numColumns_ = data[0].length;
            // d[0] is the first 1D array
        }

        // create a new matrix to hold the data
        data_ = new int[numRows_][numColumns_];

        // copy the data over
        for (int curRow = 0; curRow < numRows_; curRow++) {
            for (int curCol = 0; curCol < numColumns_; curCol++) {
                data_[curRow][curCol] = data[curRow][curCol];
            }
        }
    }

    // copy constructor
    public Matrix(Matrix matrix) {
        numRows_ = matrix.numRows_;
        numColumns_ = matrix.numColumns_;
        data_ = new int[numRows_][numColumns_];

        // copy the data over
        for (int curRow = 0; curRow < numRows_; curRow++) {
            for (int curCol = 0; curCol < numColumns_; curCol++) {
                data_[curRow][curCol] = matrix.data_[curRow][curCol];
            }
        }
    }

    // constructor for empty matrix
    public Matrix(int numRows, int numCols) {
        numRows_ = numRows;

        if (numRows_ == 0) {
            numColumns_ = 0;
        }
        else {
            numColumns_ = numCols;
            data_ = new int[numRows_][numColumns_];
        }
    }

    @Override
    public boolean equals(Object other) {
        if (!(other instanceof Matrix)) {
            // make sure the Object we're comparing to is a Matrix
            return false;
        }

        // if the above was not true, we know it's safe to treat 'o' as a Matrix
        Matrix matrix = (Matrix) other;

        // not equal if the dimensions are different
        if (numColumns_ != matrix.numColumns_ || numRows_ != matrix.numRows_) {
            return false;
        }

        // compare each element
        for (int curRow = 0; curRow < numRows_; curRow++) {
            for (int curCol = 0; curCol < numColumns_; curCol++) {
                if (data_[curRow][curCol] != matrix.data_[curRow][curCol]) {
                    return false;
                }
            }
        }

        return true;
    }

    @Override
    public String toString() {
        String matrixStr = "";

        for (int curRow = 0; curRow < numRows_; curRow++) {
            for (int curCol = 0; curCol < numColumns_; curCol++) {
                matrixStr += (data_[curRow][curCol] + " ");
            }
            matrixStr += "\n";
        }

        return matrixStr;
    }

    // addition
    public Matrix plus(Matrix matrix) {
        // check if the dimensions of the two matrices are compatible
        if (numColumns_ != matrix.numColumns_ || numRows_ != matrix.numRows_) {
            System.out.println("not compatible [error message: plus()]");
            return null;
        }

        Matrix result = new Matrix(numRows_, numColumns_);

        for (int i = 0; i < numRows_; i++) {
            for (int j = 0; j < numColumns_; j++) {
                result.data_[i][j] = data_[i][j] + matrix.data_[i][j];
            }
        }

        return result;
    }

    // matrix multiplication
    public Matrix times(Matrix matrix) {
        // check if the dimensions of the two matrices are compatible
        if (numColumns_ != matrix.numRows_
                || numRows_ == 0 || matrix.numRows_ == 0) {
            System.out.println("not compatible [error message: times()]");
            return null;
        }

//        int [][] resultData = new int[numRows_][matrix.numColumns_];
        Matrix result = new Matrix(numRows_, matrix.numColumns_);

        // iterate through the two matrices
        for (int curRow = 0; curRow < numRows_; curRow++) {
            for (int curCol = 0; curCol < matrix.numColumns_; curCol++) {
                int curElementValue = 0;

                // calculate the elements in the result matrix
                for (int curElement = 0; curElement < numColumns_; curElement++) {
                    curElementValue += data_[curRow][curElement] * matrix.data_[curElement][curCol];
                }

                result.data_[curRow][curCol] = curElementValue;
            }
        }

        return result;
    }

    // scalar multiplication
    public Matrix times(int scale) {
        Matrix result = new Matrix(this);

        for (int i = 0; i < result.numRows_; i++) {
            for (int j = 0; j < result.numColumns_; j++) {
                result.data_[i][j] *= scale;
            }
        }

        return result;
    }

    // transposition
    public Matrix transpose() {
//        int [][] resultData = new int[numColumns_][numRows_];
        Matrix result = new Matrix(numColumns_, numRows_);

        // copy the data over
        for (int curRow = 0; curRow < numRows_; curRow++) {
            for (int curCol = 0; curCol < numColumns_; curCol++) {
                result.data_[curCol][curRow] = data_[curRow][curCol];
            }
        }

        return result;
    }
}
