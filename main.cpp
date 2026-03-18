#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include "../NPAt_Core/NPAt_Interface.h"

using namespace std;

int main() {
    // Set console to UTF-8 for correct character display
    SetConsoleOutputCP(65001);
    
    cout << "--- NPAt RESEARCH SUITE v3.2 [HARD-TEST] ---" << endl;
    string s1, s2; 
    long long z;

    while (true) {
        cout << "\n===================================" << endl;
        cout << "N1 (Base): "; if (!(cin >> s1)) break;
        cout << "N2 (Step): "; if (!(cin >> s2)) break;
        cout << "z (Iter):  "; if (!(cin >> z)) break;

        // --- NPAt COMPUTATION (CORE) ---
        // Convert input strings to proprietary NPAt format
        NPAt n1 = convertToNPAt(s1, "");
        NPAt n2 = convertToNPAt(s2, "");
        NPAt acc = n1;

        for (long long i = 1; i <= z; i++) {
            // High-precision summation with integrity tracking (flag q)
            acc = addNPAt(acc, n2, i, false);
        }

        // --- STANDARD DOUBLE COMPUTATION (BASELINE) ---
        // Using 'volatile' to prevent compiler from optimizing the loop.
        // This forces the processor to perform actual memory access and arithmetic at each step.
        volatile double d_acc = stod(s1);
        volatile double d_step = stod(s2);

        for (long long i = 0; i < z; i++) {
            d_acc = d_acc + d_step;
        }

        // --- RESULTS COMPARISON ---
        cout << "\n--- COMPARISON (16 digits) ---" << endl;
        cout << scientific << setprecision(15);
        
        // Standard IEEE 754 floating-point result
        cout << "STD (Double): " << (double)d_acc << endl;
        
        cout << "-----------------------------------" << endl;
        
        // NPAt Core result showing mantissa stability and precision
        cout << "NPAt (Core):  " << convertNPAtToDecimal(acc) << endl;
    }
    
    return 0;
}
