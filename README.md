# Writing-Style-Analyzer
This program reads a report (running text) and issues warnings on style and partially correct bad style.
A statistical summary with the following information:
- Total number of words in the report
- Number of unique words
- Number of unique words of more than three letters
- Average word length 
- Average sentence length
- An index (alphabetical listing) of all the unique words

Issues a warning in the following cases:
- Word used too often: lists each unique word of more than three letters if its usage is more than 5% of the total number of words of more than three letters.
- Sentence length: writes a warning message if the average sentence length is greater than 10.
- Word length: writes a warning message if the average word length is greater than 5.

Data Structures
A Binary Search Tree of unique words in the report, created as the file is read. If a word is not in the list, puts it there. If it is, increments a counter showing how many times the word has been used.

Input
From the keyboard:  The name of the file containing the text to be analyzed.
From the file:  The report to be analyzed. 

Output
The name of the input file
The statistical summary of the report
The style warnings
