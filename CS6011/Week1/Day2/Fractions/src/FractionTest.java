import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

// Test Class
class FractionTest {
    @Test
    public void runAllTests() {
        Assertions.assertEquals(3,3);
    }

    @Test
    public void testTimes() {
        Fraction f1 = new Fraction(-6, 12);
        Fraction f2 = new Fraction(1, 3);

        Fraction f3 = f2.plus(f1);
        Assertions.assertEquals(f3.toString(), "-1/6");

        Fraction f4 = f2.minus(f1);
        Assertions.assertEquals(f4.toString(), "5/6");

        Fraction f5 = f1.times(f2);
        Assertions.assertEquals(f5.toString(), "-1/6");

        Fraction f6 = f1.dividedBy(f2);
        Assertions.assertEquals(f6.toString(), "-3/2");

        Fraction f7 = f1.reciprocal();
        Assertions.assertEquals(f7.toString(), "-2/1");
    }
}