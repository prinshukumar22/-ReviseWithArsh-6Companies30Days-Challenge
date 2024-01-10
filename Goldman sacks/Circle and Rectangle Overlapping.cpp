class Solution {
public:
    bool checkOverlap(int r, int xC, int yC, int x1, int y1, int x2, int y2) {
        int nearx = max(x1, min(xC, x2));
        int neary = max(y1, min(yC, y2));

        int a = abs(nearx - xC);
        int b = abs(neary - yC);

        int d = (a*a) + (b*b);

        if(d <= (r*r)) return true;
        return false;
    }
};
