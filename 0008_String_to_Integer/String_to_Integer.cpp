
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

        // Skip leading whitespaces
        while (i < s.length() && s[i] == ' ') i++;

        // Handle sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits and stop at first non-digit
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // Clamp result to 32-bit signed integer limits
            if (sign * result <= INT_MIN) return INT_MIN;
            if (sign * result >= INT_MAX) return INT_MAX;
            i++;
        }

        return (int)(sign * result);
    }
};
