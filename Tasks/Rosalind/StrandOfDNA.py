'''
Complementing a Strand of DNA

Problem

In DNA strings, symbols 'A' and 'T' are complements of each other, as are 'C' and 'G'.

The reverse complement of a DNA string s is the string sc formed by reversing the symbols of s, then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC").

Sample Dataset: AAAACCCGGT
Sample Output: ACCGGGTTTT
'''
# Solution
dna = 'AAAACCCGGT'
new = ''
for i in dna:    
    if i == 'A':
        new += 'T'
    elif i == 'T':
        new += 'A'
    elif i == 'C':
        new += 'G'
    elif i == 'G':
        new += 'C'
    else:
        new += i    
print new[::-1]

# Another
from string import maketrans
print(dna[::-1].translate(maketrans('ACGT', 'TGCA')))

# Another
input = "AAAACCCGGT"
complement = { "A" : "T", "T" : "A", "C" : "G", "G" : "C"}
result = [] 
for i in reversed(input): 
    result.append(complement[i])
print ''.join(result)

# Another
string = dna
string = string[::-1] #reverse string
string = string.replace("A", "t")
string = string.replace("C", "g")
string = string.replace("T", "a")
string = string.replace("G", "c")
print string.upper()
