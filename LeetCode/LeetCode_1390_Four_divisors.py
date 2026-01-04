class Solution:
    def sumFourDivisors(self, nums: list[int]) -> int:
        # def count_divisors(n):
        #     if n <= 0: return 0
        #     if n == 1: return 1

        #     total_divisors = 1

        #     count = 0
        #     while n % 2 == 0:
        #         count += 1
        #         n //= 2
        #     total_divisors *= (count + 1)

        #     count = 0
        #     while n % 3 == 0:
        #         count += 1
        #         n //= 3
        #     total_divisors *= (count + 1)

        #     i = 5
        #     while i * i <= n:
        #         # Check i
        #         if n % i == 0:
        #             count = 0
        #             while n % i == 0:
        #                 count += 1
        #                 n //= i
        #             total_divisors *= (count + 1)

        #         j = i + 2
        #         if n % j == 0:
        #             count = 0
        #             while n % j == 0:
        #                 count += 1
        #                 n //= j
        #             total_divisors *= (count + 1)

        #         i += 6

        #     if n > 1:
        #         total_divisors *= 2

        #     return total_divisors
        def get_divisors_stats(n):

            if n <= 0:
                return (0, 0)
            if n == 1:
                return (1, 1)

            total_count = 1
            total_sum = 1

            def process_factor(n, p):
                count = 0
                while n % p == 0:
                    count += 1
                    n //= p

                total_count_update = count + 1

                # Update Sum: multiply by (p^(exponent+1) - 1) // (p - 1)
                # We use pow(base, exp) for speed
                total_sum_update = (pow(p, count + 1) - 1) // (p - 1)

                return n, total_count_update, total_sum_update

            if n % 2 == 0:
                n, c_up, s_up = process_factor(n, 2)
                total_count *= c_up
                total_sum *= s_up
            if n % 3 == 0:
                n, c_up, s_up = process_factor(n, 3)
                total_count *= c_up
                total_sum *= s_up
            i = 5
            while i * i <= n:
                if n % i == 0:
                    n, c_up, s_up = process_factor(n, i)
                    total_count *= c_up
                    total_sum *= s_up

                j = i + 2
                if n % j == 0:
                    n, c_up, s_up = process_factor(n, j)
                    total_count *= c_up
                    total_sum *= s_up

                i += 6

            # 4. If n > 1, the remainder is a prime number itself
            if n > 1:
                total_count *= 2  # Exponent is 1, so (1+1) = 2
                total_sum *= n + 1  # Sum of divisors for a prime p is (p+1)

            return (total_count, total_sum)

        total_total = 0
        for num in nums:
            total, val = get_divisors_stats(num)
            if total == 4:
                total_total += val
        return total_total
