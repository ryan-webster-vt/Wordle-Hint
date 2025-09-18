# Wordle Hint Finder

This project is a simple C program that helps solve **Wordle**-style puzzles.  
Given a **guess word** and a **hint pattern**, it scans through a word list and prints all possible hidden words that match the hint.

---

## How It Works

- The program compares each word in a provided word list against a given guess and hint.  
- Hints are encoded as:
  - `g` → correct letter in the correct spot (green)  
  - `y` → correct letter in the wrong spot (yellow)  
  - `r` → incorrect letter (gray)  
- Matching words are printed to an output text file. If none are found, it reports: "No possible hidden words found."

## Build Locally

- Clone Repository
```bash
git clone https://github.com/ryan-webster-vt/wordle-hint.git
cd wordle-hint
```

- Run Executable
```bash
cat words.txt | ./possible <guess> <hint> > output.txt
```
## Using Docker

- Execute Dockerfile
```
docker build -t wordle-hint .
```

- Run Program
```
cat words.txt | docker run -i --rm wordle-hint ./possible <guess word> <hint> > output.txt
```

