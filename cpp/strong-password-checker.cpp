420. Strong Password Checker Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 2302
Total Submissions: 11387
Difficulty: Hard
Contributors:
yduan7
A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.


The basic principle is straightforward: if we want to make MINIMUM changes to turn s into 
a strong password, each change made should fix as many problems as possible.

So to start, let's first identify all the problems in the input string s and list what changes
are suitable for righting each of them. To clarify, each change should be characterized by at 
least two parts: the type of operation it takes and the position in the string where the 
operation is applied (Note: Ideally we should also include the characters involved in the 
operation and the "power" of each operation for eliminating problems but they turn out to be 
partially relevant so I will mention them only when appropriate).

Length problem: if the total length is less than 6, the change that should be made is (insert, 
any position), which reads as "the operation is insertion and it can be applied to anywhere in 
the string". If the total length is greater than 20, then the change should be (delete, any 
position).

Missing letter or digit: if any of the lowercase/uppercase letters or digits is missing, we can 
do either (insert, any position) or (replace, any position) to correct it. (Note here the 
characters for insertion or replacement can only be those missing.)

Repeating characters: for repeating characters, all three operations are allowed but the 
positions where they can be applied are limited within the repeating characters. For example, 
to fix "aaaaa", we can do one replacement (replace the middle 'a') or two insertions (one after 
the second 'a' and one after the fourth 'a') or three deletions (delete any of the three 'a's). 
So the possible changes are (replace, repeating characters), (insert, repeating characters), 
(delete, repeating characters). (Note however the "power" of each operation for fixing the 
problem are different -- replacement is the strongest while deletion is the weakest.)

All right, what's next? If we want a change to eliminate as many problems as it can, it must be 
shared among the possible solutions to each problem it can fix. So our task is to find out 
possible overlapping among the changes for fixing each problem.

Since there are most (three) changes allowed for the third problem, we may start from 
combinations first problem & third problem and second problem & third problem. It's not too 
hard to conclude that any change that can fix the first or second problems is also able to fix 
the third one (since the type of operation here is irrelevant, we are free to choose the 
position of the operation to match those of the repeating characters). For combination first 
problem & second problem, depending on the length of the string, there will be overlapping if 
length is less than 6 or no overlapping if length is greater than 20.

From the analyses above, it seems worthwhile to distinguish between the two cases: when the 
input string is too short or too long.

For the former case, it can be shown that the total changes needed to fix the first and second 
problems always outnumber those for the third one. Since whatever change used fixing the first 
two problems can also correct the third one, we may concern ourselves with only the first two. 
Also as there is overlapping between the changes for fixing the first two problems, we will 
prefer those overlapping ones, i.e. (insert, any position). Another point is that the 
characters involved in the operation matters now. To fix the first problem, only those missing 
characters can be inserted while for the second condition, it can be any character. Therefore 
correcting the first problem takes precedence over the second one.

For the latter case, there is overlapping between the first & third and second & third 
problems, so those overlapping changes will be taken, i.e., first problem => (delete, any 
position), second problem => (replace, any position). The reason not to use (insert, any 
position) for the second problem is that it contradicts the changes made to the first problem 
(therefore has the tendency to cancel its effects). After fixing the first two problems, what 
operation(s) should we choose for the third one?

Now the "power" of each operation for eliminating problems comes into play. For the third 
problem, the "power" of each operation will be measured by the maximum number of repeating 
characters it is able to get rid of. For example, one replacement can eliminate at most 5 
repeating characters while insertion and deletion can do at most 4 and 3, respectively. In this 
case, we say replacement has more "power" than insertion or deletion. Intuitively the more 
"powerful" the operation is, the less number of changes is needed for correcting the problem. 
Therefore (replace, repeating characters) triumphs in terms of fixing the third problem.

Furthermore, another very interesting point shows up when the "power" of operation is taken 
into consideration (And thank yicui for pointing it out). As I mentioned that there is 
overlapping between changes made for fixing the first two problems and for the third one, which 
means the operations chosen above for the first two problems will also be applied to the third 
one. For the second problem with change chosen as (replace, any position), we have no problem 
adapting it so that it coincides with the optimal change (replace, repeating characters) made 
for the third problem. However, there is no way to do the same for the first problem with 
change (delete, any position). We have a conflict now!

How do we reconcile it? The trick is that for a sequence of repeating characters of length k (k 
>= 3), instead of turning it all the way into a sequence of length 2 (so as to fix the 
repeating character problem) by the change (delete, any position), we will first reduce its 
length to (3m + 2), where (3m + 2) is the largest integer of the form yet no more than k. That 
is to say, if k is a multiple of 3, we apply once such change so its length will become (k - 
1); else if k is a multiple of 3 plus 1, we apply twice such change to cut its length down to 
(k - 2), provided we have more such changes to spare (be careful here as we need at least two 
changes but the remaining available changes may be less than that, so we should stick to the 
smaller one: 2 or the remaining available changes). The reason is that the optimal change 
(replace, repeating characters) for the third problem will be most "powerful" when the total 
length of the repeating characters is of this form. Of course, if we still have more changes 
(delete, any position) to do after that, then we are free to turn the repeating sequence all 
the way into a sequence of length 2.


class Solution {
public:
    int strongPasswordChecker(string s) {
        int res=0, a=1, A=1, d=1, n=s.size();
        vector<int> v(n);
        for (int i=0; i<n; ) {
            if (islower(s[i])) a=0;
            if (isupper(s[i])) A=0;
            if (isdigit(s[i])) d=0;
            
            int j=i;
            while (j<n && s[j]==s[i]) j++;
            v[i]=j-i;
            i=j;
        }
        
        int miss=a+A+d;
        if (n<6) {
            res=miss+max(0, 6-(n+miss));
        } else {
            int over=max(n-20, 0), left=0;
            res+=over;
            
            for (int k=1; k<3; ++k) {
                for (int i=0; i<n && over>0; ++i) {
                    if (v[i]<3 || v[i]%3!=k-1) continue;
                    v[i]-=min(over, k);
                    over-=k;
                }
            }
            
            for (int i=0; i<n; ++i) {
                if (v[i]>=3 && over>0) {
                    int need=v[i]-2;
                    v[i]-=over;
                    over-=need;
                }
                
                if (v[i]>=3) left+=v[i]/3;
            }
            
            res+=max(miss, left);
        }
        return res;
    }
};

