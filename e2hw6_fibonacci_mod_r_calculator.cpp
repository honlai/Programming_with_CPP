#include <iostream>
using namespace std;
void mul_matrix_mod_r(unsigned long long &arg_a, unsigned long long &arg_b, unsigned long long &arg_c, unsigned long long &arg_r);
void matrix_A_equal_B(unsigned long long &arg_a, unsigned long long &arg_b);
int main()
{
    unsigned long long n = 0;
    cin >> n;
    unsigned long long r = 0;
    cin >> r;
    /* 0 1 fn-1  fn    */
    /* 1 1 fn    fn+1  */
    unsigned long long mat[4] = {0, 1, 1, 1};
    unsigned long long ans[4] = {1, 0, 0, 1};
    unsigned long long tmp[4] = {0};
    for (int i = 64; i > 0 && n; --i)
    {
        if (n & 1)
        {
            mul_matrix_mod_r(ans[0], mat[0], tmp[0], r);
            matrix_A_equal_B(ans[0], tmp[0]);
        }
        n >>= 1;
        mul_matrix_mod_r(mat[0], mat[0], tmp[0], r);
        matrix_A_equal_B(mat[0], tmp[0]);
    }
    cout << ans[1] << endl;
    return 0;
}
void mul_matrix_mod_r(unsigned long long &arg_a, unsigned long long &arg_b, unsigned long long &arg_c, unsigned long long &arg_r)
{
    /* C=A*B */
    *(&arg_c) = ((*(&arg_a) * *(&arg_b)) % arg_r + (*(&arg_a + 1) * *(&arg_b + 2)) % arg_r) % arg_r;
    *(&arg_c + 1) = ((*(&arg_a) * *(&arg_b + 1)) % arg_r + (*(&arg_a + 1) * *(&arg_b + 3)) % arg_r) % arg_r;
    *(&arg_c + 2) = ((*(&arg_a + 2) * *(&arg_b)) % arg_r + (*(&arg_a + 3) * *(&arg_b + 2)) % arg_r) % arg_r;
    *(&arg_c + 3) = ((*(&arg_a + 2) * *(&arg_b + 1)) % arg_r + (*(&arg_a + 3) * *(&arg_b + 3)) % arg_r) % arg_r;
    return;
}
void matrix_A_equal_B(unsigned long long &arg_a, unsigned long long &arg_b)
{
    /* A=B */
    *(&arg_a) = *(&arg_b);
    *(&arg_a + 1) = *(&arg_b + 1);
    *(&arg_a + 2) = *(&arg_b + 2);
    *(&arg_a + 3) = *(&arg_b + 3);
    return;
}