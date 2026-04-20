class Solution {
    public int maxDistance(int[] colors) {
        final int n = colors.length, colorStart = colors[0], colorEnd = colors[n - 1];
        int lMaxi = 0, rMaxi = 0;
        for (int i = 0; i < n; i++){
            if (colorStart != colors[i]) lMaxi = i;
            if (colorEnd != colors[i]) rMaxi = Math.max(rMaxi, n - 1 - i);
        }
        return Math.max(rMaxi, lMaxi);
    }
}
