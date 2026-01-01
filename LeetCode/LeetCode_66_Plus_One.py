class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:

        # reverse the list
        def rev(l):
            n = len(l)
            for i in range(n // 2):
                digits[i], digits[n - 1 - i] = digits[n - 1 - i], digits[i]

        # reverse the list and add one
        rev(digits)

        n = len(digits)
        rem = 0
        # add 1
        digits[0] += 1

        # keep adding the rem to it
        for i in range(n):
            val = digits[i] + rem
            digits[i] = (val) % 10
            rem = val // 10

        # if still the remender remains then append it
        if rem:
            digits.append(rem)

        # undo the reverse for final output
        rev(digits)

        return digits


solution = Solution()
print(solution.plusOne([1, 2, 3]))  # Output: [1
