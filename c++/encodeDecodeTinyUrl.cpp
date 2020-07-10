// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
    map<string, string> url_mapper;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        time_t curr_time = time(0);
        string mapped_url = to_string(curr_time);
        string res = "http://tinyurl.com/" + mapped_url;
        url_mapper.insert({res, longUrl});
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (url_mapper.find(shortUrl) == url_mapper.end())
            return "";
        
        return url_mapper[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));