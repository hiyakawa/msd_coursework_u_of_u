public class MyRunnable implements Runnable {
    @Override
    public void run() {
        int count = (int) (Thread.currentThread().getID());
        while (count < 100) {
            System.out.println("hello number " + count + " from thread number ");
            count++;
        }
    }
}
