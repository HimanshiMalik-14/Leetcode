class Solution {
    public int myAtoi(String s) {
        int idx = 0, n = s.length();
        int sign = 1, res = 0;

        while (idx < n && s.charAt(idx) == ' ') {
            idx++;
        }

        if (idx < n && (s.charAt(idx) == '+' || s.charAt(idx) == '-')) {
            sign = (s.charAt(idx) == '-') ? -1 : 1;
            idx++;
        }

        while (idx < n && Character.isDigit(s.charAt(idx))) {
            int digit = s.charAt(idx) - '0';

            if (res > (Integer.MAX_VALUE - digit) / 10) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            res = res * 10 + digit;
            idx++;
        }

        return res * sign;
    }
}