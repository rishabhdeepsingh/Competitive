package FastIO;

import java.util.Arrays;
import java.util.Scanner;

public class Matrix {
    public int N;
    private int[][] ar;
    private int[][] sorted_rows;
    private int[][] sorted_cols;
    private int[] rowMaxArray;
    private int[] columnMinArray;

    public int rowMax;
    public int columnMin;

    Matrix() {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        ar = new int[N][N];
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                ar[row][col] = in.nextInt();
            }
        }
        rowMaxArray = new int[N];
        columnMinArray = new int[N];
        sortRows();
        sortCols();
        rowMax = find_r_max();
        columnMin = find_C_min();
    }

    static int[] getColumn(int[][] arr, int n) {
        int len = arr.length;
        int[] column = new int[len];
        for (int m = 0; m < len; m++) {
            column[m] = arr[m][n];
        }
        return column;
    }

    private int find_r_max() {
        int max = 1;
        for (int m = 0; m < N; m++) {
            int r = sorted_rows[m][0];
            if (r > max) max = r;
        }
        return max;
    }

    private int find_C_min() {
        int min = Integer.MAX_VALUE;
        for (int n = 0; n < N; n++) {
            int C = sorted_cols[n][N - 1];
            if (C < min) min = C;
        }
        return min;
    }

    private void sortRows() {
        sorted_rows = new int[N][N];
        for (int m = 0; m < N; m++) {
            sorted_rows[m] = Arrays.copyOf(ar[m], N);
            Arrays.sort(sorted_rows[m]);
        }
    }

    private void sortCols() {
        sorted_cols = new int[N][N];
        for (int n = 0; n < N; n++) {
            sorted_cols[n] = getColumn(ar, n);
            Arrays.sort(sorted_cols[n]);
        }
    }

    boolean isSolution(int row_changes, int col_changes) {
        int max_r = rowMax;
        int min_C = columnMin;
        if (row_changes > 0) {
            if (rowMaxArray[row_changes] == 0) {
                for (int row = 0; row < N; row++) {
                    int val;
                    if ((val = sorted_rows[row][row_changes]) > max_r)
                        max_r = val;
                }
                rowMaxArray[row_changes] = max_r;
            } else {
                max_r = rowMaxArray[row_changes];
            }
        }
        if (col_changes > 0) {
            if (columnMinArray[col_changes] == 0) {
                for (int col = 0; col < N; col++) {
                    int val;
                    if ((val = sorted_cols[col][N - 1 - col_changes]) < min_C)
                        min_C = val;
                }
                columnMinArray[col_changes] = min_C;
            } else {
                min_C = columnMinArray[col_changes];
            }
        }
        return max_r >= min_C;
    }
}
