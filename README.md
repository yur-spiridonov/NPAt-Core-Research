# NPAt Research Suite (Numerical Precision Atomic) v3.2

**EN:** A high-precision computational core designed to mitigate precision loss in iterative processes and extreme scales ($10^{\pm300}$).
**RU:** Вычислительное ядро повышенной точности для минимизации ошибок накопления в итерационных циклах и работы на экстремальных порядках ($10^{\pm300}$).

---

### 🚀 Key Features 
* **64-bit Mantissa:** Outperforms standard `double` (53-bit) by providing up to 19 significant digits.
* **Integrity Flag (q):** Real-time tracking of precision loss during mantissa alignment.
* **Scale Stability:** Reliable performance where standard double-precision types begin to produce "digital noise".

### 🧪 Performance Benchmark: The "Hard-Test"
We test by summing `0.1` one million times using `volatile` variables to prevent compiler optimization shortcuts.
- **Standard Double:** Cumulative error becomes visible at the 11th decimal place.
- **NPAt Core:** Maintains precision 10,000x more effectively, as demonstrated in the demo suite.

### 📦 Repository Structure
- `main.cpp`: Open-source demonstration suite (Hard-Test implementation).
- `NPAt_Interface.h`: Public API header.
- `NPAt_Core.lib`: Proprietary pre-compiled high-precision core (x64).

---
🛠 How to Run 
EN: To run this demo, you need Visual Studio 2022 (Windows, x64).

Create a new C++ Console App project.

Add main.cpp and NPAt_Interface.h to the project.

Place NPAt_Core.lib in the project folder.

Go to Project Properties -> Linker -> Input -> Additional Dependencies and add NPAt_Core.lib.

Set the configuration to Release | x64 and press Ctrl+F5.
---
*Developed for research purposes. Internal algorithms and mantissa alignment logic are proprietary.*
