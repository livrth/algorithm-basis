/*
 * @Description: 高精度乘低精度 模板
 * @Author: Xiaobin Ren
 * @Date: 2020-04-02 15:32:11
 * @LastEditTime: 2020-04-02 16:00:42
 */

/*
    乘法的模拟过程和手动不一样，
    直接把较小的数当作一个整体来乘，    
    然后再进位。注意 b 是int，main函数只需要用vector存 A 即可
*/

// C = A * b, A >= 0, b > 0
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;  //到最后一位的时候，就不会中if判断了，直接每次%10加到最后
    }

    return C;
}

//第二种写法 高精度加压位 无返回值 
//如果压9位 1e9就用 long long vector来存结果
void mul(vector<int> & a, int b){
    int t = 0;
    for(int i = 0; i < a.size(); i++){
        a[i]  = a[i] * b + t;
        t = a[i] / 10000;
        a[i] %= 10000;
    }
    while(t){
        a.push_back(t % 10000);
        t /= 10000;
    }
}