//solving it by dp
/*
	The number of ways to decode a string of length l will be equal to number of ways to decode the string of length l - 1 (excluding last character from it) if last character is in the range 1 to 9
	plus
	number of ways to decode the strong of length l - 2, if the last two characters form a number in the range 10 - 26
	Take an auxiliarry array dp of size n + 1
	dp[0] empty string will have 1 ways to decode
	dp[1] will be dependent on s[0], if s[0] == '0' ? dp[1] = 0 : dp[1] = 1
	now run the loop from 2 to s.length to fill values of dp from index 2 to n;
	if the character at i - 1 is form an integer in range 1 -> 9 add the value of dp[i-1] to dp[i]
	if the characters at i - 2 + i -1 form an integer in range 10 to 26, then add value of dp[i - 2] to dp[i];
	return value of dp[n]

	can optimize the space, as we need last two values to calculate dp[i]

*/
#include <string>

class Solution {
public:
	int numDecodings(string s) {
		if(s.length() == 0) return 0;

		int prev, prev_prev = 1;
		prev = s[0] != '0' ? 1 : 0;
		int ans = prev;
		for(int i = 2; i <= s.length(); i++) {
			ans = 0;
			int first = stoi(s.substr(i - 1, 1));
			int second = stoi(s.substr(i-2, 2));
			if(first >= 1 && first <= 9) ans += prev;
			if(second >= 10 &&  second <= 26) ans += prev_prev;
			prev_prev = prev;
			prev = ans;
		}

		return ans;
	}
}