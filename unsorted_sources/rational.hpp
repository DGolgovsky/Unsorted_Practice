struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);

    void sub(Rational rational);

    void mul(Rational rational);

    void div(Rational rational);

    void neg();

    void inv();

    double to_double() const;

    Rational &operator+=(const Rational &rational) {
        this->add(rational);
        return *this;
    }

    Rational &operator+=(int d) {
        this->add(Rational(d));
        return *this;
    }

    Rational &operator-=(const Rational &rational) {
        this->sub(rational);
        return *this;
    }

    Rational &operator-=(int d) {
        this->sub(Rational(d));
        return *this;
    }

    Rational &operator*=(const Rational &rational) {
        this->mul(rational);
        return *this;
    }

    Rational &operator*=(int d) {
        this->mul(Rational(d));
        return *this;
    }

    Rational &operator/=(const Rational &rational) {
        this->div(rational);
        return *this;
    }

    Rational &operator/=(int d) {
        this->div(Rational(d));
        return *this;
    }

    Rational operator-() const {
        Rational r(this->numerator_, this->denominator_);
        r.neg();
        return r;
    }

    Rational operator+() const {
        Rational r(this->numerator_, this->denominator_);
        return r;
    }

    Rational operator+(const Rational &rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.add(rational);
        return r;
    }

    Rational operator+(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.add(Rational(d));
        return r;
    }

    friend Rational operator+(int d, const Rational &rational) {
        return rational + d;
    }

    Rational operator-(const Rational &rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(rational);
        return r;
    }

    Rational operator-(double d) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(Rational(d));
        return r;
    }

    friend Rational operator-(int d, const Rational &rational) {
        return -(rational - d);
    }

    Rational operator*(const Rational &rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(rational);
        return r;
    }

    Rational operator*(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(Rational(d));
        return r;
    }

    friend Rational operator*(int d, const Rational &rational) {
        return rational * d;
    }

    Rational operator/(const Rational &rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(rational);
        return r;
    }

    Rational operator/(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(Rational(d));
        return r;
    }

    friend Rational operator/(int d, const Rational &rational) {
        return Rational(d) / rational;
    }

    double to_double_() const {
        return double(this->numerator_) / this->denominator_;
    }

    operator double() const {
        return to_double();
    }

    bool operator<(const Rational &rational) const {
        return this->to_double_() < rational.to_double_();
    }

    bool operator<(int d) const {
        return this->to_double_() < d;
    }

    friend bool operator<(int d, const Rational &rational) {
        return d < rational.to_double_();
    }

    bool operator>(const Rational &rational) const {
        return this->to_double_() > rational.to_double_();
    }

    bool operator>(int d) const {
        return this->to_double_() > d;
    }

    friend bool operator>(int d, const Rational &rational) {
        return d > rational.to_double_();
    }

    bool operator<=(const Rational &rational) const {
        return !(*this > rational);
    }

    bool operator<=(int d) const {
        return !(*this > d);
    }

    friend bool operator<=(int d, const Rational &rational) {
        return !(d > rational);
    }

    bool operator>=(const Rational &rational) const {
        return !(*this < rational);
    }

    bool operator>=(int d) const {
        return !(*this < d);
    }

    friend bool operator>=(int d, const Rational &rational) {
        return !(d < rational);
    }

    bool operator==(const Rational &rational) const {
        return this->to_double_() == rational.to_double_();
    }

    bool operator==(int d) const {
        return this->to_double_() == d;
    }

    friend bool operator==(int d, const Rational &rational) {
        return d == rational.to_double_();
    }

    bool operator!=(const Rational &rational) const {
        return !(*this == rational);
    }

    bool operator!=(int d) const {
        return !(*this == d);
    }

    friend bool operator!=(int d, const Rational &rational) {
        return !(rational == d);
    }

private:
    int numerator_;
    unsigned denominator_;
};

Rational operator+(Rational lhs, Rational rhs);

Rational operator-(Rational lhs, Rational rhs);

Rational operator*(Rational lhs, Rational rhs);

Rational operator/(Rational lhs, Rational rhs);
