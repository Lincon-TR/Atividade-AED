bool procura(char** board, int boardSize, int* boardColSize, char* word, int i,
             int j, int x, bool visitado[6][15]) {
    if (word[x] == '\0')
        return true;

    if (i < 0 || j < 0 || i >= boardSize || j >= boardColSize[i] ||
        board[i][j] != word[x] || visitado[i][j]) {
        return false;
    }

    visitado[i][j] = true;

    bool resultado = procura(board, boardSize, boardColSize, word, i - 1, j,
                             x + 1, visitado) ||
                     procura(board, boardSize, boardColSize, word, i, j - 1,
                             x + 1, visitado) ||
                     procura(board, boardSize, boardColSize, word, i + 1, j,
                             x + 1, visitado) ||
                     procura(board, boardSize, boardColSize, word, i, j + 1,
                             x + 1, visitado);
    visitado[i][j] = false;
    return resultado;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i, j;
    bool visitado[6][15] = {{false}};

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (procura(board, boardSize, boardColSize, word, i, j, 0,
                        visitado)) {
                return true;
            }
        }
    }
    return false;
}

//    (1,1) = (0,1)   (1,0)   (2,1)   (1,2)
//    (i,j) = (i-1,j) (i,j-1) (i+1,j) (i,j+1)