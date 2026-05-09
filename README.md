# NPAt Core: A New Paradigm in Binary Arithmetic

**Status: U.S. Patent Pending (USPTO № 19/254,239)**

---

## 🚀 The Mission

NPAt (Number with Point After t) is a new numerical format and computational paradigm that enables full floating-point arithmetic — summation, and in future development multiplication, division and beyond — on any processor, **without a dedicated hardware FPU**.

This means 100% portability: identical, verified results on any platform, from high-performance servers to embedded controllers and autonomous AI devices. This is precisely the portability goal for which IEEE 754 was originally created — now achievable entirely in software.

---

## 🛠 Key Technical Advantages

**FPU-Free Execution.** NPAt performs floating-point computations using only 64-bit integer ALU instructions. No FPU required — eliminating a costly and power-hungry hardware block from the design.

**Verified Performance.** NPAt-algorithm — the first algorithm built on the NPAt format — runs **×1.46–×2.26 faster than hardware FPU** across a wide range of input types. Performance is independent of the scale factor (exponent). This is measured against native hardware `ADDSD`, not software emulation.

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

---

## 💡 NPAt-algorithm *(open source)*

The core implementation is publicly available in the **[yur-spiridonov/NPAt_algorithm](https://github.com/yur-spiridonov/NPAt_algorithm)** repository. It contains two programs:

| File | Description |
|---|---|
| [npat_demo_precision.cpp](https://github.com/yur-spiridonov/NPAt_algorithm/blob/main/npat_demo_precision.cpp) | NPAt summation algorithm — demonstrates variable-precision computation at different values of `t` (from t=4 to t=53) |
| [npat_benchmark.cpp](https://github.com/yur-spiridonov/NPAt_algorithm/blob/main/npat_benchmark.cpp) | Performance benchmark — compares NPAt algorithm against native IEEE 754 hardware FPU (`ADDSD`) |

This algorithm produces results identical to IEEE 754 `double`, but executes on the integer ALU **×1.46–2.26× faster** than hardware FPU. Enables direct migration of existing software to FPU-free processors.

---

## 🗂 Related Repositories

| Repository | Description |
|---|---|
| [yur-spiridonov/NPAt_algorithm](https://github.com/yur-spiridonov/NPAt_algorithm) | **Open source** — NPAt summation algorithm and IEEE 754 benchmark |
| [Benchmark_Hardware-vs-NPAt-](https://github.com/yur-spiridonov/Benchmark_Hardware-vs-NPAt-) | Performance results: NPAt vs hardware IEEE 754 FPU — independently reproducible |
| [PresentationNPat](https://github.com/yur-spiridonov/PresentationNPat) | Precision comparison results: NPAt vs IEEE 754 across multiple input types |

---

## 📐 Theoretical Foundation

### An Alternative Algorithm for Summing Any Decimal Numbers in Binary Arithmetic

#### Abstract

We propose a new number format — NPAt — fully compatible with conventional finite arithmetic. The NPAt format enables computations of decimal floating-point numbers (represented in binary form) on an integer processor without an FPU. Computation results in NPAt are bit-identical to those obtained using the IEEE 754 binary standard.

NPAt defines two data types:
- **Numbers**, consisting of exact values, approximate values, and explicit zero
- **Non-numbers** (NaN)

The presence of explicit zero allows bitwise comparison across the entire floating-point range. NPAt forms a monotonically increasing sequence throughout the range from the minimum to the maximum possible values. It also allows representation of positive and negative numbers whose magnitudes are smaller than the minimum representable value — such numbers can be considered infinitesimal, but not equal to zero.

Parameters representing signed NPAt numbers are integers or zero, so all computations can be performed in two's complement code. When summing numbers in NPAt format, normalization is not required. The NPAt format has no concept of subnormal numbers, eliminating the need for special handling. Finally, the precision parameter in NPAt does not affect the computation algorithm.

---

#### Theoretical Foundations of NPAt

Any number X can be represented as an infinite integer K (0 ≤ K < ∞) of infinitesimal intervals ɛ. The interval ɛ can be a decimal ɛ₁₀ or binary ɛ₂ number, or in general a number in any number system.

For a finite decimal X, the equality holds: X = S·K₁₀·ɛ₁₀, where S = 1 or −1, K₁₀ and ɛ₁₀ are decimal numbers.

For a finite binary Y, the equality holds: Y = S·K₂·ɛ₂, where S = 1 or −1, K₂ and ɛ₂ are binary numbers.

As ɛ₁₀ → 0 and ɛ₂ → 0, K₁₀ → ∞ and K₂ → ∞, and then S·K₁₀·ɛ₁₀ = S·K₂·ɛ₂. That is, for any infinitely precise decimal X there exists a binary Y that is infinitely precisely equal to X.

Any finite decimal or binary K (except K = 0) contains a certain number j of significant digits. Significant digits are all non-zero digits in X, starting from the first non-zero one, and trailing zeros if the number is integer. For example, 0.00123 has three significant digits, 12300 has five significant digits.

---

#### Representation of a Number in Normalized Exponential Form

The form of recording any X in exponential form, in which the first non-zero significant digit follows the radix point, is called the normalized format (NF).

NF X is written as:
```
X = S · 0.K · β^e
```
where 0.K is the mantissa, K is an integer consisting of j significant digits, β is the number system base, e is the exponent determining the position of the radix point.

For example, for 0.001234: j = 4, K = 1234, NF X = 0.1234·10⁻².

For X in NF: β^(j−1) ≤ K < β^j − 1.

For X represented in NF, four areas are allocated in the operational register — S, p, s, w:
- One digit for the sign S
- p digits for K̃ (closest to K)
- One digit s for the sign of exponent e
- w digits for the exponent e

The maximum integer for the p-digit area: K̃_max = β^p − 1.
The maximum integer for the w-digit area: e_max = β^w − 1.

If K > K̃_max, it is necessary to round K to the closest K̃ with p significant digits. For example, if p = 2, for X = 0.1234·10⁻³ where K = 1234, after rounding K̃ = 12 and X̃ = 0.12·10⁻³.

---

#### NPAt Format

Assume we have NF X̃ = S·0.K̃·β^e, in which K̃ contains p digits. If the radix point is placed after the least-significant digit of the integer K̂, then to keep the value of X̃ unchanged, the exponent e must be decreased by p:

```
X̂ = S · K̂ · β^(e−p)
```

More generally, if the radix point is placed after digit number t ≤ p (counted from left to right):

```
X̂ = S · K̂ · β^(e−t)
```

Denoting q = (e − t):

```
X̂ = S · K̂ · β^q
```

Setting μ = β^q:

```
X̂ = S · K̂ · μ
```

The coefficient q is called the **rounding coefficient (RC)**. The number X̂ with integer K̂ is called a **number with point after t (NPAt)**.

In the operational register, four areas are allocated — S, p, s, w:
- **S** — sign of the number
- **t-area** — j digits of integer K̂ (0 ≤ j ≤ t), or zero
- **s** — sign of RC q
- **w** — RC q

If there were no losses of non-zero significant digits when rounding, NPAt is an **exact number** X̄. Exact numbers X̄ are a subset of NPAt X̂.

**Examples:**
- X = 0.0123 → NF: 0.123·10⁻¹ → t=2: q = −1−2 = −3, μ = 10⁻³ → **NPAt X̂ = 12·10⁻³**
- X = 12000 → NF: 0.120·10⁵ → t=2: q = 5−2 = 3, μ = 10³ → **NPAt X̄ = 12·10³** (exact)
- X = 2 → NF: 0.200·10¹ → t=3: q = 1−3 = −2, μ = 10⁻² → **NPAt X̄ = 200·10⁻² = 2** (exact)

---

#### Properties of NPAt and NF

**Subnormal numbers in NF.** In NF, if e < e_min and K̃ < 1 (K̃ ≠ 0), such NF is a subnormal number — at least one leading digit in K̃ is zero. Normalization of subnormal numbers leads to exponent register overflow, requiring special algorithms different from the main algorithm. This complicates hardware and software processing. In some applications, developers refuse to work with subnormal numbers entirely, narrowing the range of processed values.

**No subnormal numbers in NPAt.** The NPAt format has no concept of subnormal numbers. All values are handled uniformly by the same algorithm.

**Range.** For NPAt X̂, the RC q takes any value in −W ≤ q < W, where W = β^w − 1. Since q = e − t:
```
−(e_max + t) ≤ q ≤ e_max − t
```
The values of RC q set the position of the radix point in NPAt X̂ relative to NF X̃ shifted t digits to the left.

---

#### Explicit Exact Zero and Signed Zero

In IEEE 754, if e < e_min and K̃ = 0, such X̃ is taken as ±0. The standard lacks representation of explicit exact zero. This leads to ambiguity — for example: 1/+0 and 1/−0. If +0 and −0 are not equal to exact zero, then 1/+0 = +∞ and 1/−0 = −∞. At the same time, for exact zero: 1/0 = NaN.

In NPAt, explicit exact zero is obtained when subtracting equal exact numbers X̄:
- If during calculations with exact values X̄ we obtain K̄ = 0 → X̄ is **exactly equal to zero**
- If at least one operand is inexact, the obtained X̂ with K̂ = 0 is an **infinitely small number** (positive +0 or negative −0)

By their nature, signed zeros in IEEE 754 are positive (+0) and negative (−0) infinitely small numbers.

In NPAt there is no ambiguity:
```
a / +0 = +∞
a / −0 = −∞
a / 0  = NaN   (where a ≠ 0)
```

---

#### Comparison of Summation Results (Table 1)

β = 10, t = 2, W = 3

| # | X̃₁ | X̃₂ | X̃₁ + X̃₂ | X̂₁ | X̂₂ | X̂₁ + X̂₂ |
|---|---|---|---|---|---|---|
| 1 | 0.23·10⁻¹ | 0.01·10⁻¹ | 0.24·10⁻¹ | 23·10⁻³ | 1.2·10⁻³ | 24·10⁻³ |
| 2 | 0.12·10³ | 0.23·10³ | 0.35·10³ | 12·10¹ | 23·10¹ | 35·10¹ |
| 3 | 0.12·10⁻¹ | −0.12·10⁻¹ | (+0) | X̄₁=12·10⁻³ | X̄₂=−12·10⁻³ | **0** (exact) |
| 4 | 0.23·10² | −0.22·10² | 0.10·10¹ | 23·10⁰ | −22·10⁰ | 1·10⁰ |
| 5 | 0.12·10⁵(+∞) | 0.23·10³ | (+∞) | 12·10³ | 0.00·10³ | 12·10³ |
| 6 | 0.12·10⁻³ | 0.23·10⁻³ | 0.35·10⁻³ | (+0) | (+0) | (+0) |
| 7 | 0.12·10⁶(+∞) | 0.23·10³ | (+∞) | (+∞) | 0.0023·10³ | (+∞) |

Key observations:
- **Row 3:** subtracting identical exact numbers gives **explicit exact zero** in NPAt — unambiguous, unlike IEEE 754 (+0)
- **Row 5:** when one addend exceeds register capacity in NF (+∞), NPAt computes the correct finite result (12·10³)
- **Row 6:** numbers too small for the register become infinitely small (+0) in both formats
- **Row 7:** if one addend is infinitely large (+∞), the sum is (+∞) in both formats

---

#### Summary

1. Any normalized floating-point number X = S·0.K·β^e can be approximately represented as NPAt X̂ = S·K̂·μ, or exact X̄ = S·K̄·μ, where X̄ is a subset of NPAt X̂
2. K̂ and K̄ are integers in the interval from 0 to K̂_max, defining a monotonically increasing function from X̂_min to X̂_max
3. NPAt has two data types: numbers (approximate X̂ and exact X̄) and non-numbers (NaN)
4. All parameters (S, K, s, q) are integers — all computations in two's complement code
5. If in exact number X̄ = S·K̄·μ we have K = 0, then X̄ = 0 is an explicit exact zero
6. Explicit exact zero enables bitwise number comparison in computational algorithms
7. Explicit exact zero enables the concepts of minus (−0) and plus (+0) infinitely small numbers
8. No normalization required during summation — the fractional part goes beyond the register grid and K is rounded to the nearest integer
9. Computation precision t is set by the user and does not affect the computation algorithm
10. No concept of subnormal number — no special means required for such numbers
11. Simple implementation on CPU yields results identical to FPU
12. The demonstration algorithm shows how to implement summation of arbitrary signed numbers in NPAt format on an integer processor, with results bit-identical to float or double

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

*NPAt-algorithm is open source — see [yur-spiridonov/NPAt_algorithm](https://github.com/yur-spiridonov/NPAt_algorithm). NPAt Core Strategy is in development. All IP rights reserved. NDA available upon request.*
