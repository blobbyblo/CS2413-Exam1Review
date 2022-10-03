### 1. Big O Notation

The Big O Notation is used to describe the behavior of a function when its inputs approaches infinity.

### 2. Big O Terms of a Formula

Pick out the fastest-growing term and remove its constant coefficients.

![bigoformula](/images/bigoformula.png)

### 3. Comparing Big O

Compare by saying n is any nonnegative integer as it approaches infinity.

The higher, the worse (or more complex in terms of time or space)

![comparingbigo](/images/bigocompare.png)

### 4. Difference between Time/Space Complexity and Exact Time/Space

The time or space complexity can be represented by the Big O Notation as previously mentioned. However, the Big O Notation does not represent the exact time or space a program takes. For example (see below), with linear search, the exact time is `n*(T2+T2+T3)+T4+T1` while the Big O Notation only represents the fastest-growing term.

![exactvsbigo](/images/exactvsbigo.png)
