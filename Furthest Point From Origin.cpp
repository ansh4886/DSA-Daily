class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        final int n = moves.length();
        int l = 0, r = 0, blank = 0;
        for (int i = 0; i < n; i++) {
            char ch = moves.charAt(i);
            l += ch == 'L' ? 1 : 0;
            r += ch == 'R' ? 1 : 0;
            blank += ch == '_' ? 1 : 0;
        }
        return Math.max(l + blank - r, r + blank - l);
    }
}
