// https://leetcode.com/problems/encode-and-decode-tinyurl

class Solution {
    unordered_map<size_t, string> urls;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t result = hash<string>()(longUrl);
        urls[result] = longUrl;
        return to_string(result);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[stoul(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));