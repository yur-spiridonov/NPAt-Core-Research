# NPAt Core: A New Paradigm in Binary Arithmetic

**Status: U.S. Patent Pending (USPTO № 19/254,239)**

📄 [Download Technical Presentation (PDF)](NPAt_Core_Numerical_Integrity_Presentation.pdf)

---

## 🚀 The Mission

NPAt (Number with Point After t) is a new numerical format and computational paradigm that enables full floating-point arithmetic — summation, and in future development multiplication, division and beyond — on any processor, **without a dedicated hardware FPU**.

This means 100% portability: identical, verified results on any platform, from high-performance servers to embedded controllers and autonomous AI devices. This is precisely the portability goal for which IEEE 754 was originally created — now achievable entirely in software.

---

## 🛠 Key Technical Advantages

**FPU-Free Execution.** NPAt performs floating-point computations using only 64-bit integer ALU instructions. No FPU required — eliminating a costly and power-hungry hardware block from the design.

**Verified Performance.** NPAt Pathway 1 — the first algorithm built on the NPAt format — runs **×2.12 faster than hardware FPU** on subnormal inputs, and **×1.46–2.26×** across a wide range of input types. This is measured against native hardware `ADDSD`, not software emulation.

**Bit-Exact IEEE 754 Compatibility.** Results are bit-for-bit identical to IEEE 754 `double`, verified to 50 decimal places over 10⁹ iterations. All existing software can be migrated to FPU-free processors without modification.

**No Subnormal Numbers.** The NPAt format has no concept of subnormal numbers — eliminating the need for special handling and the associated performance penalty on hardware FPU.

**Explicit Exact Zero.** NPAt introduces explicit exact zero, resolving ambiguities in IEEE 754 signed zero semantics (±0).

**User-Controlled Precision.** The precision parameter `t` is set by the user and does not affect the computation algorithm — enabling easy adaptation to different precision requirements on the same hardware.

---

## 📊 Verified Benchmark Results

| Input Type | HW cycles/iter | NPAt cycles/iter | Speedup |
|---|:---:|:---:|:---:|
| Subnormal (−9.999e−311) | 5.2147 | 2.4553 | **×2.12** |
| Normal fractional (0.125 / 0.625) | 5.2580 | 2.3242 | **×2.26** |
| Large integers (e+06 / e+09) | 5.4411 | 2.5621 | **×2.12** |
| Extreme magnitude (e+200) | 5.2394 | 2.6708 | **×1.96** |
| Small normal, subtraction | 5.4773 | 3.7429 | **×1.46** |

All tests: Z = 1,000,000,000 iterations · MSVC /O2 · Windows 11 · Core 0 · REALTIME_PRIORITY_CLASS

🔬 **Full benchmark source and results:**
[github.com/yur-spiridonov/Benchmark_Hardware-vs-NPAt-](https://github.com/yur-spiridonov/Benchmark_Hardware-vs-NPAt-)

---

## 💡 Two Implementation Pathways

**Pathway 1 — Bit-for-Bit IEEE 754 Compatibility** *(proprietary, closed source)*
An algorithm that produces results identical to IEEE 754 `double`, but executes on the integer ALU faster than hardware FPU. Enables direct migration of existing software to FPU-free processors.

**NPAt Core Strategy — NPAt_Demo** *(available in this repository)*
A native NPAt algorithm that exceeds IEEE 754 in precision and simplicity. Uses a 64-bit mantissa for high-precision iterative calculations.

---

## 🔬 Theoretical Foundation

The NPAt format is based on the representation of any number X as:

```
X̂ = S · K̂ · β^q
```

Where S is the sign, K̂ is an integer mantissa, and q is the rounding coefficient (RC). All parameters are integers — enabling all computations in two's complement integer arithmetic.

Key properties:
- No normalization required during summation
- No subnormal numbers
- Explicit exact zero
- Monotonically increasing sequence from minimum to maximum representable value
- Precision parameter `t` independent of the computation algorithm

📄 [Full theoretical paper](https://github.com/yur-spiridonov/PresentationNPat)

---

## 📥 Quick Start

### For Users (Demo)
1. Download [NPAt_Demo.exe](NPAt_Demo.exe)
2. Run the application to compare NPAt precision stability against IEEE 754

> **Note:** If Windows displays a security warning, click "More info" → "Run anyway". This is standard for independent research tools without commercial code signing.

### For Developers (Integration)
1. Add `main.cpp` and `NPAt_Interface.h` to your project
2. Link `NPAt_Core.lib` (Visual Studio: Project Properties → Linker → Input → Additional Dependencies)
3. Set configuration to `Release | x64` and build

---

## 🗂 Related Repositories

| Repository | Description |
|---|---|
| [Benchmark_Hardware-vs-NPAt-](https://github.com/yur-spiridonov/Benchmark_Hardware-vs-NPAt-) | Hardware IEEE 754 baseline benchmark — open source, independently reproducible |
| [PresentationNPat](https://github.com/yur-spiridonov/PresentationNPat) | Early results: NPAt vs IEEE 754 across 7 input types |

---

## 📜 Intellectual Property & Research

- **U.S. Patent Pending (USPTO № 19/254,239):** APPARATUS FOR ITERATIVELY SUMMING BINARY EQUIVALENTS OF DECIMAL NUMBERS
- **TechRxiv Preprints:** Published research on decimal-to-binary equivalence and computational stability

---

## 👤 About the Author

**Iouri Spiridonov** · Independent Researcher · Newmarket, ON, Canada

- Former Head of Laboratory at NPO "Agat"
- USSR State Prize Laureate · Medal for Labor Distinction
- Holder of 18 Invention Certificates and 2 patents in digital architecture and computational systems
- Over 20 years of R&D in digital systems, hardware-software integration and numerical algorithms

---

*Internal algorithms and mantissa alignment logic of NPAt Pathway 1 are proprietary. All IP rights reserved. NDA available upon request.*
