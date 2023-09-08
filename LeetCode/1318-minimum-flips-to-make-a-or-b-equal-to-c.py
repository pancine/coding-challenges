class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        a_string = str(bin(a)[2:])
        b_string = str(bin(b)[2:])
        c_string = str(bin(c)[2:])

        max_len = max(len(a_string), len(b_string), len(c_string))

        while len(a_string) < max_len:
            a_string = '0' + a_string
        while len(b_string) < max_len:
            b_string = '0' + b_string
        while len(c_string) < max_len:
            c_string = '0' + c_string

        result = 0
        for i in range(max_len):
            if a_string[i] + b_string[i] + c_string[i] != "111":
                result += abs(int(a_string[i]) + int(b_string[i]) - int(c_string[i]))

        return result