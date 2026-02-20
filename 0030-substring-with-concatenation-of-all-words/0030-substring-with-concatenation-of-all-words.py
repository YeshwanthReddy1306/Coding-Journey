from collections import Counter

class Solution:
    def findSubstring(self, s, words):
        if not s or not words:
            return []

        word_len = len(words[0])
        total_words = len(words)
        word_count = Counter(words)
        result = []

        for i in range(word_len):
            left = i
            count = 0
            window = {}

            for right in range(i, len(s) - word_len + 1, word_len):
                word = s[right:right + word_len]

                if word in word_count:
                    window[word] = window.get(word, 0) + 1
                    count += 1

                    while window[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        window[left_word] -= 1
                        left += word_len
                        count -= 1

                    if count == total_words:
                        result.append(left)
                else:
                    window.clear()
                    count = 0
                    left = right + word_len

        return result