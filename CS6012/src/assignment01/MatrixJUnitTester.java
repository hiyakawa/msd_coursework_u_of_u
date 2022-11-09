/*
 * MatrixJUnitTester.java
 * Author: Muyuan Zhang
 * CS 6012 Assignment 1: Matrix
 * File 2 of 2
 */

package assignment01;

import org.junit.Assert;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class MatrixTest {
    Matrix oneByOne;
    Matrix twoByThree;
    Matrix threeByTwo;
    Matrix twoByTwo;

    @BeforeEach
    public void setUp() throws Exception {
        int[][] oneByOneData = {{-1}};
        int[][] twoByThreeData = {{1, 2, 3}, {4, 5, 6}};
        int[][] threeByTwoData = {{7, 8}, {9, 10}, {11, 12}};
        int[][] twoByTwoData = {{58, 64}, {139, 154}};
        oneByOne = new Matrix(oneByOneData);
        twoByThree = new Matrix(twoByThreeData);
        threeByTwo = new Matrix(threeByTwoData);
        twoByTwo = new Matrix(twoByTwoData);
    }

    @Test
    public void timesWithBalancedDimensions() {
        Matrix result = twoByThree.times(threeByTwo);

        Assertions.assertTrue(twoByTwo.equals(result));
    }

    @Test
    public void timesWithUnbalancedDimensions() {
        Matrix result = threeByTwo.times(threeByTwo);

        // should return null if the matrices are not compatible
        Assertions.assertNull(result);
    }

    @Test
    public void timesADouble() {
        Matrix result = twoByThree.times(2);
        int[][] twoByThreeResultData = {{2, 4, 6}, {8, 10, 12}};
        Matrix twoByThreeResult = new Matrix(twoByThreeResultData);

        Assertions.assertTrue(twoByThreeResult.equals(result));
    }

    @Test
    public void plusWithBalancedDimensions() {
        Matrix result = oneByOne.plus(oneByOne);

        int[][] oneByOneResultData = {{-2}};
        Matrix oneByOneResult = new Matrix(oneByOneResultData);

        Assertions.assertTrue(result.equals(oneByOneResult));
    }

    @Test
    public void plusWithUnbalancedDimensions() {
        Matrix result = twoByThree.plus(threeByTwo);

        // should return null if the matrices are not compatible
        Assertions.assertNull(result);
    }

    @Test
    public void twoByThreeToString() {
        String resultString = "1 2 3 \n4 5 6 \n";
        Assert.assertEquals(resultString, twoByThree.toString());
    }

    @Test
    public void twoByThreeTransposition() {
        int[][] threeByTwoResultData = {{1, 4}, {2, 5}, {3, 6}};
        Matrix threeByTwoResult = new Matrix(threeByTwoResultData);
        Assertions.assertTrue(threeByTwoResult.equals(twoByThree.transpose()));

        // try to transpose twice and get the original matrix
        Assertions.assertTrue(twoByThree.equals(twoByThree.transpose().transpose()));
    }

    @AfterEach
    public void tearDown() throws Exception {
        oneByOne = null;
        twoByThree = null;
        threeByTwo = null;
        twoByTwo = null;
    }
}