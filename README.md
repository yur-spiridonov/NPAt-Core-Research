
# NPAt Core: A New Paradigm in Binary Arithmetic
**High-precision computational engine for iterative financial and scientific calculations.**

## 🚀 The Mission
Modern computing (IEEE 754) is prone to uncontrollable error accumulation in high-volume summation. **NPAt (Number with Point After t)** is a disruptive numerical format designed to ensure high precision, 9x faster performance, and hardware independence.

## 🛠 Key Technical Advantages
* **Precision over Double:** Prevents "money drift" in financial audits where standard `double` fails after millions of iterations.
* **FPU-Free:** Performs complex floating-point math on 8/16/32/64-bit integer ALUs. Ideal for **Edge AI**.
* **No Normalization:** Drastically simplifies summation logic by using pure integer bitwise operations.
* **Efficiency:** Up to **9 times faster** than software-emulated IEEE 754.

## 📜 Intellectual Property & Research
* **U.S. Patent Pending:** [USPTO № 19/254,239] – *Apparatus for iteratively summing binary equivalents of decimal numbers.*
* **TechRxiv Preprints:** Published research on decimal-to-binary equivalence and arithmetic stability.

## 📥 Quick Demo (Windows x64)
1.  Download [NPAt_Demo.exe](NPAt_Demo.exe).
2.  Run it (Click "Run anyway" if Windows SmartScreen appears).
3.  Test case: Step `0.1`, Iterations `1,000,000`. Watch NPAt maintain precision where IEEE 754 drifts.

For Developers:

Add main.cpp and NPAt_Interface.h to your project.

Place NPAt_Core.lib in the project folder.

Go to Project Properties -> Linker -> Input -> Additional Dependencies and add NPAt_Core.lib.

Set configuration to Release | x64 and press Ctrl+F5.
Set the configuration to Release | x64 and press Ctrl+F5.

---
## 👤 About the Author: Iouri Spiridonov
**Independent Researcher | Former Head of Laboratory at NPO "Agat"**
* **20+ years of R&D** in mission-critical digital systems.
* **USSR State Prize Laureate** & recipient of the Medal for Labor Distinction.
* Expert in numerical algorithms and high-reliability hardware-software integration.


---
*Developed for research purposes. Internal algorithms and mantissa alignment logic are proprietary.*
