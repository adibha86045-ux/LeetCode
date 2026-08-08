class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int length1 = ax2 - ax1;
    int height1 = ay2 - ay1;
    int area1 = length1 * height1;
    int length2 = bx2 - bx1;
    int height2 = by2 - by1;
    int area2 = length2 * height2;
    int overlapLeft = max(ax1, bx1);
    int overlapRight = min(ax2, bx2);
    int overlapBottom = max(ay1, by1);
    int overlapTop = min(ay2, by2);
    int overlapArea = 0;
    if (overlapLeft < overlapRight && overlapBottom < overlapTop) {
        int overlapLength = overlapRight - overlapLeft;
        int overlapHeight = overlapTop - overlapBottom;
        overlapArea = overlapLength * overlapHeight;
    }
    int totalArea = area1 + area2 - overlapArea;
    return totalArea;  
    }
};