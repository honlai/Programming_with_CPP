/*輸入一張H×W 的圖像A，每個像素僅黑與白兩種顏色；高度為H，寬度為W。
使用兩個3×3卷積核C1與C2作計算。得出兩個結果 B1與 B2。
對於B1與 B2，計算新影像 D[h][w]=B1[h][w]^2+B2[h][w]^2。
由影像D 計算最終結果 D[h][w]≥8 則E[h][w]=0，反之E[h][w]=1。D 與E 的尺寸皆為(H−2)×(W−2)。*/
#include <iostream>
using namespace std;
int C1[3][3] = {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};
int C2[3][3] = {{-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}};
int image_h = 0, image_w = 0;
int image[100][100] = {0};
int B1[100][100] = {0};
int B2[100][100] = {0};
int D[100][100] = {0};
int result[100][100] = {0};

void set_image();
void convolutional();
void calculate_B1();
void calculate_B2();
void calculate_D();
void calculate_result();
void print_result();

int main()
{
    set_image();
    convolutional();
    print_result();
    return 0;
}
void set_image()
{
    cin >> image_h >> image_w;
    for (int i = 0; i < image_h; ++i)
    {
        for (int j = 0; j < image_w; ++j)
        {
            char tmp = ' ';
            cin >> tmp;
            if (tmp == '-')
            {
                image[i][j] = true;
            }
            if (tmp == '@')
            {
                image[i][j] = false;
            }
        }
    }
    return;
}
void convolutional()
{
    calculate_B1();
    calculate_B2();
    calculate_D();
    calculate_result();
    return;
}
void calculate_B1()
{
    for (int i = 0; i < image_h - 2; ++i)
    {
        for (int j = 0; j < image_w - 2; ++j)
        {
            B1[i][j] = image[i][j] * C1[0][0] + image[i][j + 1] * C1[0][1] + image[i][j + 2] * C1[0][2] + image[i + 1][j] * C1[1][0] + image[i + 1][j + 1] * C1[1][1] + image[i + 1][j + 2] * C1[1][2] + image[i + 2][j] * C1[2][0] + image[i + 2][j + 1] * C1[2][1] + image[i + 2][j + 2] * C1[2][2];
        }
    }
    return;
}
void calculate_B2()
{
    for (int i = 0; i < image_h - 2; ++i)
    {
        for (int j = 0; j < image_w - 2; ++j)
        {
            B2[i][j] = image[i][j] * C2[0][0] + image[i][j + 1] * C2[0][1] + image[i][j + 2] * C2[0][2] + image[i + 1][j] * C2[1][0] + image[i + 1][j + 1] * C2[1][1] + image[i + 1][j + 2] * C2[1][2] + image[i + 2][j] * C2[2][0] + image[i + 2][j + 1] * C2[2][1] + image[i + 2][j + 2] * C2[2][2];
        }
    }
    return;
}
void calculate_D()
{
    for (int i = 0; i < image_h - 2; ++i)
    {
        for (int j = 0; j < image_w - 2; ++j)
        {
            D[i][j] = B1[i][j] * B1[i][j] + B2[i][j] * B2[i][j];
        }
    }
    return;
}
void calculate_result()
{
    for (int i = 0; i < image_h - 2; ++i)
    {
        for (int j = 0; j < image_w - 2; ++j)
        {
            if (D[i][j] >= 8)
            {
                result[i][j] = 0;
            }
            else
            {
                result[i][j] = 1;
            }
        }
    }
    return;
}
void print_result()
{
    cout << image_h - 2 <<' '<< image_w - 2 << endl;
    for (int i = 0; i < image_h - 2; ++i)
    {
        for (int j = 0; j < image_w - 2; ++j)
        {
            if (result[i][j] == 0)
            {
                cout << '@' << flush;
            }
            if (result[i][j] == 1)
            {
                cout << '-' << flush;
            }
        }
        cout << endl;
    }
    return;
}