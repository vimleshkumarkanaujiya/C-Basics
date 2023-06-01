#include <iostream>
#include <complex>
#include <cmath>
#include <vector>

typedef std::complex<double> Complex;
const double PI = 3.14159265358979323846;

// Cooley-Tukey FFT algorithm
void fft(std::vector<Complex>& x) {
    int n = x.size();
    if (n <= 1)
        return;

    // Separate the even and odd elements
    std::vector<Complex> even(n / 2);
    std::vector<Complex> odd(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        even[i] = x[2 * i];
        odd[i] = x[2 * i + 1];
    }

    // Recursively compute the FFT of the even and odd elements
    fft(even);
    fft(odd);

    // Combine the results
    for (int k = 0; k < n / 2; k++) {
        Complex t = std::polar(1.0, -2 * PI * k / n) * odd[k];
        x[k] = even[k] + t;
        x[k + n / 2] = even[k] - t;
    }
}

// Inverse FFT (IFFT) using FFT
void ifft(std::vector<Complex>& x) {
    // Take the conjugate of the input
    for (Complex& c : x)
        c = std::conj(c);

    // Compute FFT
    fft(x);

    // Take the conjugate again and scale
    for (Complex& c : x) {
        c = std::conj(c);
        c /= x.size();
    }
}

int main() {
    std::vector<Complex> x = {1, 2, 3, 4};
    int n = x.size();

    std::cout << "Input sequence: ";
    for (int i = 0; i < n; i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;

    // Compute FFT
    fft(x);

    std::cout << "FFT: ";
    for (int i = 0; i < n; i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;

    // Compute IFFT
    ifft(x);

    std::cout << "IFFT: ";
    for (int i = 0; i < n; i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;

    return 0;
}
