// 二分图最大匹配
# include <iostream>
# include <cstring>
using namespace std;
bool map[N][M]; //X有N个元素，Y有M个元素，map[i][j]=true 表示元素i到元素j有一条边
int match[M];  //表示元素j的与之匹配的是哪个元素i，一开始要把全部初始化为N，表示和哪个都不匹配 
int chk[N]; //表示元素i在dfs过程中是否被标记过 

int dfs(int p) {
	int i, t;
	for (i = 0; i < M; i++) {
		//如果i还没被标记并且i到p是有边的，令i匹配p，然后递归继续搜索
		if (map[i][p] && !chk[i]) {
			chk[i] = 1;
			t = match[i];
			match[i] = p;
			if (t == N || dfs(t)) {
				return 1;
			}
			match[i] = t;
		} 
	}
	return 0;
} 
int match() {
	int i, res = 0;
	//循环N次，每次确定一个元素被匹配
	for(i = 0; i < N; i++) {
		memset(chk, false, sizeof(chk));
		//深度优先搜索寻找增广路，如果找到，匹配数加1
		if (dfs(i)) {
			res++;
		} 
	} 
	return res; //res是最大匹配数 
}
int main() {
	
	return 0;
} 
