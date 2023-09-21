class Solution {
    int[] piles;
    private int recHelper(int M, int idx, boolean aliceTurn) {
        // If all the piles have been used, res will always be 0
        if (idx == piles.length) {
            return 0;
        }
        int currSum = 0;
        // res corresponds to the maximum (on Alice's turn) or minimum (on Bob's turn) points that Alice can make given M and idx
        // Must be initialized to 0 on Alice's turn (to go up) and max on Bob's turn (to go down)
        int res = (aliceTurn ? 0 : Integer.MAX_VALUE);
        for (int i = 0; i < 2 * M; i++) {
            if (idx + i >= piles.length) {
                break;
            }
            currSum += piles[idx + i];
            if (aliceTurn) {    // Alice's turn -- maximize her points
                res = Math.max(res, currSum + recHelper(Math.max(M, i + 1), idx + i + 1, false));
            }
            else {  // Bob's turn -- minimize Alice's points
                res = Math.min(res, recHelper(Math.max(M, i + 1), idx + i + 1, true));
            }
        }
        return res;
    }
    public int stoneGameII(int[] piles) {
        this.piles = piles;
        return recHelper(1, 0, true);
    }
    public static void main(String args[]) {
        System.out.println(new Solution().stoneGameII(new int[]{2,7,9,4,4}));
    }
}