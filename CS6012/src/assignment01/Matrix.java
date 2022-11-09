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
        numRows_ = data.length; // d.length is the number of 1D arrays in the 2D array

        if (numRows_ == 0) {
            numColumns_ = 0;
        }
        else {
            numColumns_ = data[0].length; // d[0] is the first 1D array
        }

        data_ = new int[numRows_][numColumns_]; // create a new matrix to hold the data

        // copy the data over
        for (int i = 0; i < numRows_; i++) {
            for (int j = 0; j < numColumns_; j++) {
                data_[i][j] = data[i][j];
            }
        }
    }

    // copy constructor
    public Matrix(Matrix matrix) {
        numRows_ = matrix.numRows_;
        numColumns_ = matrix.numColumns_;
        data_ = new int[numRows_][numColumns_];

        // copy the data over
        for (int i = 0; i < numRows_; i++) {
            for (int j = 0; j < numColumns_; j++) {
                data_[i][j] = matrix.data_[i][j];
            }
        }
    }

    @Override
    public boolean equals(Object other) {
        if (!(other instanceof Matrix)) {
            // make sure the Object we're comparing to is a Matrix
            return false;
        }

        Matrix matrix = (Matrix) other;
        // if the above was not true, we know it's safe to treat 'o' as a Matrix

        // not equal if the dimensions are different
        if (this.numColumns_ != matrix.numColumns_ || this.numRows_ != matrix.numRows_) {
            return false;
        }

        // compare each cell
        for (int i = 0; i < numRows_; i++) {
            for (int j = 0; j < numColumns_; j++) {
                if (this.data_[i][j] != matrix.data_[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    @Override
    public String toString() {
        String matrixStr = "";

        for (int i = 0; i < numRows_; i++) {
            for (int j = 0; j < numColumns_; j++) {
                matrixStr += data_[i][j];
                matrixStr += " ";
            }
            matrixStr += "\n";
        }
        return matrixStr;
    }

    // addition
    public Matrix plus(Matrix matrix) {
        // check if the dimensions of the two matrices are compatible
        if (this.numColumns_ != matrix.numColumns_ || this.numRows_ != matrix.numRows_) {
            System.out.println("not compatible [error message: plus()]");
            return null;
        }

        int [][] resultData = new int[numRows_][numColumns_];
        Matrix result = new Matrix(resultData);

        for (int i = 0; i < numRows_; i++) {
            for (int j = 0; j < numColumns_; j++) {
                result.data_[i][j] = this.data_[i][j] + matrix.data_[i][j];
            }
        }
        return result;
    }

    // matrix multiplication
    public Matrix times(Matrix matrix) {
        // check if the dimensions of the two matrices are compatible
        if (this.numColumns_ != matrix.numRows_) {
            System.out.println("not compatible [error message: times()]");
            return null;
        }

        int [][] resultData = new int[this.numRows_][matrix.numColumns_];
        Matrix result = new Matrix(resultData);

        for (int i = 0; i < this.numRows_; i++) {
            for (int j = 0; j < matrix.numColumns_; j++) {
                int curCell = 0;

                for (int k = 0; k < this.numColumns_; k++) {
                    curCell += this.data_[i][k] * matrix.data_[k][j];
                }

                result.data_[i][j] = curCell;
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
        int[][] resultData = new int[this.numColumns_][this.numRows_];
        Matrix result = new Matrix(resultData);

        result.numRows_ = this.numColumns_;
        result.numColumns_ = this.numRows_;
        result.data_ = resultData;

        // copy the data over
        for (int i = 0; i < numRows_; i++) {
            for (int j = 0; j < numColumns_; j++) {
                result.data_[j][i] = this.data_[i][j];
            }
        }
        return result;
    }
}
