//
//  Use this file to import your target's public headers that you would like to expose to Swift.
//



typedef struct result {
    int row_size, col_size;
    // Header is 1D array of strings
    // Grid is a 2D array of ints
    char **header, **grid;
} result;

result *get_result(char expressions[]);
