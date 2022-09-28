class Fraction {
    private long numerator_;
    private long denominator_;

    private long GCD() {
        long gcd = numerator_;
        long remainder = denominator_;

        while (remainder != 0) {
            long temp = remainder;
            remainder = gcd % remainder;
            gcd = temp;
        }

        return gcd;
    };

    private void reduce() {
        if (denominator_ == 0) {
            throw new IllegalArgumentException("The denominator is zero!");
        }

        long gcd = GCD();
        numerator_ /= gcd;
        denominator_ /= gcd;

        // the negative sign should always be on the numerator
        if (denominator_ < 0) {
            numerator_ = - numerator_;
            denominator_ = - denominator_;
        }
    };

    public Fraction() {
        numerator_ = 0;
        denominator_ = 1;
    };

    public Fraction(long n, long d) {
        // if denominator is 0, throw an exception
        if (d == 0) {
            throw new IllegalArgumentException("The denominator is zero!");
        }

        if (n == 0) {
            numerator_ = 0;
            denominator_ = 1;
        } else {
            numerator_ = n;
            denominator_ = d;

            long gcd = GCD();
            numerator_ /= gcd;
            denominator_ /= gcd;

            // the negative sign should always be on the numerator
            if (denominator_ < 0) {
                numerator_ = - numerator_;
                denominator_ = - denominator_;
            }
        }
    };

    public Fraction plus(Fraction rhs) {
        Fraction temp = new Fraction();
        temp.numerator_ = numerator_ * rhs.denominator_ + denominator_ * rhs.numerator_;
        temp.denominator_ = denominator_ * rhs.denominator_;
        temp.reduce();

        return temp;
    };

    public Fraction minus(Fraction rhs) {
        Fraction temp = new Fraction();
        temp.numerator_ = numerator_ * rhs.denominator_ - denominator_ * rhs.numerator_;
        temp.denominator_ = denominator_ * rhs.denominator_;
        temp.reduce();

        return temp;
    };

    public Fraction times(Fraction rhs) {
        Fraction temp = new Fraction();
        temp.numerator_ = numerator_ * rhs.numerator_;
        temp.denominator_ = denominator_ * rhs.denominator_;
        temp.reduce();

        return temp;
    };

    public Fraction dividedBy(Fraction rhs) {
        Fraction temp = new Fraction();
        temp.numerator_ = numerator_ * rhs.denominator_;
        temp.denominator_ = denominator_ * rhs.numerator_;
        temp.reduce();

        return temp;
    };

    public Fraction reciprocal() {
        Fraction temp = new Fraction();
        long temp_numerator = numerator_;
        temp.numerator_ = denominator_;
        temp.denominator_ = temp_numerator;
        temp.reduce();

        return temp;
    };

    public String toString() {
        String strFraction = numerator_ + "/" + denominator_;
        return strFraction;
    };

    public double toDouble() {
        double dblFraction = 1.0 * numerator_ / denominator_;
        return dblFraction;
    };
}

public class Main {
    public static void main(String[] args) {
    }
}