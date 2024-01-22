class Solution {
public:
    void getlps(vector<int>& lps, string& pat, int& m) {
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }

    vector<int> beautifulIndices(string txt, string pat1, string pat2, int k) {
        int n = txt.size();
        int m1 = pat1.size();
        int m2 = pat2.size();

        vector<int> lps1(m1, 0);
        vector<int> lps2(m2, 0);

        getlps(lps1, pat1, m1);
        getlps(lps2, pat2, m2);

        vector<int> pat1_in;
        vector<int> pat2_in;

        int i = 0;
        int j = 0;
        while (i < n) {
            if (j == m1) {
                pat1_in.push_back(i - j);
                j = lps1[j - 1];
            }

            if (txt[i] == pat1[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps1[j - 1];
                } else {
                    i++;
                }
            }
        }

        if (j == m1) {
            pat1_in.push_back(i - j);
        }

        i = 0;
        j = 0;
        while (i < n) {
            if (j == m2) {
                pat2_in.push_back(i - j);
                j = lps2[j - 1];
            }

            if (txt[i] == pat2[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps2[j - 1];
                } else {
                    i++;
                }
            }
        }

        if (j == m2) {
            pat2_in.push_back(i - j);
        }

        vector<int> ans;
        for (int i = 0; i < pat1_in.size(); i++) {
            // Binary search to find the range of elements in array b satisfying
            // the condition
            int low =
                lower_bound(pat2_in.begin(), pat2_in.end(), pat1_in[i] - k) -
                pat2_in.begin();
            int high =
                upper_bound(pat2_in.begin(), pat2_in.end(), pat1_in[i] + k) -
                pat2_in.begin();

            // Check if there are elements in the range
            if (low < high) {
                ans.push_back(pat1_in[i]);
            }
        }

        return ans;
    }
};
