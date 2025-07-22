class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;

        // Step 1: Initialize parent and owner maps
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); ++i) {
                parent[acc[i]] = acc[i]; // Initially, parent is self
                owner[acc[i]] = name;
            }
        }

        // Step 2: Union emails in same account
        for (auto& acc : accounts) {
            string root = find(acc[1], parent);
            for (int i = 2; i < acc.size(); ++i) {
                parent[find(acc[i], parent)] = root;
            }
        }

        // Step 3: Group emails by root
        unordered_map<string, set<string>> unions;
        for (auto& p : parent) {
            string root = find(p.first, parent);
            unions[root].insert(p.first);
        }

        // Step 4: Build result
        vector<vector<string>> res;
        for (auto& u : unions) {
            vector<string> emails(u.second.begin(), u.second.end());
            emails.insert(emails.begin(), owner[u.first]);
            res.push_back(emails);
        }

        return res;
    }

private:
    string find(string email, unordered_map<string, string>& parent) {
        if (parent[email] != email) {
            parent[email] = find(parent[email], parent); // Path compression
        }
        return parent[email];
    }
};
