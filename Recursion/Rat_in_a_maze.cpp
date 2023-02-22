class solution{
    private:
    bool isValid(vector<vector<int>> visited, vector<vector<int>>& m, int n, int x, int y){
        if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (m[x][y] == 1)){
            return true;
        }
        else{
            return false;
        }
    } 
    
    
    void solve(vector<vector<int>>& m, int x, int y, int n, vector<vector<int>> visited, vector<string>& ans, string path){
        //Base case.
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        // 4 choices D-L-R-U.
        //Down.
        int newx = x+1;
        int newy = y;
        if(isValid(visited, m, n, newx, newy)){
            path.push_back('D');
            solve(m, newx, newy, n, visited, ans, path);
            path.pop_back();
        }
        //Left.
        newx = x;
        newy = y-1;
        if(isValid(visited, m, n, newx, newy)){
            path.push_back('L');
            solve(m, newx, newy, n, visited, ans, path);
            path.pop_back();
        }
        //Right.
        newx = x;
        newy = y+1;
        if(isValid(visited, m, n, newx, newy)){
            path.push_back('R');
            solve(m, newx, newy, n, visited, ans, path);
            path.pop_back();
        }
        //Up.
        newx = x-1;
        newy = y;
        if(isValid(visited, m, n, newx, newy)){
            path.push_back('U');
            solve(m, newx, newy, n, visited, ans, path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0){
            return ans;
        }
        int srcx = 0;
        int srcy = 0;
        vector<vector<int>> visited = m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(m, srcx, srcy, n, visited, ans, path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

