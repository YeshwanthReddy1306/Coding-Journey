class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // Check first column
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                firstCol = true;
                break;
            }
        }

        // Check first row
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                firstRow = true;
                break;
            }
        }

        // Mark rows and columns
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeros based on markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // Update first column
        if(firstCol){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }

        // Update first row
        if(firstRow){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};