<h2><a href="https://leetcode.com/problems/longest-valid-parentheses">32. Longest Valid Parentheses</a></h2><h3>Hard</h3><hr><p>Given a string containing just the characters <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code>, return <em>the length of the longest valid (well-formed) parentheses </em><span data-keyword="substring-nonempty"><em>substring</em></span>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(()&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest valid parentheses substring is &quot;()&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;)()())&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest valid parentheses substring is &quot;()()&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;&quot;
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s[i]</code> is <code>&#39;(&#39;</code>, or <code>&#39;)&#39;</code>.</li>
</ul>

Correct approach — two passes
You can solve it exactly in the way you suggested:
1. Left → Right
2. Right → Left
3. Keep open and close counts.
4. Whenever they are equal, update ans.
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;

        // Left to Right
        int open = 0, close = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                ans = max(ans, 2 * close);
            }
            else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        // Right to Left
        open = 0;
        close = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                ans = max(ans, 2 * open);
            }
            else if (open > close) {
                open = 0;
                close = 0;
            }
        }

        return ans;
    }
};

Why do we need both directions?
Consider:
s = "(()"

Left → Right:
(   (   )
1   2   1    ← open
0   0   1    ← close

We never get open == close, so the answer appears to be 0.
But there is a valid substring:
"()"

of length 2.
The Right → Left scan catches it.
Similarly, there are cases where the left-to-right scan finds the answer but the right-to-left scan is necessary to handle the opposite imbalance.
Important rule to remember
For Left → Right:
if (close > open)
    reset;

Because:
)))(
^^^

has too many closing brackets.
For Right → Left:
if (open > close)
    reset;

Because when scanning backwards, too many opening brackets are invalid.
Complexity
Time:  O(n)
Space: O(1)

This is one of the standard O(n), O(1) solutions for LeetCode 32.
Your original start + open idea is trying to achieve the same thing, but the two-counter approach is much safer and easier to reason about.






    








Today 9:36 AM
take a example and try run it





 






Sure. Let's dry run the exact two-pass approach with a good example:
s = ")()())"

The correct answer is 4, because:
) ( ) ( ) )
  └─────┘
   ()()

1. Left → Right
We maintain:
open
close
ans

Initially:
open = 0
close = 0
ans = 0

i	char	open	close	What happens	ans
0	)	0	1	close > open → reset	0
1	(	1	0	continue	0
2	)	1	1	equal → 2	2
3	(	2	1	continue	2
4	)	2	2	equal → 4	4
5	)	2	3	close > open → reset	4


So after the first pass:
ans = 4

The substring we found is:
()()

2. Why do we need Right → Left?
Consider:
s = "(()"

Left → Right
i	char	open	close	ans
0	(	1	0	0
1	(	2	0	0
2	)	2	1	0


We never get:
open == close

So left → right gives:
ans = 0

But obviously:
(())

Actually the valid substring is:
()

length 2.
So we scan from right → left.
3. Right → Left for "(()"
Start:
open = 0
close = 0
ans = 0

We scan:
( ( )
↑

i = 2
Character:
)

So:
close++

Now:
open = 0
close = 1

No equality.
i = 1
Character:
(

So:
open++

Now:
open = 1
close = 1

Equal!
Therefore:
ans = max(ans, 2 * open);

ans = max(0, 2)
ans = 2

We found:
()

i = 0
Character:
(

Now:
open = 2
close = 1

Since:
open > close

reset:
open = 0
close = 0

Final:
ans = 2

The important idea
Think of the two passes like this:
Left → Right
We detect:
too many )

So:
if (close > open)
    reset;

Right → Left
We detect:
too many (

So:
if (open > close)
    reset;

Together, they handle both types of imbalance.
So the complete logic is:
for (int i = 0; i < n; i++) {

    if (s[i] == '(')
        open++;
    else
        close++;

    if (open == close)
        ans = max(ans, 2 * close);

    else if (close > open) {
        open = 0;
        close = 0;
    }
}

Then reverse:
for (int i = n - 1; i >= 0; i--) {

    if (s[i] == '(')
        open++;
    else
        close++;

    if (open == close)
        ans = max(ans, 2 * open);

    else if (open > close) {
        open = 0;
        close = 0;
    }
}

This is why one pass isn't enough, and two opposite-direction passes solve the problem in O(n) time and O(1) space.
