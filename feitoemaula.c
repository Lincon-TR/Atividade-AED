int compara(char lista, int l, int c, char word);
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i, j;

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] == word[0]) {
                if (compara(**board, i, j, *word) == 1)
                    return true;
            }
        }
    }
    return false;
}

int compara(char lista, int l, int c, char word) {
        
        for (int x = 1; x < 10; x++) {
            if (lista[l][c - 1] == word[x] {
                compara(*lista, l, c-1);
                return (1);
            }
            if (lista[l + 1][c] == word[x]) {
                compara(*lista[l + 1][c], l+1, c);
                return (1);
            }
            if (lista[l][c + 1] == word[x]) {
                compara(*lista[i][c+1], l, c+1);
                return (1);
            }
            if (lista[l - 1][c] == word[x]) {
                compara(*lista[l - 1][c], l-1, c);
                return (1);
            }
        }
}

//    (1,1) = (0,1)   (1,0)   (2,1)   (1,2)
//    (i,j) = (i-1,j) (i,j-1) (i+1,j) (i,j+1)