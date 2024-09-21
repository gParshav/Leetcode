One thing I couldn't understand was that I could access word1[n1]. It was giving empty space.
This probably explains why was it giving memory limit exceeded in some cases. A very big amount of space has somehow been allocated to these strings.

Logic:
How do you convert string1 to string2?
- You have to keep the LCS intact. Don't touch that.
- Remove everything from word1 that doesn't fall in the LCS.(ans+=n1-LCS)
- Add everything to word1, that is in word2 and not in the LCS.(ans+=n2-LCS)

ans = n1+n2-2*LCS