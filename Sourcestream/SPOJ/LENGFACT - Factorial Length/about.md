# Factorial Length

The solution is a direct application of **Stirling's approximation** for factorials. Here's an overview (credits: wikipedia):
> In mathematics, Stirling's approximation (or Stirling's formula) is an approximation for factorials. It is a good approximation, leading to accurate results even for small values of n.

<p align="center">
  <img width="500" height="200" src="https://wikimedia.org/api/rest_v1/media/math/render/svg/7fe20ccef4b13b2fc2b79b752fb595da6d855de2">
</p>

Kamenetsky's formula is based on this very approximation, to estimate the number of digits in the factorial of a number. In general, the number of digits 
in a number, say **d**, is given by **floor(log<sub>10</sub>(d)) + 1**. We can indeed use it to compute the same for **n!** as **log<sub>10</sub>(1 * 2 * ... * (n - 1) * n)** expands to 
**log<sub>10</sub>(1) + log<sub>10</sub>(2) + ... + log<sub>10</sub>(n)**. The computation, as can be seen, will take time of the order linear in **n**. **The trick Kamenetsky uses is:** taking the
logarithm of the approximation directly!
