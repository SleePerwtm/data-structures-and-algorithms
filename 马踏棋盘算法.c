#include <stdio.h>
#include <string.h>

#define X 8
#define Y 8

int chessboard[X][Y]; // 棋盘

// 记录每个方向的坐标偏移
int offsets[8][2] = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                     {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

/* 判断当前位置是否合法 */
int isValid(int x, int y) {
    // 边界检查
    if (x < 0 || x >= X || y < 0 || y >= Y)
        return 0;
    // 检查是否已经走过
    if (chessboard[x][y] != 0)
        return 0;
    return 1;
}

/* 打印棋盘 */
void printChessboard() {
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            printf("%d\t", chessboard[i][j]);
        }
        printf("\n");
    }
}

int travelToNext(int x, int y, int step) {
    // 在当前位置记录步数
    chessboard[x][y] = step;

    // 如果已经走完所有格子，说明找到了一个解
    if (step == X * Y) {
        return 1;
    }

    // 按照8个方向逐一尝试
    for (int i = 0; i < 8; ++i) {
        // 计算下一步的坐标
        int nextX = x + offsets[i][0];
        int nextY = y + offsets[i][1];

        // 检查下一步是否可行
        if (isValid(nextX, nextY)) {
            // 递归探索下一步
            if (travelToNext(nextX, nextY, step + 1)) {
                return 1;
            }
        }
    }

    // 所有方向都尝试过不行，回溯并重置当前位置
    chessboard[x][y] = 0;
    return 0;
}

int main() {
    // 初始化棋盘
    memset(chessboard, 0, sizeof(chessboard));

    printf("输入起始位置坐标，用空格隔开：\n");
    int x, y;
    scanf("%d %d", &x, &y);

    // 从指定位置开始寻找路径
    int result = travelToNext(x, y, 1);

    // 输出最终结果
    printChessboard();

    return 0;
}