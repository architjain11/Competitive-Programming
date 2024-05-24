public class Solution {
    private int backtrack(String[] words, int[] score, int[] letterCounts, int[] availableLetters, int index, int currentScore, int maxScore) {
        for (int i = 0; i < 26; i++) {
            if (letterCounts[i] > availableLetters[i])
                return maxScore;
        }

        maxScore = Math.max(maxScore, currentScore);

        for (int i = index; i < words.length; i++) {
            for (char c : words[i].toCharArray()) {
                letterCounts[c - 'a']++;
                currentScore += score[c - 'a'];
            }

            maxScore = backtrack(words, score, letterCounts, availableLetters, i + 1, currentScore, maxScore);

            for (char c : words[i].toCharArray()) {  
                letterCounts[c - 'a']--;
                currentScore -= score[c - 'a'];
            }
        }

        return maxScore;
    }
    
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] letterCounts = new int[26];
        int[] availableLetters = new int[26];

        for (char c : letters)
            availableLetters[c - 'a']++;

        int maxScore = 0;
        maxScore = backtrack(words, score, letterCounts, availableLetters, 0, 0, maxScore);
        return maxScore;
    }
}
