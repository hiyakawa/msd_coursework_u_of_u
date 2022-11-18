package assignment04;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Random;

public class SortUtil<T> {

    public static <T> void mergesort(ArrayList<T> arrayList,
                                     Comparator<? super T> comparator) {

    }

    /**
     * @param arrayList the array list to be sorted.
     * @param comparator if input is null, use the default comparator.
     *                   Throws an exception if default comparator does not exist.
     * @param <T> type of the elements in the array list.
     */
    public static <T> void quicksort(ArrayList<T> arrayList,
                                     Comparator<? super T> comparator) {
        if (comparator == null) {
            try {
                comparator = (Comparator<T>) (o1, o2) ->
                        ((Comparable<T>) o1).compareTo(o2);
            }
            catch (Exception e) {
                e.printStackTrace();
            }
        }

        sort(arrayList, comparator, 0, arrayList.size() - 1);
    }

    /**
     * @param arrayList the array list to be sorted.
     * @param comparator if input is null, use the default comparator.
     *                   Throws an exception if default comparator does not exist.
     * @param low lower index.
     * @param high higher index.
     * @param <T> type of the elements in the array list.
     */
    private static <T> void sort(ArrayList<T> arrayList,
                                 Comparator<? super T> comparator,
                                 int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arrayList, comparator, low, high);

            // recursively sort the two sub arrays divided by the pivot
            sort(arrayList, comparator, low, pivotIndex - 1);
            sort(arrayList, comparator, pivotIndex + 1, high);
        }
    }

    /**
     * @param arrayList the array list to be sorted.
     * @param comparator if input is null, use the default comparator.
     *                   Throws an exception if default comparator does not exist.
     * @param low lower index.
     * @param high higher index.
     * @param <T> type of the elements in the array list.
     * @return the index of pivot.
     */
    private static <T> int partition(ArrayList<T> arrayList,
                          Comparator<? super T> comparator,
                          int low, int high) {
        // You must implement three different strategies for determining the pivot.
        T pivot = arrayList.get(high);
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (comparator.compare(arrayList.get(j), pivot) <= 0) {
                i++;
                swapElements(arrayList, i, j);
            }
        }

        swapElements(arrayList, i + 1, high);
        return i + 1;
    }

    /**
     * @param arrayList the array list to be sorted.
     * @param lhsIndex the index of the left hand side element to be swapped.
     * @param rhsIndex the index of the right hand side element to be swapped.
     * @param <T> type of the elements in the array list.
     */
    private static <T> void swapElements(ArrayList<T> arrayList,
                                         int lhsIndex, int rhsIndex) {
        T temp = arrayList.get(lhsIndex);
        arrayList.set(lhsIndex, arrayList.get(rhsIndex));
        arrayList.set(rhsIndex, temp);
    }

    /**
     * @return an ArrayList of integers 1 to size in ascending order.
     */
    public static ArrayList<Integer> generateBestCase(int size) {
        if (size < 1) {
            return null;
        }

        ArrayList<Integer> ascendingIntArr = new ArrayList<>();

        for (int i = 1; i <= size; i++) {
            ascendingIntArr.add(i);
        }

        return ascendingIntArr;
    }

    /**
     * @return an ArrayList of integers 1 to size in permuted order.
     */
    public static ArrayList<Integer> generateAverageCase(int size) {
        if (size < 1) {
            return null;
        }

        ArrayList<Integer> randIntArr = new ArrayList<>();
        Random rand = new Random();

        // re-seed the Random with the same seed

        for (int i = 0; i < size; i++) {
            int randInt = rand.nextInt(size - 1) + 1;
            randIntArr.add(randInt);
        }

        return randIntArr;
    }

    /**
     * @return an ArrayList of integers 1 to size in descending order.
     */
    public static ArrayList<Integer> generateWorstCase(int size) {
        if (size < 1) {
            return null;
        }

        ArrayList<Integer> descendingIntArr = new ArrayList<>();

        for (int i = size; i > 0; i--) {
            descendingIntArr.add(i);
        }

        return descendingIntArr;
    }

    /**
     * @param arrayList the array list to be sorted.
     */
    public static void printIntArrayList(ArrayList<Integer> arrayList) {
        try {
            for (int i = 0; i < arrayList.size(); i++) {
                System.out.println(arrayList.get(i));
            }
        }
        catch (Exception e) {
            System.out.println("not able to print the elements");
        }
    }
}
