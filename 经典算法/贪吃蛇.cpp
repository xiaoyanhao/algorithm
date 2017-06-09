# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <conio.h>

# define snake_max_length 20
# define snake_head 'H'
# define snake_body 'X'
# define blank_cell ' '
# define snake_food '$'
# define wall_cell '*'

//snake stepping: dy = -1(up),1(down); dx = -1(left),1(right),0(no move)
void snake_move(int, int);
//put a food randomized on a blank cell
void put_money(void);
//out cells of the grid
void output(void);
//outs when gameover
bool gameover(void);
//expand the length of snake when it catches food
void snake_expansion(void);

char map[12][13] = {          //初始状态，直接打表。 
	"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"
};
// 定义蛇的起始坐标和长度 
int snake_x[snake_max_length] = {1, 2, 3, 4, 5};
int snake_y[snake_max_length] = {1, 1, 1, 1, 1};
int snake_length = 5;
char head_next = blank_cell;
int tail_x, tail_y;

int main() {
	int i, j;
	put_money();
	while (!gameover()) {
		if (head_next == snake_food && snake_length < snake_max_length) {
			snake_expansion();
		    put_money();
		}
		system("cls"); // 清屏 
		output();
		if (snake_length == snake_max_length) {
			printf("\nWin The Game! ↖(^ ω ^)↗ \n\n");
		    break;
		}
		char ch;
		    ch = getch();
		switch(ch) {
			case 'w':
				if (snake_y[snake_length - 2] + 1 == snake_y[snake_length - 1])
				    continue;
				snake_move(0, -1);
				break;
			case 's':
				if (snake_y[snake_length - 2] - 1 == snake_y[snake_length - 1])
				    continue;
				snake_move(0, 1);
				break;
			case 'a':
				if (snake_x[snake_length - 2] + 1 == snake_x[snake_length - 1])
				    continue;
				snake_move(-1, 0);
				break;
			case 'd':
				if (snake_x[snake_length - 2] - 1 == snake_x[snake_length - 1])
				    continue;
				snake_move(1, 0);
				break;
		}
	}
	return 0;
}

void output(){
	for (int i = 0; i < 12; i++) {
	    	printf("%s", map[i]);
			printf("\n");
	}
}

void snake_move(int dx, int dy) {
	tail_x = snake_x[0]; // 记录当前蛇尾的坐标 
	tail_y = snake_y[0];
	map[snake_y[0]][snake_x[0]] = blank_cell;
	for (int i = 0; i < snake_length - 1; i++) {
		snake_x[i] = snake_x[i + 1];
		snake_y[i] = snake_y[i + 1];
		map[snake_y[i]][snake_x[i]] = snake_body;
	}
	snake_x[snake_length - 1] += dx;
	snake_y[snake_length - 1] += dy;
	head_next = map[snake_y[snake_length - 1]][snake_x[snake_length - 1]]; // 记录蛇头移动的下一个坐标的内容 
	map[snake_y[snake_length - 1]][snake_x[snake_length - 1]] = snake_head;
}

bool gameover() {
	if (head_next == snake_body || head_next == wall_cell) {
		printf("\nGame Over! ~( 〒_〒 )~ \n\n");
		return 1;
	} else {
		return 0;
	}
}

void put_money() {
	while (1) {
		srand((unsigned int)time(NULL));    // 使每次生成的随机数不同
	    int food_x = rand() % (11 - 1) + 1; // 随机生成[1, 11)的整数 
    	int food_y = rand() % (11 - 1) + 1;
    	if (map[food_y][food_x] != snake_body && map[food_y][food_x] != snake_head) { // 判断食物是否出现在蛇身上，如果是则重新生成食物。 
	        map[food_y][food_x] = snake_food;
	        break;
    	}
	}
}

void snake_expansion() {
	snake_length += 1;
	for (int i = snake_length - 1; i > 0; i--) {
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}
	snake_x[0] = tail_x;
	snake_y[0] = tail_y;
    map[snake_y[0]][snake_x[0]] = snake_body;
}
