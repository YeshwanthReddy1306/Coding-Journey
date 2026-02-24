class Solution(object):
    def groupAnagrams(self, strs):
        anagram_map = {}

        for word in strs:
            # Sort the word to use as key
            key = ''.join(sorted(word))

            if key not in anagram_map:
                anagram_map[key] = []

            anagram_map[key].append(word)

        return list(anagram_map.values())