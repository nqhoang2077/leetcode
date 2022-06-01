(int r = rows - 1; r >= 0; r--)
        {
            for (int c = cols - 1; c >= 0; c--)
            {

                int right = (c < cols - 1) ? mat[r][c + 1] : rows * cols;
                int down = (r < rows - 1) ? mat[r + 1][c] : rows * cols;
                mat[r][c] = min(1 + min(right, down),mat[r][c]);
            }
        }