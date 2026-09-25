class Solution {
private:
    int i = 0;
    using Set = unordered_set<string>;
    Set parseExpr(const string& s) {
        Set result = parseTerm(s);
        while (i < s.size() && s[i] == ',') {
            i++;
            Set next = parseTerm(s);
            result.insert(next.begin(), next.end());
        }
        return result;
    }
    Set parseTerm(const string& s) {
        Set result = {""};
        while (i < s.size() &&
               s[i] != ',' && s[i] != '}') {
            Set current;
            if (s[i] == '{') {
                i++;
                current = parseExpr(s);
                i++;
            }
            else {
                current.insert(string(1, s[i]));
                i++;
            }
            Set temp;
            for (const string& a : result) {
                for (const string& b : current) {
                    temp.insert(a + b);
                }
            }
            result = move(temp);
        }
        return result;
    }
public:
    vector<string> braceExpansionII(string expression) {
        i = 0;
        Set result = parseExpr(expression);
        vector<string> ans(result.begin(), result.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};