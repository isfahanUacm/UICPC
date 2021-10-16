#include <bits/stdc++.h>
using namespace std;

// Flight Collision

#define num long long int

const num inf = LLONG_MAX;

num GCD(num a, num b) {
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

struct fraction {

        num numerator, denominator;
        double real;

        fraction(){
            this->numerator = 0;
            this->denominator = 1;
            this->real = 0.0;
        }

        fraction(num numerator, num denominator){
            if(denominator == 0){
                this->numerator = inf;
                this->denominator = 1;
            }
            else if(numerator == 0){
                this->numerator = 0;
                this->denominator = 1;
            }
            else{
                num sign = (numerator > 0 ? 1 : -1) * (denominator > 0 ? 1 : -1);
                numerator = abs(numerator), denominator = abs(denominator);
                num gcd = GCD(min(numerator, denominator), max(numerator, denominator));
                this->numerator = sign * numerator / gcd;
                this->denominator = denominator / gcd;
            }
            this->real = double(this->numerator) / this->denominator;
        }

        fraction& operator=(const fraction &other) = default;
           
        fraction(double real) {
            this->real = real;
            char str[50];
            sprintf(str, "%f", real);
            int str_len = strlen(str);
            double exp = pow(10, str_len - (find(str, str + str_len, '.') - str) - 1);
            numerator = real  * exp;
            denominator = exp;
            num gcd = GCD(min(numerator, denominator), max(numerator, denominator));
            numerator = numerator / gcd;
            denominator = denominator / gcd;
        }

        bool operator<(const fraction &other) const {
            if(this->numerator == inf)
                return false;
            if(other.numerator == inf)
                return true;
            return this->numerator * other.denominator < other.numerator * this->denominator;
        }

        bool operator==(const fraction &other) const {
            return this->numerator == other.numerator && this->denominator == other.denominator;
        }

        operator const char *() const {
            char *buffer = (char *) malloc(20);
            sprintf(buffer, "%lld/%lld", this->numerator, this->denominator);
            return buffer;
        }

        fraction negate(){
            if(this->numerator == inf)
                return fraction(1, 0);
            if(this->numerator == 0)
                return fraction(0, 1);
            return fraction(-this->numerator, this->denominator);
        }

        fraction reverse(){
            if(this->numerator == inf)
                return fraction(0, 1);
            if(this->numerator == 0)
                return fraction(1, 0);
            return fraction(this->denominator, this->numerator);
        }

        fraction operator+(const fraction &other) const {
            return fraction(this->numerator * other.denominator + other.numerator * this->denominator, this->denominator * other.denominator);
        }

        fraction operator-(const fraction &other) const {
            return fraction(this->numerator * other.denominator - other.numerator * this->denominator, this->denominator * other.denominator);
        }

        fraction operator*(const fraction &other) const {
            return fraction(this->numerator * other.numerator, this->denominator * other.denominator);
        }

        fraction operator/(const fraction &other) const {
            fraction p(this->numerator, this->denominator);
            fraction q(other.numerator, other.denominator);
            return p * q.reverse();
        }
};

const int maxn = 1e5 + 3;

int n, x[maxn], v[maxn];
set<int> alive;

struct collision{

    int i, j;
    fraction t;

    collision(int i, int j, fraction t){
        this->i = i;
        this->j = j;
        this->t = t;
    }

    bool operator<(const collision& o) const{
        return o.t < this->t;
    }

};

priority_queue<collision> pq;

inline void collide(int i, int j){
    fraction t(x[j] - x[i], v[i] - v[j]);
    if(t.numerator == inf || t.numerator < 0)
        return;
    pq.push(collision(i, j, t));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> v[i];
        alive.insert(i);
    }
    for(int i = 0; i < n-1; i++){
        collide(i, i+1);
    }
    while(!pq.empty()){
        collision c = pq.top();
        pq.pop();
        auto left = alive.find(c.i);
        auto right = alive.find(c.j);
        if(left == alive.end() || right == alive.end()){
            continue;
        }
        if(left != alive.begin() && next(right) != alive.end()){
            auto moreLeft = prev(left);
            auto moreRight = next(right);
            collide(*moreLeft, *moreRight);
        }
        alive.erase(left);
        alive.erase(right);
    }
    cout << alive.size() << endl;
    for(int a : alive)
        cout << a + 1 << " ";
    cout << endl;
}