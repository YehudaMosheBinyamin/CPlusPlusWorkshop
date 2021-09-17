#include "Rational.h"


Rational::Rational(int mone, int mechane) :mone(mone), mechane(mechane) {
}

Rational::Rational(const Rational& num)
    :mone(num.getMone()),
    mechane(num.getMechane()) {}

void Rational::setMone(int myMone) { mone = myMone; }

void Rational::setMechane(int myMechane)
{
    mechane = myMechane;
}

int Rational::getMone() const { return mone; }
int Rational::getMechane() const { return mechane; }
void Rational::operator *=(Rational num)
{
    setMone(mone * num.getMone());
    setMechane(mechane * num.getMechane());
}
Rational Rational::operator *(Rational num)
{
    Rational tmp;
    tmp.setMone(mone * num.getMone());
    tmp.setMechane(mechane * num.getMechane());
    return tmp;
}
Rational Rational::operator +(Rational num)
{
    Rational tmp;
    tmp.setMone(mone * num.getMechane() +num.getMone() * mechane);
    tmp.setMechane(mechane * num.getMechane());
    return tmp;
}

Rational Rational::operator-(Rational other)
{
    Rational thisCopy = *this;
    Rational otherCopy = other;
    Rational result;
    int thisMechane=thisCopy.getMechane();
    int otherMechane;
    int commonMechane=thisMechane;
    otherMechane=otherCopy.getMechane();
       if(thisMechane != otherMechane) 
        {
           commonMechane = thisCopy.getMechane() * otherCopy.getMechane();
           thisCopy.setMechane(commonMechane);
           otherCopy.setMechane(commonMechane);
       }
       result = Rational(thisCopy.getMone() - otherCopy.getMone(), commonMechane);
       return result;
}
Rational& Rational::operator =(const Rational& num)
{
    mone = num.getMone();
    mechane = num.getMechane();
    return *this;
}
Rational Rational::operator/(Rational other)
{
    Rational temp;
    temp.mone = mone * other.mechane;
    temp.mechane = mechane * other.mone;
    return temp;
}
bool Rational::operator==(const Rational& num) const {
    return (mone == num.mone && mechane ==
        num.mechane);
}
bool Rational::operator!=(const Rational& other) const
{
    if (*this == other)
    {
        return false;
    }
    return true;
}
Rational Rational::operator++() {
    mone += mechane;
    return *this;
}
Rational Rational::operator++(int u) {
    Rational temp = *this;
    mone += mechane;
    return temp;
}
Rational & Rational::operator--()
{
    mone = mone-mechane;
    return *this;
}
Rational Rational::operator--(int)
{
    Rational temp=*this;
    mone = mone - mechane;
    return temp;
}
bool Rational::operator>(Rational other)
{
    float quotientThis = mone * 1.0 / mechane;
    float quotientOther = other.mone * 1.0 / mechane;
    return (quotientThis > quotientOther) ? true : false;
}
bool Rational::operator>=(Rational other)
{
    if (*this == other)
    {
        return true;
    }
    if (*this > other)
    {
        return true;
    }
    return false;
}
bool Rational::operator<(Rational other)
{
    float quotientThis = mone * 1.0 / mechane;
    float quotientOther = other.mone * 1.0 / mechane;
    return (quotientThis<quotientOther) ? true : false;
}
bool Rational::operator<=(Rational other)
{
    if (*this > other)
    {
        return false;
    }
    return true;
}
void Rational::minimizeFraction()
{
    int divisor = 0;
    do
    {
        divisor++;
    } while ((mone % divisor==0) && (mechane % divisor==0));
    setMone(mone / divisor);
    setMechane(mechane / divisor);
}
Rational& Rational::operator+=(const Rational& num)
{
    mone = mone + num.getMone();
    return *this;
}


ostream& operator<<(ostream& s, Rational& r)
{
    int mone=r.getMone();
    int mechane = r.getMechane();
    r.minimizeFraction();
    if (mone == 0)
    {
        cout <<mone;
    }
    else if (mechane == 1 ||(mone==mechane))
    {
        s<<"1";
    }
    else
    {
        s<< mone << "/" << mechane;
    }
    return s;
}
void Rational:: print()
{
    minimizeFraction();
    if (mone == 0)
    {
        cout << mone;
    }
    else if (mechane == 1)
    {
        cout << mechane;
    }
    else
    {
        cout << mone << "/" << mechane << endl;
    }
}
istream& operator>>(istream& s, Rational& r)
{
    char slash;
    s >> r.mone;
    s >> slash;
    s >> r.mechane;
    if (r.mechane == 0)
    {
        cout << "ERROR" << endl;
        r.mechane = 1;
    }
    return s;
}
