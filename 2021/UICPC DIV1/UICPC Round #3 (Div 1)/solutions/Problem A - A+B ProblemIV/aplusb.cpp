#include <bits/stdc++.h>
using namespace std;

// A+B Problem

// Spending a week solving this problem...

vector<complex<double>> fft(int n, int m, vector<complex<double>> coeffs, int divisor){
    /*
    n: degree of polynomial f
    m: 2^k upper bound of n
    coeffs: coefficients of polynomial f in increasing order (a0, a1, a2, ..., an-1)
    divisor: initially should be set to 1
    returns vector of (yk)s for k from 0 to n-1 as yk = f(e^{i(k/n)*2pi})
    */
    vector<complex<double>> ans;
    if(coeffs.size() == 1){
        for(int k = 0; k < m; k += divisor)
            ans.push_back(coeffs[0]);
        return ans;
    }
    vector<complex<double>> even, odd;
    for(int i = 0; i < coeffs.size(); i++){
        if(i % 2)
            odd.push_back(coeffs[i]);
        else
            even.push_back(coeffs[i]);
    }
    vector<complex<double>> fft_even = fft(n, m, even, divisor * 2), fft_odd = fft(n, m, odd, divisor * 2);
    for(int k = 0; k < m; k += divisor)
        ans.push_back(fft_even[int(ans.size()) % (m / (divisor * 2))] + polar(1.0, (double(k) / m) * 2.0 * M_PI) * fft_odd[int(ans.size()) % (m / (divisor * 2))]);
    return ans;
}

vector<int> powers_of_two{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152};

vector<complex<double>> convolution(vector<complex<double>> cf, vector<complex<double>> cg){
    /*
    cf: coefficients of polynomial f in increasing order (a0, a1, a2, ..., an-1)
    cg: coefficients of polynomial g in increasing order (b0, b1, b2, ..., bm-1)
    returns coefficients of polynomial f*g (convolution of f and g) in increasing order (c0, c1, c2, ..., cn+m-2)
    n = degree of polynomial f
    m = degree of polynomial g
    n + m - 1 = degree of polynomial f*g
    */
    int n = cf.size(), m = cg.size(), s = *lower_bound(powers_of_two.begin(), powers_of_two.end(), n + m - 1);
    vector<complex<double>> f = fft(n, s, cf, 1), g = fft(m, s, cg, 1);
    vector<complex<double>> cfg;
    for(int i = 0; i < s; i++)
        cfg.push_back((f[i] * g[i]) / complex<double>(s));
    vector<complex<double>> fg = fft(s, s, cfg, 1), ans;
    ans.push_back(fg.front());
    for(int i = 1; i < n + m - 1; i++)
        ans.push_back(fg[s - i]);
    return ans;
}

#define num long long int

const int maxn = 1e5 + 1;
const int o = 5e4;

int frequency[maxn], zeroes = 0;
vector<complex<double>> polynomial;

int main(){
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x == 0)
            zeroes++;
        else
            frequency[x + o]++;
    }
    for(int i = 0; i < maxn; i++)
        polynomial.push_back(frequency[i]);
    vector<complex<double>> ff_convolution = convolution(polynomial, polynomial);
    num ans = 0;
    for(int i = o; i < maxn + o; i++){
        num cnt = static_cast<num>(ff_convolution[i].real() + 0.5);
        ans += cnt * frequency[i - o];
    }
    for(int i = 0; i < maxn; i++)
        if(frequency[i]){
            int j = 2 * (i - o) + o;
            if(j >= 0 && j < maxn && frequency[j])
                ans -= ((num)frequency[j]) * frequency[i];
        }
    if(zeroes >= 3)
        ans += ((num)zeroes) * (zeroes - 1) * (zeroes - 2);
    for(int i = 0; i < maxn; i++)
        if(frequency[i] >= 2)
            ans += ((num)frequency[i]) * zeroes * (frequency[i] - 1) * 2;
    for(int i = 0; i < maxn; i++)
        if(frequency[i]){
            int j = -(i - o) + o;
            ans += ((num)frequency[i]) * frequency[j] * zeroes;
        }
    cout << ans << endl;
}