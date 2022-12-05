package assignment06;

import java.util.Collection;
import java.util.LinkedList;

public class ChainingHashTable implements Set<String> {
    private LinkedList<String>[] storage_;
    private int size_;
    private int capacity_;
    private HashFunctor functor_;

    @SuppressWarnings("unchecked")
    public ChainingHashTable(int capacity, HashFunctor functor) {
        capacity_ = capacity;
        storage_ = (LinkedList<String>[]) new LinkedList[capacity_];
        size_ = 0;
        functor_ = functor;
    }

    /**
     * Ensures that this set contains the specified item.
     * @param item the item whose presence is ensured in this set
     * @return true if this set changed as a result of this method call
     * (that is, if the input item was actually inserted);
     * otherwise, returns false
     */
    @Override
    public boolean add(String item) {
        if (this.contains(item)) {
            return false;
        }

        int bucket = functor_.hash(item);
        LinkedList<String> newList = storage_[bucket];
        newList.add(item);

        if (storage_[bucket] != null) {
            // shift all the elements after bucket to the right
            for (int curIndex = size_; curIndex > bucket; curIndex--) {
                storage_[curIndex] = storage_[curIndex - 1];
            }
        }

        storage_[bucket] = newList;
        size_++;
        growTable();
        return true;
    }

    /**
     * Ensures that this set contains all items in the specified collection.
     * @param items the collection of items whose presence is ensured in this set
     * @return true if this set changed as a result of this method call
     * (that is, if any item in the input collection was actually inserted);
     * otherwise, returns false
     */
    @Override
    public boolean addAll(Collection<? extends String> items) {
        return false;
    }

    /**
     * Removes all items from this hash table. The hash table will be empty after this method call.
     */
    @Override
    @SuppressWarnings("unchecked")
    public void clear() {
        capacity_ = storage_.length;
        storage_ = (LinkedList<String>[]) new LinkedList[capacity_];
        size_ = 0;
    }

    /**
     * Determines if there is an item in this set that is equal to the specified item.
     * @param item the item sought in this set
     * @return true if there is an item in this set that is equal to the input item; otherwise, returns false
     */
    @Override
    public boolean contains(String item) {
        int bucket = functor_.hash(item);
        if (storage_[bucket] == null)
            return false;
        LinkedList<String> list = storage_[bucket];
        for (String entry : list) {
            if (entry.equals(item))
                return true;
        }
        return false;
    }

    /**
     * Determines if for each item in the specified collection, there is an item in this set that is equal to it.
     * @param items the collection of items sought in this set
     * @return true if for each item in the specified collection, there is an item in this set that is equal to it;
     * otherwise, returns false
     */
    @Override
    public boolean containsAll(Collection<? extends String> items) {
        return false;
    }

    /**
     * Returns true if this hash table contains no items.
     */
    @Override
    public boolean isEmpty() {
        return size_ == 0;
    }

    /**
     * Ensures that this set does not contain the specified item.
     * @param item the item whose absence is ensured in this set
     * @return true if this set changed as a result of this method call
     * (that is, if the input item was actually removed);
     * otherwise, returns false
     */
    @Override
    public boolean remove(String item) {
        int bucket = functor_.hash(item);

        if (storage_[bucket] == null) {
            // nothing to remove
            return false;
        }

        LinkedList<String> list = storage_[bucket];
        LinkedList<String> listCopy = new LinkedList<>();
        // copy all the elements except for input item to a new list
        for (String curStr : list) {
            if (! curStr.equals(item)) {
                listCopy.add(curStr);
            }
        }
        // copy over
        storage_[bucket] = (listCopy.size() == 0) ? null: new LinkedList<>(listCopy);
        return true;
    }


    /**
     * Ensures that this set does not contain any of the items in the specified collection.
     * @param items the collection of items whose absence is ensured in this set
     * @return true if this set changed as a result of this method call
     * (that is, if any item in the input collection was actually removed);
     * otherwise, returns false
     */
    @Override
    public boolean removeAll(Collection<? extends String> items) {
        return false;
    }

    /**
     * Returns the number of items in this hash table.
     */
    @Override
    public int size() {
        return size_;
    }

    @SuppressWarnings("unchecked")
    private void growTable() {
        if (size_ >= 0.75 * storage_.length) {
            LinkedList<String>[] newStorage = (LinkedList<String>[]) new LinkedList[storage_.length * 2];
            for (int curIndex = 0; curIndex < storage_.length; curIndex++) {
                LinkedList<String> list = storage_[curIndex];

                while (list != null) {
                    int hash = (Math.abs(list.hashCode())) % newStorage.length;
                }
            }
        }
    }
}
