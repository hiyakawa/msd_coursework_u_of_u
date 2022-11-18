package assignment04;

import org.junit.jupiter.api.Test;
import java.util.ArrayList;
import java.util.Comparator;
import static assignment04.SortUtil.*;
import static org.junit.jupiter.api.Assertions.*;

class SortUtilTest {

    @Test
    public void mergesortTest() {
    }

    @Test
    public void quicksortTest() {
        ArrayList<Integer> averageArrayList = generateAverageCase(100);
        Comparator<Integer> reverseComparator = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return ((Comparable<Integer>) o2).compareTo(o1);
            }
        };
        quicksort(averageArrayList, reverseComparator);
        quicksort(averageArrayList, null);
//        SortUtil.printIntArrayList(averageArrayList);

        ArrayList<Integer> worstArrayList = generateWorstCase(100);
//        quicksort(worstArrayList, null);
        quicksort(worstArrayList, reverseComparator);
//        SortUtil.printIntArrayList(worstArrayList);
    }

    @Test
    public void generateBestCaseTest() {
        assertNull(generateBestCase(-10));
        assertNull(generateBestCase(0));

        ArrayList<Integer> bestCaseArrayList = generateBestCase(100);
        SortUtil.printIntArrayList(bestCaseArrayList);
    }

    @Test
    public void generateAverageCaseTest() {
        assertNull(generateAverageCase(-10));
        assertNull(generateAverageCase(0));

        ArrayList<Integer> averageArrayList = generateAverageCase(100);
        SortUtil.printIntArrayList(averageArrayList);
    }

    @Test
    public void generateWorstCaseTest() {
        assertNull(generateWorstCase(-10));
        assertNull(generateWorstCase(0));

        ArrayList<Integer> worstArrayList = generateWorstCase(100);
        SortUtil.printIntArrayList(worstArrayList);
    }
}