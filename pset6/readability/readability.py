inText = input("Text: ")
end = ['.', '!', '?']

letters = sum(c.isalpha() for c in inText)
words = 1 + sum(c.isspace() for c in inText)
sentences = sum((c in end) for c in inText)

L = (100 / words) * letters
S = (100 / words) * sentences
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >=1 and index < 16:
    print(f"Grade {index}")
else:
    print("Grade 16+")